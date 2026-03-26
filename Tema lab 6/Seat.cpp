#include "Seat.h"
Seat::Seat()
{
    this->fuelCapacity = 50.0;
    this->fuelConsumption = 15.0;

    this->avgSpeedSunny = 120.0;
    this->avgSpeedRain = 100.0;
    this->avgSpeedSnow = 60.0;
}
double Seat::GetSpeed(Weather w) const
{
    if (w == Weather::Sunny) return this->avgSpeedSunny;
    if (w == Weather::Rain)  return this->avgSpeedRain;
    if (w == Weather::Snow)  return this->avgSpeedSnow;
    return 0;
}

double Seat::GetFuelCapacity() const
{
    return this->fuelCapacity;
}

double Seat::GetFuelConsumption() const
{
    return this->fuelConsumption;
}

const char* Seat::GetName() const
{
    return "Seat";
}