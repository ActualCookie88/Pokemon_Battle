#include "../../../header/items/Pokeballs/Pokeball.h"
#include <cstdlib>
#include <ctime>
#include <iomanip>

Pokeball::Pokeball()
 : Item() {}

Pokeball::Pokeball(string ballName, string desc, int ballCost, BallType ballType)
 : Item(ballName, desc, ballCost) {
    switch (ballType) {
        case STANDARD:
            multiplier = 1.0;
            break;
        case GREAT:
            multiplier = 1.5;
            break;
        case ULTRA:
            multiplier = 2.0;
            break;
        case MASTER:
            multiplier = 100.0;
            break;
        default:
            multiplier = 1.0; // default to Standard
    }
}

void Pokeball::useItem() {
    cout << "You thew a " << name << "!" << endl << endl;
    sellAmount(1);
}

void Pokeball::displayInfo() const {
    cout << "Name: " << name << endl;
    cout << "    Description: " << description << endl;
    cout << "    Catch Multiplyer: " << multiplier << "x" << endl;
    cout << "    Price: " << cost << "¥" << endl;
}

double Pokeball::getMultiplier() const { return multiplier; }