#pragma once
#include <iostream>
#include <sstream>

class Car
{
public:
	Car() = delete;
	Car(int wheelSize, int enginePower, int doors, std::string& model)
		:
		WheelSize(wheelSize),
		EnginePower(enginePower),
		Doors(doors),
		Model(model)
	{}

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
class Builder
{
public:
	virtual int GetWheelSize() = 0;
	virtual int GetEnginePower() = 0;
	virtual int GetDoorNum() = 0;
	virtual std::string GetModel() = 0;
};

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

class Director
{
public:
	void Director::SetBuilder(Builder* builder)
	{
		pBuilder = builder;
	}

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
	delete car;
	delete build;
	build = nullptr;
	car = nullptr;

	return 0;
}


