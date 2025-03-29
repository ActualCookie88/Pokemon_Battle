#pragma once
#include <vector>

#include "../Pokemon/pokemon.h"
#include "Store.h"
#include "PC.h"

using namespace std;

class Player {
    private:
        vector<Item*> playerItems;
        vector<Pokemon*> teamPokemon;
        vector<Pokemon*> caughtPokemon;
        Store* myStore;
        PC* myPC;
        Display* display;
        
    public:
        Player()
         : playerItems( { new StandardBall(), new GreatBall(), new UltraBall(), 
                        new StandardPotion(), new SuperPotion(), new HyperPotion(), 
                        new StandardRevive(), new MaxRevive() } ),
            myStore(new Store(playerItems)),
            myPC(new PC(teamPokemon, caughtPokemon)) {}
        ~Player();            
        // actions
        void accessStore();
        void accessPC();
        // helpers
        void viewMyItems(); // refers to Store function
        void viewPokemonTeam(); // refers to PC function
        // getters
        vector<Item*> getItems() const { return playerItems; }
        Store* getStore() { return myStore; }
        PC* getPC() { return myPC; }
        vector<Pokemon*> getTeam() { return teamPokemon; }
        // setters
        void setItems(vector<Item*> items) { playerItems = items; }
        void setStore(Store* store) {  myStore = store; }
        void setPC(PC* pc) { myPC = pc; }
};