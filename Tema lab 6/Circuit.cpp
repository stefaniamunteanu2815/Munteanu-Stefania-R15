#include "Circuit.h"
#include <iostream>
using namespace std;

Circuit::Circuit() 
{
    this->length = 0;
    this->weather = Weather::Sunny;
    this->carsCount = 0;
}

Circuit::~Circuit() 
{
    for (int i = 0; i < carsCount; i++)
        delete cars[i];
}

void Circuit::SetLength(double l) 
{
    this->length = l;
}

void Circuit::SetWeather(Weather w) 
{
    this->weather = w;
}

void Circuit::AddCar(Car* c) 
{
    if (this->carsCount < 100) 
    {
        this->cars[this->carsCount] = c;
        this->carsCount++;
    }
}

void Circuit::Race() 
{
    for (int i = 0; i < carsCount; i++) 
    {
        double speed = cars[i]->GetSpeed(this->weather);
        double consumptionPer100 = cars[i]->GetFuelConsumption();
        double capacity = cars[i]->GetFuelCapacity();

        double fuelNeeded = (this->length * consumptionPer100) / 100.0;

        results[i].name = cars[i]->GetName();

        if (fuelNeeded <= capacity) 
        {
            results[i].time = this->length / speed;
            results[i].finished = true;
        }
        else 
        {
            results[i].time = 999999.0;
            results[i].finished = false;
        }
    }
    for (int i = 0; i < carsCount - 1; i++)
    {
        for (int j = 0; j < carsCount - i - 1; j++)
        {
            if (results[j].time > results[j + 1].time)
            {
                Result temp = results[j];
                results[j] = results[j + 1];
                results[j + 1] = temp;
            }
        }
    }
}

void Circuit::ShowFinalRanks() 
{
    cout << "CLASAMENT FINAL" << endl;
    int rank = 1;
    for (int i = 0; i < carsCount; i++)
    {
        if (results[i].finished)
        {
            cout << rank++ << ". " << results[i].name << " - Timp: "
                << results[i].time << " ore" << endl;
        }
    }
}

void Circuit::ShowWhoDidNotFinish() 
{
    cout << "MASINI CARE NU AU TERMINAT" << endl;
    bool anyoneDNF = false;
    for (int i = 0; i < carsCount; i++) 
    {
        if (!results[i].finished) 
        {
            cout << "- " << results[i].name << " (Ramas fara combustibil)" << endl;
            anyoneDNF = true;
        }
    }
    if (!anyoneDNF) cout << "Toate masinile au terminat cursa!" << endl;
}