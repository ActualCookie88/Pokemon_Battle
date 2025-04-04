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

void Pokeball::catchPokemon(Battle* battle, int baseCatchChance) const {
    srand(time(0));  // Only once per method call

    double chance = baseCatchChance * getMultiplier();  
    double roll = rand() % 100 + 1;

    cout << "(" << roll << "% roll to catch)" << endl;
    cout << "(" << chance << "% chance to catch)" << endl;
    if(roll <= chance) {
        cout << "Pokémon was caught!" << endl;
        battle->getPlayer()->getPC()->addPokemon(battle->getWildPokemon());  // Add Pokémon to PC
        battle->getWildPokemon()->setBaseHP(0);  // Set wild Pokémon's HP to 0 (caught)
        battle->endBattle();  // End the battle
    }
    else {
        cout << "The Pokémon broke free!" << endl;
    }
}

void Pokeball::useItem() {
    cout << "You used a " << name << " with a multiplier of " << multiplier << "x!\n";
    sellAmount(1);
}

void Pokeball::displayInfo() const {
    cout << "Name: " << name << endl;
    cout << "    Description: " << description << endl;
    cout << "    Catch Multiplyer: " << multiplier << "x" << endl;
    cout << "    Price: " << cost << "¥" << endl;
}

double Pokeball::getMultiplier() const { return multiplier; }