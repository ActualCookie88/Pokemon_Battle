#pragma once
#include <string>
#include "moves.h"
#include "pokemonType.h"
class Pokemon;

using std::string;

class Attack {
    private:
        moves name;
        PokemonType type;
        int power;
    public:
        Attack& operator=(const Attack& other) {
            if (this != &other) {
                name = other.name;
                type = other.type;
                power = other.power;
            }
            return *this;
        }
        Attack();
        Attack(moves name);

        string getName() const;//get name of the moves
        int getpower() const;//get the value of power
        int calculateDamage(Pokemon attacker, Pokemon defender) const;//calculates the actual damage to the opponent
        void displayInfo() const;//display name and power
};
