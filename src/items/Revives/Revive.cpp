#include "../../../header/items/Revives/Revive.h"

Revive::Revive(string reviveName, string desc, int reviveCost, ReviveType reviveType)
 : Item(reviveName, desc, reviveCost) {
    switch (reviveType) {
        case STANDARD:
            restorePercent = 0.5;
            break;
        case MAX:
            restorePercent = 1;
            break;
        default:
            restorePercent = .5; // default to Standard
    }
}

void Revive::useItem() {
    cout << "You used a " << name << ", restoring " << (restorePercent * 100) << "% HP to a fainted Pokémon!" << std::endl;
}

void Revive::displayInfo() const {
    cout << "Name: " << name << endl;
    cout << "    Description: " << description << endl;
    cout << "    Health Restored: " << (restorePercent * 100) << "%" << endl;
    cout << "    Price: " << cost << "¥" << endl;
}