#pragma once
#include <vector>

#include "Pokemon/pokemon.h"
#include "Store.h"

using namespace std;

class Player {
    private:
        vector<Item*> playerItems;
        Store* myStore;

    public:
        Player() : playerItems( { new StandardBall(), new GreatBall(), new UltraBall(), 
                            new StandardPotion(), new SuperPotion(), new HyperPotion(), 
                            new StandardRevive(), new MaxRevive() } ),
                    myStore(new Store(playerItems)) {}
        ~Player() {}                
        // screen accessors
        void accessStore();
        void accessPC();
        // getters and setters
        vector<Item*> getItems() const { return playerItems; }
        Store* getStore() { return myStore; }
};