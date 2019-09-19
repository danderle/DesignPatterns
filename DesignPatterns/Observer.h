#pragma once
#include <iostream>
#include  <vector>

//Subject class
//it stores all the observers and notifys them if the value has changed
class Subject
{
public:
	//Stores an observer in a vector
	void Attach(class Observer* obs)
	{
		views.push_back(obs);
	}

	//Sets a new value and notifies the observers
	void SetValue(const int value)
	{
		mValue = value;
		Notify();
	}

	//return a the current value
	int GetValue() const
	{
		return mValue;
	}

	//Cycles the vector with the saved observers
	void Notify() const
	{
		for (auto view : views)
			view->Update();
	}

private:
	std::vector<Observer*> views;
	int mValue;
};

//Abstract observer class
//Uses the subject class a private member to store all the instantiated derived observer objects
class Observer
{
public:
	//Deleted default constructor
	Observer() = delete;

	//Overloaded constructor takes a subject pointer as parameter
	Observer(Subject* sub)
	{
		pSubject = sub;
		pSubject->Attach(this);
	}

	//Default destrcutor
	~Observer() = default;

	//Will check the current value and then respond accordingly
	virtual void Update() = 0;

protected:
	//Returns the subject the observer is watching
	Subject* GetSubject() const
	{
		return pSubject;
	}

private:
	Subject *pSubject;
};

class OddObserver : public Observer
{
public:
	OddObserver() = delete;
	OddObserver(Subject* sub)
		:
		Observer(sub)
	{}
	void Update() override
	{
		int num = GetSubject()->GetValue();
		if (num % 2)
			std::cout << "OddObserver: " << num << " is not an odd number\n";
		else
			std::cout << "OddObserver: " << num << " is an odd number\n";
	}
};

class EvenObserver : public Observer
{
public:
	EvenObserver() = delete;
	EvenObserver(Subject* sub)
		:
		Observer(sub)
	{}
	void Update() override
	{
		int num = GetSubject()->GetValue();
		if (num % 2)
			std::cout << "EvenObserver: " << num << " is an even number\n";
		else
			std::cout << "EvenObserver: " << num << " is not an even number\n";
	}
};




















