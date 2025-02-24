#pragma once
#include "Potion.h"

class HyperPotion : public Potion {
    public:
        HyperPotion(string desc, int potionCost);
        ~HyperPotion() {}
};