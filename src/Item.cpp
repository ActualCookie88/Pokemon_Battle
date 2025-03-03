#include "../header/Item.h"

Item::Item()
 : name("Default"), description("No description"), cost(0), amount(0) {}

Item::Item(string itemName, string itemDesc, int itemCost)
 : name(itemName), description(itemDesc), cost(itemCost), amount(0) {}

string Item::getName() const { return name; }

string Item::getDescription() const { return description; }

int Item::getCost() const { return cost; }

int Item::getAmount() const { return amount; }

void Item::addAmount(int amount) { amount++; }

void Item::sellAmount(int amount) { amount--; }
