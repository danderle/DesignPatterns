#include <iostream>
#include "Singleton.h"
#include "Factory.h"
int main()
{
	Car* a = Factory::CreateCar(CarMake::BMW);
	Car* c = Factory::CreateCar(CarMake::Smart);
	Car* b = Factory::CreateCar(CarMake::Lambo);

	int speed = a->GetMaxSpeed();
	speed = b->GetMaxSpeed();
	speed = c->GetMaxSpeed();

	return 0;
}