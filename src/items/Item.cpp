#include "../../header/items/Item.h"

Item::Item()
 : name("Default"), description("No description"), cost(0), amount(0) {}

Item::Item(string itemName, string itemDesc, int itemCost)
 : name(itemName), description(itemDesc), cost(itemCost), amount(0) {}

bool Item::isPokeball() const {
    return name == "Standard Ball" || name == "Great Ball" || name == "Ultra Ball";
}

bool Item::isPotion() const {
    return name == "Standard Potion" || name == "Super Potion" || name == "Hyper Potion";
}

bool Item::isRevive() const {
    return name == "Revive" || name == "Max Revive";
}

string Item::getName() const { return name; }

string Item::getDescription() const { return description; }

int Item::getCost() const { return cost; }

int Item::getAmount() const { return amount; }

void Item::addAmount(int amount) { this->amount += amount; }

void Item::sellAmount(int amount) { this->amount -= amount; }

void Item::setAmount(int amount) { this->amount == amount; }