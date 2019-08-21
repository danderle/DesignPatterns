#pragma once

class Singleton
{
private:
	Singleton() = default;
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
	static Singleton *instance;

public:
	static Singleton* GetInstance()
	{
		if (instance == nullptr)
		{
			instance = new Singleton();
		}
		return instance;
	}
	~Singleton()
	{
		delete instance;
		instance = nullptr;
	}
};
Singleton *Singleton::instance = nullptr;

