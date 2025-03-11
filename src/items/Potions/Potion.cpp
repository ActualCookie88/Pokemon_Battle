#include "../../../header/items/Potions/Potion.h"
#include <iostream>
using std::cout;

Potion::Potion(string potionName, string desc, int potionCost, PotionType potionType)
 : Item(potionName, desc, potionCost) {
    switch (potionType) {
        case STANDARD:
            healingAmount = 20;
            break;
        case SUPER:
            healingAmount = 50;
            break;
        case HYPER:
            healingAmount = 120;
            break;
        default:
            healingAmount = 20; // default to Standard
    }
 }

void Potion::useItem() const {
    cout << "You used a " << name << " to heal " << healingAmount << " HP.\n";
}

void Potion::displayInfo() const {
    cout << "Name: " << name << endl;
    cout << "    Description: " << description << endl;
    cout << "    Healing Amount: " << healingAmount << " HP\n";
    cout << "    Price: " << cost << "¥" << endl;
}