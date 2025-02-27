#include "../header/Item.h"

Item::Item(string itemName, string itemDesc, int itemCost) : name(itemName), description(itemDesc), cost(itemCost) {}

string Item::getName() const { return name; }

string Item::getDescription() const { return description; }

int Item::getCost() const { return cost; }

int Item::getAmount() const { return amount; }

void Item::addAmount(int& amount) { amount++; }

void Item::sellAmount(int& amount) { amount--; }
