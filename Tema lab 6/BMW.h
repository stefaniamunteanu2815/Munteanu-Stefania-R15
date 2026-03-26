#pragma once
#include "Car.h"
class BMW : public Car
{
public:
    BMW();
    double GetSpeed(Weather w) const override;
    double GetFuelCapacity() const override;
    double GetFuelConsumption() const override;
    const char* GetName() const override;
};