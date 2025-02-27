#include "../../header/Pokeballs/Pokeball.h"
#include <cstdlib>
#include <ctime>

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

bool Pokeball::isPokemonCaught(double baseCatchChance) const{
    srand(time(0));
    double chance = (baseCatchChance * multiplier);
    double roll = (rand() % 100 + 1) / 100.0;
    return roll < chance;
}

void Pokeball::printIfPokemonCaught(double baseCatchChance) const {
    if(isPokemonCaught(baseCatchChance)) {
        cout << "Pokémon was caught!" << endl;
    }
    else {
        cout << "The Pokémon broke free!" << endl;
    }
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