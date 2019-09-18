#pragma once
#include <iostream>
#include  <vector>

class Subject
{
public:
	void Attach(Observer* obs)
	{
		views.push_back(obs);
	}
	void SetValue(const int value)
	{
		mValue = value;
		Notify();
	}
	int GetValue() const
	{
		return mValue;
	}
	void Notify() const
	{
		for (auto view : views)
			view->Update();
	}
private:
	std::vector<Observer*> views;
	int mValue;
};

class Observer
{
public:
	Observer() = delete;
	Observer(Subject* sub)
	{
		pSubject = sub;
		pSubject->Attach(this);
	}
	~Observer() = default;

	virtual void Update() = 0;

protected:
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




















