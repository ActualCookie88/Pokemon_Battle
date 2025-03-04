#pragma once
#include <vector>

#include "Item.h"
#include "Pokeballs/StandardBall.h"
#include "Pokeballs/GreatBall.h"
#include "Pokeballs/UltraBall.h"
#include "Potions/StandardPotion.h"
#include "Potions/SuperPotion.h"
#include "Potions/HyperPotion.h"
#include "Revives/StandardRevive.h"
#include "Revives/MaxRevive.h"

using namespace std;

class Store {
    private:
        int money = 0;
        vector<Item*> playerItems;
        vector<Item*> storeItems;

    public:
        Store() : playerItems({}), storeItems({}) {}
        Store(vector<Item*>& items)
         : playerItems(items),
            storeItems( { new StandardBall(), new GreatBall(), new UltraBall(), 
                        new StandardPotion(), new SuperPotion(), new HyperPotion(), 
                        new StandardRevive(), new MaxRevive() } ) {}
        ~Store() {}
        //actions
        void initiateStore();
        void buyItem();
        void sellItem();
        void viewMyItems(bool isViewing);
        void viewStoreItems() const;
        // helpers
        int amountHelper();
        int clearInputHelper();
        int selectOptionHelper1();
        bool selectOptionHelper2();
        // getters and setters
        int getMoney() const { return money; }
        void setMoney(int mon) { money = mon; }
};