#pragma once
#include "../Item.h"
using namespace std;

class Revive : public Item {
    protected:
        double restorePercent;

    public:
        enum ReviveType { STANDARD, MAX };
        Revive(string reviveName, string desc, int reviveCost, ReviveType reviveType);
        ~Revive() {}
        
        void useItem() const override;
        void displayInfo() const override;
};