#pragma once
#include <iostream>
#include <sstream>

//Abstract Builder Class
//The derived classes will overwrite the pure virtual functions 
class Builder
{
public:
	Builder() = delete;
	Builder(int wheelSize, int enginePower, int doors, std::string model)
		:
		WheelSize(wheelSize),
		EnginePower(enginePower),
		Doors(doors),
		Model(model)
	{}

	//Returns the wheel size of a car
	virtual int GetWheelSize() = 0;

	//Returns the horsepower of a car
	virtual int GetEnginePower() = 0;

	//Return the number of doors of a car
	virtual int GetDoorNum() = 0;
	virtual std::string GetModel() = 0;

	//Needs to be virtual so inheriting 
	//classes destructors will be called on deletion
	virtual ~Builder() = default;

	//Members are protected so the children can still access them
protected:
	int WheelSize;
	int Doors;
	int EnginePower;
	std::string Model;
};

//Derived builder class for BMW
class BmwBuilder : public Builder
{
public:
	BmwBuilder()
		:Builder(20,250,4,"BMW")
	{}
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


};

//Derived builder class for mazda
class MazdaBuilder : public Builder
{
public:
	MazdaBuilder()
		:Builder(18,200,2,"Mazda")
	{}
	
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
};

//Car class to be build
class Car
{
public:
	//Default constructor deleted
	Car() = delete;
	//Overloaded Constructor with parameters passed in from the derived builder classes
	Car(int wheelSize, int enginePower, int doors, std::string model)
		:
		WheelSize(wheelSize),
		EnginePower(enginePower),
		Doors(doors),
		Model(model)
	{}

	//Prints the build car specifications
	void GetSpecs() const
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
	void SetBuilder(Builder* builder)
	{
		pBuilder = builder;
	}

	//Builds a car with the set builder class and returns a car
	Car* MakeCar()
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

////Example builds 2 different cars and prints their specs
//int main()
//{
//	Director direct;
//	Builder* build = new BmwBuilder();
//	direct.SetBuilder(build);
//	Car* car = direct.MakeCar();
//	car->GetSpecs();
//	delete car;
//	delete build;
//	build = nullptr;
//	car = nullptr;
//
//	build = new MazdaBuilder();
//	direct.SetBuilder(build);
//	car = direct.MakeCar();
//	car->GetSpecs();
//	delete car;
//	delete build;
//	build = nullptr;
//	car = nullptr;
//
//	return 0;
//}


