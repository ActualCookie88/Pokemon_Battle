#pragma once
#include "Pokeball.h"
using namespace std;

class StandardBall : public Pokeball {
    public:
        StandardBall(string desc, int ballCost); 
        ~StandardBall() {}
};