#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <limits>
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

class Inventory
{
    private:
        vector<Item*> items = {new StandardBall(), new GreatBall(), new UltraBall(), new StandardPotion(), new SuperPotion(), new HyperPotion(), new StandardRevive(), new MaxRevive()};
        int money = 0;

    public:
        ~Inventory();
        void viewMyItems();

        void store();
        void storeItems();

        void buyItem();
        void sellItem();
        
        void addMoney(int );
        int getMoney();

        int selectOptionHelper1();
        bool selectOptionHelper2();
        int clearInputHelper();
        int amountHelper();
        
        bool useItems(string );
        vector<Item*> getItems(){
            return items;
        }
};