#pragma once
#include <memory>
#include <stack>
#include <iostream>

//Abstract state class
class State
{
public:
	//will print the current activated state
	virtual void PrintState() const = 0;

	//Needs to be virtual so inheriting 
	//classes destructors will be called on deletion
	virtual ~State() = default;
};

typedef std::unique_ptr<State> StatePointer;

//class to add and remove states and keep track of the state stack
class StateMachine
{
public:
	StateMachine() = default;
	~StateMachine() = default;

	//Adds states to the stack or replaces current state
	void AddState(StatePointer newState, bool isReplacing = true)
	{
		bIsAdding = true;
		bIsReplacing = isReplacing;

		mNewState = std::move(newState);
		ProcessStateChanges();
	}

	//Removes the top state
	void RemoveState()
	{
		bIsRemoving = true;
		ProcessStateChanges();
	}

	//returns the current state
	StatePointer& GetActiveState()
	{
		return stackStates.top();
	}

private:
	//Proccesses the changes after adding or removing states
	void ProcessStateChanges()
	{
		if (bIsRemoving && !stackStates.empty())
		{
			stackStates.pop();
			bIsRemoving = false;
		}
		if (bIsAdding)
		{
			if (!stackStates.empty())
				if (bIsReplacing)
					stackStates.pop();
			stackStates.push(std::move(mNewState));
			bIsAdding = false;
		}
	}

	std::stack<StatePointer> stackStates;
	StatePointer mNewState;
	bool bIsRemoving;
	bool bIsAdding;
	bool bIsReplacing;
};

//Game state class
class GameState : public State
{
	void PrintState() const override
	{
		std::cout << "Playing Game\n";
	}
};

//Game over state class
class GameOverState : public State
{
	void PrintState() const override
	{
		std::cout << "Game Over\n";
	}
};

//Main menu state class
class MainMenuState : public State
{
	void PrintState() const override
	{
		std::cout << "Main Menu\n";
	}
};

//In Game Menu state class
class GameMenuState : public State
{
	void PrintState() const override
	{
		std::cout << "In Game Menu\n";
	}
};

//
////Example of using the State pattern
//int main()
//{
//	StateMachine machine;
//	machine.AddState((StatePointer)new MainMenuState());
//	machine.GetActiveState()->PrintState();
//	machine.AddState((StatePointer)new GameState());
//	machine.GetActiveState()->PrintState();
//	machine.AddState((StatePointer)new GameMenuState(), false);
//	machine.GetActiveState()->PrintState();
//	machine.RemoveState();
//	machine.GetActiveState()->PrintState();
//	machine.AddState((StatePointer)new GameOverState());
//	machine.GetActiveState()->PrintState();
//
//	return 0;
//}