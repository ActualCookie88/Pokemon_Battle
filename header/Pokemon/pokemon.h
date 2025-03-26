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
        int hp;
        int attack;
        int defense;
        int level;
        //int exp;
        Attack* move1;
        Attack* move2;
        Attack* move3;

    public:
        Pokemon();
        Pokemon(PokemonSpecies sp);
        ~Pokemon() {
            delete move1;
            delete move2;
            delete move3;
        }
        Pokemon& operator=(const Pokemon& other);
        // actions
        void displayInfo();
        void initializeStats(PokemonSpecies sp);
        string speciesToString(PokemonSpecies species);
        string typeToString(PokemonType type);
        int calculateDamage(Attack* move, Pokemon* attacker, Pokemon* defender) const;
        int calculateHP() const;
        int calculateAttack() const;
        int calculateDefense() const;
        // int calculateEXP(Pokemon defeatedPokemon) const;
        bool isTypeEffective(Pokemon* defender);
        bool isTypeNotEffective(Pokemon* defender);
        // getters and setters
        PokemonSpecies getSpecies() const;
        PokemonType getType() const;
        int gethp();
        int getAttack();
        int getDefense();
        int getLevel() const;
        Attack* getMove1() const;
        Attack* getMove2() const;
        Attack* getMove3() const;
};