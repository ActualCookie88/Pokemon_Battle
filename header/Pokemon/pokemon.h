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
        int baseHP;
        int baseAttack;
        int baseDefense;
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
        Pokemon(PokemonSpecies sp, int lvl, int exp, Moves m1, Moves m2, Moves m3);
        ~Pokemon();
        Pokemon& operator=(const Pokemon& other);
        // actions
        vector<Moves> generateRandomMoves(Type pokemonType);
        void displayInfo();
        void initializeStats(PokemonSpecies sp);
        int calculateDamage(Attack* move, Pokemon* attacker, Pokemon* defender) const;
        int calculateHP() const;
        int calculateAttack() const;
        int calculateDefense() const;
        int calculateEXP(const Pokemon& defeatedPokemon) const;
        // converters
        string speciesToString(PokemonSpecies species);
        string typeToString(Type type);
        PokemonSpecies stringToSpecies(string& sp);
        Moves stringToMove(const string& move);
        // getters
        PokemonSpecies getSpecies() const;
        Type getType() const;
        int getBaseHP() const;
        int getBaseAttack() const;
        int getBaseDefense() const;
        int getHP() const;
        int getAttack() const;
        int getDefense() const;
        int getLevel() const;
        int getEXP() const;
        Attack* getMove1() const;
        Attack* getMove2() const;
        Attack* getMove3() const;
        // setters
        void setSpecies(PokemonSpecies newSpecies);
        void setBaseHP(int val);
        void setBaseAttack(int val);
        void setBaseDefense(int val);
        void setLevel(int val);
        void addEXP(int val);
        void setMove1(Attack* newMove);
        void setMove2(Attack* newMove);
        void setMove3(Attack* newMove);
        void addLevel();
};