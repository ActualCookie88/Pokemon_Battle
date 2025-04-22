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
        // helpers
        bool isPokeball() const;
        bool isPotion() const;
        bool isRevive() const;
        // getters and setters
        string getName() const;
        string getDescription() const;
        int getCost() const;
        int getAmount() const;
        void addAmount(int amount);
        void sellAmount(int amount);
        void setAmount(int amount);
        // pure functions
        virtual void useItem() = 0;
        virtual void displayInfo() const = 0;
        virtual void displayInfo2() const = 0;
};
