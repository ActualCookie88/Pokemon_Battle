#pragma once
#include <vector>

#include "Pokemon/pokemon.h"
#include "Store.h"

using namespace std;

class Player {
    private:
        Store* myStore;
        vector<Item*> items;

    public:
        Player() : items( { new StandardBall(), new GreatBall(), new UltraBall(), 
                            new StandardPotion(), new SuperPotion(), new HyperPotion(), 
                            new StandardRevive(), new MaxRevive() } ),
                    myStore(new Store(items)) {}

        ~Player() {}        
        void accessStore();
        void accessPC();
};