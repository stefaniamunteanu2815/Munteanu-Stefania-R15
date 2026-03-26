#pragma once
#include "Car.h"
class RangeRover : public Car
{
public:
    RangeRover();
    double GetSpeed(Weather w) const override;
    double GetFuelCapacity() const override;
    double GetFuelConsumption() const override;
    const char* GetName() const override;
};