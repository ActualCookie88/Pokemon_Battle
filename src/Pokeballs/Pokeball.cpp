#include "../../header/Pokeballs/Pokeball.h"
#include <cstdlib>
#include <ctime>

Pokeball::Pokeball(string ballName, string desc, int ballCost, BallType ballType) : Item(ballName, desc, ballCost) {
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

bool Pokeball::catchPokemon(double baseCatchChance) {
    double chance = (baseCatchChance * multiplier);
    double roll = (rand() % 100) / 100.0; // rand # between 0 and 1
    return roll < chance;
}
void Pokeball::useItem() const {
    cout << "You used a " << name << " with a multiplier of " << multiplier << "x.\n";
}

void Pokeball::displayInfo() const {
    cout << "Name: " << name << endl;
    cout << "    Description: " << description << endl;
    cout << "    Catch Multiplyer: " << multiplier << "x" << endl;
    cout << "    Price: " << cost << "¥" << endl;
}