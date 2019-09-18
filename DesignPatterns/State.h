#pragma once
#include <memory>
#include <stack>
#include <iostream>

class State
{
public:
	virtual void PrintState() = 0;
};

typedef std::unique_ptr<State> StatePointer;

class StateMachine
{
public:
	StateMachine() = default;
	~StateMachine() = default;

	void AddState(StatePointer newState, bool isReplacing = true);
	void RemoveState();
	void ProcessStateChanges();
	StatePointer& GetActiveState();

private:
	std::stack<StatePointer> stackStates;
	StatePointer mNewState;
	bool bIsRemoving;
	bool bIsAdding;
	bool bIsReplacing;
};

class GameState : public State
{
	void PrintState();
};

class GameOverState : public State
{
	void PrintState();
};

class MainMenuState : public State
{
	void PrintState();
};

class GameMenuState : public State
{
	void PrintState();
};


void StateMachine::AddState(StatePointer newState, bool isReplacing)
{
	bIsAdding = true;
	bIsReplacing = isReplacing;

	mNewState = std::move(newState);
}

void StateMachine::RemoveState()
{
	bIsRemoving = true;
}

void StateMachine::ProcessStateChanges()
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

StatePointer& StateMachine::GetActiveState()
{
	return stackStates.top();
}

void GameState::PrintState()
{
	std::cout << "Playing Game\n";
}

void MainMenuState::PrintState()
{
	std::cout << "Main Menu\n";
}

void GameOverState::PrintState()
{
	std::cout << "Game Over\n";
}

void GameMenuState::PrintState()
{
	std::cout << "In Game Menu\n";
}