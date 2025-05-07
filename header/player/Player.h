#pragma once
#include <vector>

#include "../Pokemon/pokemon.h"
#include "Store.h"
#include "PC.h"

using namespace std;

class Player {
    private:
        int money = 0;
        vector<Item*> playerItems;
        vector<Pokemon*> teamPokemon;
        vector<Pokemon*> caughtPokemon;
        Store* myStore;
        PC* myPC;
        Display* display;
    public:
        Player() : 
        playerItems({   new StandardBall(), new GreatBall(), new UltraBall(), 
                        new StandardPotion(), new SuperPotion(), new HyperPotion(), 
                        new StandardRevive(), new MaxRevive() }),
        teamPokemon({   new Pokemon(PokemonSpecies::Charmander), 
                        new Pokemon(PokemonSpecies::Bulbasaur), 
                        new Pokemon(PokemonSpecies::Squirtle) }),
        caughtPokemon({}),
        myStore(new Store(playerItems)),
        myPC(new PC(teamPokemon, caughtPokemon)){}
        ~Player();            
        // actions
        void accessStore();
        void accessPC();
        void initiateAll(int auth);
        // helpers
        bool hasRevives();
        void displayRevives();
        void viewMyItems(bool isViewing); // Store function
        void viewItemStats(int itemNum); // Store function
        void viewPokemonTeam(int option); // PC function
        void displayTeamStats(); // PC function
        // getters
        vector<Item*> getItems() const;
        vector<Pokemon*>& getTeam();
        vector<Pokemon*> getCaught();
        vector<Pokemon*> getTeamAndCaught();
        Store* getStore();
        PC* getPC();
        Display* getDisplay();
        int getMaxLevelPokemon();
        int getAVGLevelPokemon();
        int getTotalPokemon();
        // setters
        void setItems(vector<Item*> items);
        void setStore(Store* store);
        void setPC(PC* pc);
        void setTeamlevel(int val);
        void setActivePokemon(Pokemon* pokemon);
};