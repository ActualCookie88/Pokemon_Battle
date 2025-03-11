#pragma once
#include <vector>

#include "../items/Item.h"
#include "../items/Pokeballs/StandardBall.h"
#include "../items/Pokeballs/GreatBall.h"
#include "../items/Pokeballs/UltraBall.h"
#include "../items/Potions/StandardPotion.h"
#include "../items/Potions/SuperPotion.h"
#include "../items/Potions/HyperPotion.h"
#include "../items/Revives/StandardRevive.h"
#include "../items/Revives/MaxRevive.h"
#include "../Display.h"
using namespace std;

class Store {
    private:
        int money = 0;
        vector<Item*> playerItems;
        vector<Item*> storeItems;
        Display* display;

    public:
        Store() : playerItems({}), storeItems({}) {}
        Store(vector<Item*>& items) : playerItems(items), storeItems( { new StandardBall(), new GreatBall(), new UltraBall(), 
                                                                        new StandardPotion(), new SuperPotion(), new HyperPotion(), 
                                                                        new StandardRevive(), new MaxRevive() } ) {}
        ~Store();
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