#pragma once
#include <string>
#include "../Item.h"

using namespace std;

class Potion : public Item
{
    protected:
        int recoveryValue;

    public:
        Potion(string n, int p, string desc, int rValue);
        void displayInformation() override;
        int getRecoveryValue();
};