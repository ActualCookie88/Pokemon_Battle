#pragma once
#include "type.h"
#include "pokemonSpecies.h"
#include "growthRate.h"
#include "moves.h"
#include "attack.h"
#include <iostream>
#include <vector>
using namespace std;

class Pokemon {
    private:
        PokemonSpecies species;
        Type type;
        GrowthRate growthRate;
        int hp;
        int attack;
        int defense;
        int level;
        int exp;
        Attack* move1;
        Attack* move2;
        Attack* move3;

    public:
        Pokemon();
        Pokemon(PokemonSpecies sp);
        ~Pokemon();
        Pokemon& operator=(const Pokemon& other);
        // actions
        void displayInfo();
        void initializeStats(PokemonSpecies sp);
        string speciesToString(PokemonSpecies species);
        string typeToString(Type type);
        int calculateDamage(Attack* move, Pokemon* attacker, Pokemon* defender) const;
        int calculateHP() const;
        int calculateAttack() const;
        int calculateDefense() const;
        int calculateEXP(Pokemon defeatedPokemon) const;
        // getters and setters
        PokemonSpecies getSpecies() const;
        Type getType() const;
        int gethp() const;
        int getAttack() const;
        int getDefense() const;
        int getLevel() const;
        int getEXP() const;
        Attack* getMove1() const;
        Attack* getMove2() const;
        Attack* getMove3() const;
        void addEXP(int val);
        void addLevel();
};