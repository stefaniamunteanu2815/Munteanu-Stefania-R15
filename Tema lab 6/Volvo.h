#pragma once
#include "Car.h"
class Volvo : public Car 
{
public:
	Volvo();
	double GetSpeed(Weather w) const override;
	double GetFuelCapacity() const override;
	double GetFuelConsumption() const override;
	const char* GetName() const override;
};