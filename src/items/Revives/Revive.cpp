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
            restorePercent = 0.5; // default to Standard
    }
}

void Revive::useItem() {
    cout << "You used a " << name << ", restoring " << (restorePercent * 100) << "% HP to a fainted Pokemon!" << std::endl;
}

void Revive::displayInfo() const {
    cout << "NAME: " << name << endl;
    cout << "    DESC: " << description << endl;
    cout << "    RESTORE AMOUNT: " << (restorePercent * 100) << "%" << endl;
    cout << "    PRICE: " << cost << "¥" << endl;
}

void Revive::displayInfo2() const {
    cout << "NAME: " << name << endl;
    cout << "    RESTORE AMOUNT: " << (restorePercent * 100) << "%" << endl;
    cout << "    AMOUNT: " << amount << endl;
}
