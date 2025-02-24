#pragma once
#include "Potion.h"

class StandardPotion : public Potion {
    public:
        StandardPotion(string desc, int potionCost); 
        ~StandardPotion() {}
};