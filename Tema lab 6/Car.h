#pragma once
#include "Weather.h"
class Car 
{
public:
    double fuelCapacity;
    double fuelConsumption;
    double avgSpeedRain;
    double avgSpeedSunny;
    double avgSpeedSnow;

    virtual ~Car() {}

    virtual double GetSpeed(Weather w) const = 0;
    virtual double GetFuelCapacity() const = 0;
    virtual double GetFuelConsumption() const = 0;
    virtual const char* GetName() const = 0;
};