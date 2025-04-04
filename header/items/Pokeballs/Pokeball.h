#pragma once
#include "../Item.h"
#include "../../battle.h"
using namespace std;

class Pokeball : public Item {
    private:
        double multiplier;
        
    public:
        enum BallType { STANDARD, GREAT, ULTRA, MASTER };
        Pokeball();
        Pokeball(string ballName, string desc, int ballCost, BallType ballType);
        virtual ~Pokeball() { }

        void catchPokemon(Battle* battle, int baseCatchChance) const;
        
        void useItem() override;
        void displayInfo() const override;

        double getMultiplier() const;
};