#pragma once
#include <iostream>
#include <sstream>

//Abstract Builder Class
//The derived classes will overwrite the pure virtual functions 
class Builder
{
public:
	//Returns the wheel size of a car
	virtual int GetWheelSize() = 0;

	//Returns the horsepower of a car
	virtual int GetEnginePower() = 0;

	//Return the number of doors of a car
	virtual int GetDoorNum() = 0;
	virtual std::string GetModel() = 0;
};

//Derived builder class for BMW
class BmwBuilder : public Builder
{
public:
	BmwBuilder() = default;
	int GetWheelSize() override
	{
		return WheelSize;
	}
	int GetEnginePower() override
	{
		return EnginePower;
	} 
	int GetDoorNum() override
	{
		return Doors;
	}
	std::string GetModel() override
	{
		return Model;
	}

private:
	const int WheelSize = 20;
	const int Doors = 4;
	const int EnginePower = 250;
	const std::string Model = "BMW";
};

//Derived builder class for mazda
class MazdaBuilder : public Builder
{
public:
	MazdaBuilder() = default;
	
	int GetWheelSize() override
	{
		return WheelSize;
	}
	int GetEnginePower() override
	{
		return EnginePower;
	}
	int GetDoorNum() override
	{
		return Doors;
	}
	std::string GetModel() override
	{
		return Model;
	}
private:
	const int WheelSize = 18;
	const int Doors = 2;
	const int EnginePower = 200;
	const std::string Model = "Mazda";
};

//Car class to be build
class Car
{
public:
	//Default constructor deleted
	Car() = delete;
	//Overloaded Constructor with parameters passed in from the derived builder classes
	Car(int wheelSize, int enginePower, int doors, std::string& model)
		:
		WheelSize(wheelSize),
		EnginePower(enginePower),
		Doors(doors),
		Model(model)
	{}

	//Prints the build car specifications
	void Car::GetSpecs() const
	{
		std::stringstream ss;
		ss << "Model: " << Model << "\n";
		ss << "Wheelsize: " << WheelSize << "\n";
		ss << "Horsepower: " << EnginePower << "\n";
		ss << "Doors: " << Doors << "\n";

		std::cout << ss.str() << std::endl;
	}
private:
	int WheelSize;
	int EnginePower;
	int Doors;
	std::string Model;
};

//Director class
//Sets a builder and builds a car
class Director
{
public:
	//Sets one of the derived builder classes
	void Director::SetBuilder(Builder* builder)
	{
		pBuilder = builder;
	}

	//Builds a car with the set builder class and returns a car
	Car* Director::MakeCar()
	{
		Car* car = new Car(
			pBuilder->GetWheelSize(),
			pBuilder->GetEnginePower(),
			pBuilder->GetDoorNum(),
			pBuilder->GetModel()
			);

		return car;
	}

private:
	Builder* pBuilder;
};

//Example builds 2 different cars and prints their specs
int main()
{
	Director direct;
	Builder* build = new BmwBuilder();
	direct.SetBuilder(build);
	Car* car = direct.MakeCar();
	car->GetSpecs();
	delete car;
	delete build;
	build = nullptr;
	car = nullptr;

	build = new MazdaBuilder();
	direct.SetBuilder(build);
	car = direct.MakeCar();
	car->GetSpecs();
	delete car;
	delete build;
	build = nullptr;
	car = nullptr;

	return 0;
}


