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
        Attack();
        Attack(moves name);
        Attack& operator=(const Attack& other);

        string getName() const;
        int getPower() const;
};
