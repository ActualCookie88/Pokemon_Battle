#pragma once
#include "Pokeball.h"
using namespace std;

class GreatBall : public Pokeball {
    public:
        GreatBall(string desc, int ballCost);
        ~GreatBall() {}
};