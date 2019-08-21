#pragma once

enum class CarMake
{
	Lambo,
	BMW,
	Smart
};
class Car
{
public:
	virtual int GetMaxSpeed() = 0;
};

class Lambo : public Car
{
public:
	int GetMaxSpeed() override
	{
		return 500;
	}
};

class Smart : public Car
{
public:
	int GetMaxSpeed() override
	{
		return 50;
	}
};

class BMW : public Car
{
public:
	int GetMaxSpeed() override
	{
		return 250;
	}
};

class Factory
{
public:
	static Car* CreateCar(CarMake type)
	{
		Car* car = nullptr;
		switch (type)
		{
		case CarMake::Lambo:
			return new Lambo();
		case CarMake::BMW:
			return new BMW();
		case CarMake::Smart:
			return new Smart();
		}
	}
};