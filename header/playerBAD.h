#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <limits>
#include "Inventory.h"
#include "Pokemon/pokemon.h"
#include "battle.h"

using namespace std;

class Player {
   private:
       int money;
       bool isEnded;
       vector<Pokemon*> caughtPokemons = {new Pokemon(PokemonSpecies::Bulbasaur), new Pokemon(PokemonSpecies::Charmander), new Pokemon(PokemonSpecies::Squirtle)};     // List of Pokemon player has caught
       vector<Pokemon*> selectedTeam = {new Pokemon(PokemonSpecies::Bulbasaur), new Pokemon(PokemonSpecies::Charmander), new Pokemon(PokemonSpecies::Squirtle)};       // Player's team (3 Pokemon)
       Inventory* myInventory;

   public:
        //PC
       vector<Pokemon*> getCaughtPokemon() const;   
       vector<Pokemon*> getCaughtPokemon();
       void addPokemon(Pokemon* p);
       vector<Pokemon*> getTeam() const;
       vector<Pokemon*> getTeam();
       
       //battle
       void enterBattle();
       //logout
       bool logout();
       //main menu
       void menu();
       //PC
       void displayPCMenu();
        void viewPokemonStats();
        void viewEditPokemonTeam();
        
};