#pragma once
#include <string>
#include "../Item.h"

using namespace std;

class Revive : public Item
{
    protected:
        double reviveMultiplyer;

    public:
        Revive(string n, int p, string desc, double rMultiplyer);
        void displayInformation() override;
        double getReviveMultiplyer();
};