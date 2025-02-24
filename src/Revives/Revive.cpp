#include "../../header/Revives/Revive.h"

Revive::Revive(string n, int p, string desc, double rMultiplyer) 
{
    name = n;
    price = p;
    description = desc;
    reviveMultiplyer = rMultiplyer;
}

void Revive::displayInformation()
{
    cout << "Name: " << name << endl;
    cout << "    Description: " << description << endl;
    cout << "    Revive Multiplyer: " << reviveMultiplyer << "x" << endl;
    cout << "    Price: " << price << "¥" << endl;
} 

double Revive::getReviveMultiplyer()
{
    return reviveMultiplyer;
}