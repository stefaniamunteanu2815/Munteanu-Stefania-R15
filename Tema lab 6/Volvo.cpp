#include "Volvo.h"
Volvo::Volvo()
{
    this->fuelCapacity = 55.0;
    this->fuelConsumption = 12.5;

    this->avgSpeedSunny = 110.0;
    this->avgSpeedRain = 80.0;
    this->avgSpeedSnow = 50.0;
}
double Volvo::GetSpeed(Weather w) const
{
    if (w == Weather::Sunny) return this->avgSpeedSunny;
    if (w == Weather::Rain)  return this->avgSpeedRain;
    if (w == Weather::Snow)  return this->avgSpeedSnow;
    return 0;
}

double Volvo::GetFuelCapacity() const
{
    return this->fuelCapacity;
}

double Volvo::GetFuelConsumption() const
{
    return this->fuelConsumption;
}

const char* Volvo::GetName() const
{
    return "Volvo";
}