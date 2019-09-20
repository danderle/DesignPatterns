#pragma once
//Enum for the possible car types
enum class CarMake
{
	Acura,
	BMW,
	Honda
};

//Abstract car class for all types of cars
class Car
{
public:
	//The max speed function which every car has, needs to be overriden
	//since it is different for every car
	virtual int GetMaxSpeed() = 0;
};

class Acura: public Car
{
public:
	int GetMaxSpeed() override
	{
		return 150;
	}
};

class Honda: public Car
{
public:
	int GetMaxSpeed() override
	{
		return 100;
	}
};

class BMW : public Car
{
public:
	int GetMaxSpeed() override
	{
		return 200;
	}
};

//The Car Factory which produces whatever cartype is passed into it
class Factory
{
public:
	static Car* CreateCar(CarMake type)
	{
		Car* car = nullptr;
		switch (type)
		{
		case CarMake::Acura:
			return new Acura();
		case CarMake::BMW:
			return new BMW();
		case CarMake::Honda:
			return new Honda();
		}
	}
};

////Example how the factory is used
//int main()
//{
//	Car* a = Factory::CreateCar(CarMake::BMW);
//	Car* c = Factory::CreateCar(CarMake::Honda);
//	Car* b = Factory::CreateCar(CarMake::Acura);
//
//	int speed;
//	speed = a->GetMaxSpeed();
//	speed = b->GetMaxSpeed();
//	speed = c->GetMaxSpeed();
//
//	delete a;
//	delete b;
//	delete c;
//
//	return 0;
//}