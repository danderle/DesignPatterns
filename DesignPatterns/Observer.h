#pragma once
#include <iostream>
#include  <vector>

//Forward declaration
class Observer;

//Subject class
//it stores all the observers and notifys them if the value has changed
class Subject
{
public:
	Subject() = default;

	//Stores an observer in a vector
	void Attach(Observer* obs)
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
	//defined at the bottom because derived obeservers have not been defined
	void Notify() const;
	

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

//OddObserver class
class OddObserver : public Observer
{
public:
	OddObserver() = delete;
	OddObserver(Subject* sub)
		:
		Observer(sub)
	{}

	//oddObserver update function responds to the subject change
	void Update() override
	{
		int num = GetSubject()->GetValue();
		if (num % 2)
			std::cout << "OddObserver: " << num << " is not an odd number\n";
		else
			std::cout << "OddObserver: " << num << " is an odd number\n";
	}
};

//EvenObserver class
class EvenObserver : public Observer
{
public:
	EvenObserver() = delete;
	EvenObserver(Subject* sub)
		:
		Observer(sub)
	{}

	//oddObserver update function responds to the subject change
	void Update() override
	{
		int num = GetSubject()->GetValue();
		if (num % 2)
			std::cout << "EvenObserver: " << num << " is an even number\n";
		else
			std::cout << "EvenObserver: " << num << " is not an even number\n";
	}
};

//Must be defined here
void Subject::Notify() const
{
	for (auto view : views)
		view->Update();
}


////Example of use
//int main()
//{
//	Subject* sub = new Subject();
//	Observer* ob1 = new OddObserver(sub);
//	Observer* ob2 = new EvenObserver(sub);
//
//	sub->SetValue(2);
//	sub->SetValue(11);
//
//	return 0;
//}















