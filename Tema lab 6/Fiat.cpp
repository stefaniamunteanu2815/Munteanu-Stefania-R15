#include "Fiat.h"
Fiat::Fiat()
{
    this->fuelCapacity = 50.0;
    this->fuelConsumption = 13.0;

    this->avgSpeedSunny = 110.0;
    this->avgSpeedRain = 75.0;
    this->avgSpeedSnow = 65.0;
}
double Fiat::GetSpeed(Weather w) const
{
    if (w == Weather::Sunny) return this->avgSpeedSunny;
    if (w == Weather::Rain)  return this->avgSpeedRain;
    if (w == Weather::Snow)  return this->avgSpeedSnow;
    return 0;
}

double Fiat::GetFuelCapacity() const
{
    return this->fuelCapacity;
}

double Fiat::GetFuelConsumption() const
{
    return this->fuelConsumption;
}

const char* Fiat::GetName() const
{
    return "Fiat";
}