#pragma once
#include "pokemonType.h"
#include "pokemonSpecies.h"
#include "growthRate.h"
#include "moves.h"
#include "attack.h"
#include <cstdlib>
#include <ctime>
#include <map> 
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Pokemon
{
    private:
        PokemonSpecies species;
        PokemonType type;
        GrowthRate GR;
        int level;
        int exp;
        int baseEXP;
        int baseHP;
        int IV;
        int baseAttack;
        int baseDefense;
        Attack* move1;
        Attack* move2;
        Attack* move3;
    public:
        ~Pokemon(){
            delete move1;
            delete move2;
            delete move3;
        }
        Pokemon(PokemonSpecies sp);
        Pokemon(PokemonSpecies sp, int lvl, int EXP, int iv, moves m1, moves m2, moves m3);
        Pokemon(){//default constructor
            species=PokemonSpecies::none;
            type = PokemonType::Normal;
            baseHP=100;
            baseAttack=50;
            baseDefense=30;
            move1=nullptr;
            move2=nullptr;
            move3=nullptr;
        }

        Pokemon& operator=(const Pokemon& other){
            if (this == &other) {
                return *this;
            }

            // Clean up dynamically allocated memory
            delete move1;
            delete move2;
            delete move3;

            // Copy all members from the other object
            species = other.species;
            type = other.type;
            GR = other.GR;
            level = other.level;
            exp = other.exp;
            baseEXP = other.baseEXP;
            baseHP = other.baseHP;
            IV = other.IV;
            baseAttack = other.baseAttack;
            baseDefense = other.baseDefense;

            // Deep copy of dynamically allocated memory
            move1 = other.move1 ? new Attack(*other.move1) : nullptr;
            move2 = other.move2 ? new Attack(*other.move2) : nullptr;
            move3 = other.move3 ? new Attack(*other.move3) : nullptr;

            return *this;
        }
        void displayInfo();//displays every attributes for each pokemon

        int calculateHP() const;//calculates HP as the level goes up
        int calculateAttack() const;//calculates Attack as the level goes up
        int calculateDefense() const;//calculates Defense as the leve goes up
        int calculateEXP(Pokemon defeatedPokemon) const;
        
        void initializeStats(PokemonSpecies sp);

        static string speciesToString(PokemonSpecies species);
        static string typeToString(PokemonType type);

        bool isTypeEffective(Pokemon defender);
        bool isTypeNotEffective(Pokemon defender);
        
        void addEXP(int val);
        void addLevel();
        int getLevel() const;

        void setBaseHP(int val);
        void setBaseAttack(int val);
        void setBaseDefense(int val);
        
        int getBaseHP();
        int getBaseAttack();
        int getBaseDefense();

        Attack* getMove1() const;
        Attack* getMove2() const;
        Attack* getMove3() const;

        PokemonSpecies getSpecies() const {
            return species;
        }

        int getEXP() const {
            return exp;
        }
        int getIV() const {
            return IV;
        }

};

