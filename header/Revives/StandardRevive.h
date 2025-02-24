#pragma once
#include "Revive.h"

class StandardRevive : public Revive {
    public:
        StandardRevive(string desc, int reviveCost); 
        ~StandardRevive() {}
};