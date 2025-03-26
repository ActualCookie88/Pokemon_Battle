#pragma once
#include "pokemonType.h"
#include "pokemonSpecies.h"
#include "moves.h"
#include "attack.h"
#include <iostream>
#include <vector>
using namespace std;

class Pokemon {
    private:
        PokemonSpecies species;
        PokemonType type;
        int HP;
        int Attack;
        int Defense;

        //int level;
        //int exp;

        Attack* move;
};