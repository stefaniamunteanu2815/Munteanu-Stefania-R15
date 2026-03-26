#pragma once
#include "Car.h"
class Fiat : public Car
{
public:
    Fiat();
    double GetSpeed(Weather w) const override;
    double GetFuelCapacity() const override;
    double GetFuelConsumption() const override;
    const char* GetName() const override;
};