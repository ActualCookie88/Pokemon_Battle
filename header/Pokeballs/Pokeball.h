#pragma once
#include "../Item.h"
using namespace std;

class Pokeball : public Item {
    private:
        double multiplier;
        
    public:
        enum BallType { STANDARD, GREAT, ULTRA, MASTER };

        Pokeball(string ballName, string desc, int ballCost, BallType ballType);
        virtual ~Pokeball() {}
        virtual bool catchPokemon(double baseChance);
        
        void useItem() const override;
        void displayInfo() const override;
};