#pragma once
#include <iostream>
#include <memory>

//Abstract mood class
class Mood
{
public:
	//Derived mood classes will override this
	virtual void MyMood() const = 0;

	//Needs to be virtual so inheriting 
	//classes destructors will be called on deletion
	virtual ~Mood() = default;
};

typedef std::shared_ptr<Mood> moodPtr;

//Derived sad class
class Sad : public Mood
{
public:
	//prints the sad mood
	void MyMood() const override
	{
		std::cout << "I am sad\n";
	}
};

//Derived happy class
class Happy : public Mood
{
public:
	//prints the happy mood
	void MyMood() const override
	{
		std::cout << "I am happy\n";
	}

};

//Derived stressed class
class Stressed : public Mood
{
public:
	void MyMood() const override
	{
		std::cout << "I am stressed\n";
	}
};

//Human class
class Human
{
public:
	//Sets the mood of the human
	void setMyMood(std::shared_ptr<Mood> mood)
	{
		pMyMood = mood;
	}

	//Prints the current mood
	void printMood() const
	{
		pMyMood->MyMood();
	}

private:
	std::shared_ptr<Mood> pMyMood;
};

//
////Example of the strategy pattern
//int main()
//{
//	Human h1;
//	Human h2;
//
//	Mood* mood = new Happy();
//	h1.setMyMood((moodPtr)mood);
//	h2.setMyMood((moodPtr)mood);
//	h1.printMood();
//	h2.printMood();
//
//	mood = new Stressed();
//	h2.setMyMood((moodPtr)mood);
//	h2.printMood();
//
//	return 0;
//}