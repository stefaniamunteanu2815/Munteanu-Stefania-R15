#pragma once
#include "Car.h"
class Seat : public Car
{
public:
	Seat();
    double GetSpeed(Weather w) const override;
    double GetFuelCapacity() const override;
    double GetFuelConsumption() const override;
    const char* GetName() const override;
};