#pragma once
#include "../Item.h"
using namespace std;

class Potion : public Item {
    protected:
    int healingAmount;

    public:
        enum PotionType { STANDARD, SUPER, HYPER };

        Potion(string potionName, string desc, int potionCost, PotionType potionType);
        virtual ~Potion() {}

        void useItem() override;
        void displayInfo() const override;
};