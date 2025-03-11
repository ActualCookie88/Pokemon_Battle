#pragma once

#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Item {
    protected:
        string name;
        string description;
        int cost;
        int amount;

    public:
        Item();
        Item(string itemName, string itemDesc, int itemCost);
        virtual ~Item() {}

        string getName() const;
        string getDescription() const;
        int getCost() const;
        int getAmount() const;
        void addAmount(int amount);
        void sellAmount(int amount);

        virtual void useItem() const = 0;
        virtual void displayInfo() const = 0;
        
};
