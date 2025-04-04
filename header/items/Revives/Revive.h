#pragma once
#include "../Item.h"
using namespace std;

class Revive : public Item {
    protected:
        double restorePercent;

    public:
        enum ReviveType { STANDARD, MAX };
        Revive(string reviveName, string desc, int reviveCost, ReviveType reviveType);
        virtual ~Revive() {}
        
        void useItem() override;
        void displayInfo() const override;
};