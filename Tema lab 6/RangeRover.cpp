#include "RangeRover.h"
RangeRover::RangeRover()
{
    this->fuelCapacity = 70.0;
    this->fuelConsumption = 10.5;

    this->avgSpeedSunny = 150.0;
    this->avgSpeedRain = 100.0;
    this->avgSpeedSnow = 90.0;
}
double RangeRover::GetSpeed(Weather w) const
{
    if (w == Weather::Sunny) return this->avgSpeedSunny;
    if (w == Weather::Rain)  return this->avgSpeedRain;
    if (w == Weather::Snow)  return this->avgSpeedSnow;
    return 0;
}

double RangeRover::GetFuelCapacity() const
{
    return this->fuelCapacity;
}

double RangeRover::GetFuelConsumption() const
{
    return this->fuelConsumption;
}

const char* RangeRover::GetName() const
{
    return "Range Rover";
}