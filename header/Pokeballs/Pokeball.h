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

        bool isPokemonCaught(double baseChance) const;
        void printIfPokemonCaught(double baseCatchChance) const;
        
        void useItem() const override;
        void displayInfo() const override;

        double getMultiplier() const;
};