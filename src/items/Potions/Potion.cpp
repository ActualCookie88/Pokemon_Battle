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

void Potion::useItem() {
    cout << "You used a " << name << " to heal " << healingAmount << " HP!\n";
}

void Potion::displayInfo() const {
    cout << "NAME: " << name << endl;
    cout << "DESC: " << description << endl;
    cout << "HEAL AMOUNT: " << healingAmount << " HP\n";
    cout << "PRICE: " << cost << "¥" << endl;
}
void Potion::displayInfo2() const {
    cout << "NAME: " << name << endl;
    cout << "HEAL AMOUNT: " << healingAmount << " HP\n";
    cout << "AMOUNT: " << amount << endl;
}