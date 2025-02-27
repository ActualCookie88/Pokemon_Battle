#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <limits>
#include "Inventory.h"
#include "Pokemon/pokemon.h"
#include "battle.h"
#include "Display.h"

using namespace std;

class Player {
   private:
       int money;
       bool isEnded;
       vector<Pokemon*> caughtPokemons = {new Pokemon(PokemonSpecies::Bulbasaur), new Pokemon(PokemonSpecies::Charmander), new Pokemon(PokemonSpecies::Squirtle)};     // List of Pokemon player has caught
       vector<Pokemon*> selectedTeam = {new Pokemon(PokemonSpecies::Bulbasaur), new Pokemon(PokemonSpecies::Charmander), new Pokemon(PokemonSpecies::Squirtle)};       // Player's team (3 Pokemon)
       Inventory* myInventory;
       Display* myDisplays;

   public:
        void displayPC() const {
            myDisplays->displayPCScreen(this->getTeam());
        }

        Player() : money(0), myInventory(new Inventory()), isEnded(false) {}
        Player(int mon, Inventory* myInven) : money(mon), myInventory(myInven), isEnded(false){}
        ~Player();
       int getMoney() const;
       string getName() const;
       vector<Pokemon*> getCaughtPokemon() const;   
       vector<Pokemon*> getCaughtPokemon();
       void addPokemon(Pokemon* p);
       vector<Pokemon*> getTeam() const;
       vector<Pokemon*> getTeam();
       void accessInventory();
       void enterBattle();
       bool logout();
       void menu();
       void displayPCMenu();
        void viewPokemonStats();
        void viewEditPokemonTeam();
        
};