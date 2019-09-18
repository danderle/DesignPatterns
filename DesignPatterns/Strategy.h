#pragma once
#include <memory>

class Mood
{
public:
	virtual ~Mood() = default;
	virtual void MyMood() = 0;
};

class Sad : public Mood
{
public:
	virtual void MyMood() override;
};

class Happy : public Mood
{
public:
	virtual void MyMood() override;
};

class Stressed : public Mood
{
public:
	virtual void MyMood() override;
};

class Human
{
public:
	Human() = default;
	~Human();
	void setMyMood(std::shared_ptr<Mood> mood);
	void printMood() const;
private:
	std::shared_ptr<Mood> pMyMood;
};

#include "Strategy.h"
#include <iostream>



void Sad::MyMood()
{
	std::cout << "I am sad\n";
}

void Happy::MyMood()
{
	std::cout << "I am happy\n";
}

void Stressed::MyMood()
{
	std::cout << "I am stressed\n";
}

void Human::setMyMood(std::shared_ptr<Mood> mood)
{
	pMyMood = mood;
}

void Human::printMood() const
{
	pMyMood->MyMood();
}

Human::~Human()
{
}