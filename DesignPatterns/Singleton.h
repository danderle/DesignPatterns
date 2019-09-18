#pragma once
//Singleton Class
//make sure that only 1 exists
class Singleton
{
public:
	//Creates a single instance if not yet created
	static Singleton* GetInstance()
	{
		if (instance == nullptr)
		{
			instance = new Singleton();
		}
		return instance;
	}

	//Default destructor
	~Singleton()
	{
		delete instance;
		instance = nullptr;
	}

private:
	//Default constructor
	Singleton() = default;

	//Delete the copy constructor
	Singleton(const Singleton&) = delete;

	//Delete the copy assignment operator
	Singleton& operator=(const Singleton&) = delete;

	//Private static Singleton instance
	static Singleton *instance;

};
//Set default instance to Null
Singleton *Singleton::instance = nullptr;

//Singleton usage example
int main()
{
	//Now the singleton can be used
	Singleton* myInstance = Singleton::GetInstance();

	return 0;
}

