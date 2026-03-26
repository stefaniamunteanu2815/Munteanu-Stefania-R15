#include "BMW.h"
BMW::BMW()
{
	this->fuelCapacity = 65.0;
	this->fuelConsumption = 11.5;

	this->avgSpeedSunny = 120.0;
	this->avgSpeedRain = 80.0;
	this->avgSpeedSnow = 60.0;
}
double BMW::GetSpeed(Weather w) const 
{
    if (w == Weather::Sunny) return this->avgSpeedSunny;
    if (w == Weather::Rain)  return this->avgSpeedRain;
    if (w == Weather::Snow)  return this->avgSpeedSnow;
    return 0;
}

double BMW::GetFuelCapacity() const 
{
    return this->fuelCapacity;
}

double BMW::GetFuelConsumption() const 
{
    return this->fuelConsumption;
}

const char* BMW::GetName() const 
{
    return "BMW";
}