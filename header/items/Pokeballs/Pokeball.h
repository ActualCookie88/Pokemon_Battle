#pragma once
#include "../Item.h"
using namespace std;

class Pokeball : public Item {
    private:
        double multiplier;
        
    public:
        enum BallType { STANDARD, GREAT, ULTRA, MASTER };
        Pokeball();
        Pokeball(string ballName, string desc, int ballCost, BallType ballType);
        virtual ~Pokeball() { }
        
        void useItem() override;
        void displayInfo() const override;
        void displayInfo2() const override;

        double getMultiplier() const;
};