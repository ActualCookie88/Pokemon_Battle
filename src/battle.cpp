#include "../header/battle.h"
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void loseScreen() {
    cout << "//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << " __________________________________________________________________________" << endl;
    cout << "|                                                                          |" << endl;
    cout << "|     _   _   _____   _   _          _       _____   _____   _____   _     |" << endl;
    cout << "|    \\ \\ / / |  _  | | | | |        | |     |  _  | |  ___| |  ___| | |    |" << endl;
    cout << "|     \\ V /  | | | | | | | |        | |     | | | | | |___  | |___  | |    |" << endl;
    cout << "|      | |   | | | | | | | |        | |     | | | | |___  | |  ___| |_|    |" << endl;
    cout << "|      | |   | |_| | | |_| |        | |___  | |_| |  ___| | | |___   _     |" << endl;
    cout << "|      |_|   |_____| |_____|        |_____| |_____| |_____| |_____| |_|    |" << endl;
    cout << "|                                                                          |" << endl;
    cout << "|__________________________________________________________________________|" << endl;
    cout << endl;
    cout << "ALL OF YOUR POKEMON HAVE FAINTED!" << endl;
    cout << "(1) Use Revive Item" << endl; // only works if the user actually owns one, use conditional
    cout << "(2) Give up and flee" << endl;
    cout << endl;
}

void Battle::battleMenu() {
    int choice;
    
    cout << "//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << " _____________________________________________________________________________________________________" << endl;
    cout << "|                                                                                                     |" << endl;
    cout << "|     ____     _____   _______   _______   _       ____          _     _   _____   __   _   _   _     |" << endl;
    cout << "|    |  _  \\  |  _  | |__   __| |__   __| | |     |  __|        | \\   / | |  ___| |  \\ | | | | | |    |" << endl;
    cout << "|    | |_)  | | |_| |    | |       | |    | |     | |__         |  \\ /  | | |___  |   \\| | | | | |    |" << endl;
    cout << "|    |  _  /  |  _  |    | |       | |    | |     |  __|        | |\\ /| | |  ___| | |\\   | | | | |    |" << endl;
    cout << "|    | |_) \\  | | | |    | |       | |    | |___  | |__         | |   | | | |___  | | \\  | | |_| |    |" << endl;
    cout << "|    |_____/  |_| |_|    |_|       |_|    |_____| |____|        |_|   |_| |_____| |_|  \\_| |_____|    |" << endl;
    cout << "|                                                                                                     |" << endl;
    cout << "|_____________________________________________________________________________________________________|" << endl;
    cout << endl;
    cout << "(1) View/Use Items" << endl;
    cout << "(2) View/Edit Pokemon Team" << endl;
    cout << "(3) View Active Pokemon Moveset" << endl;
    cout << "(4) View Wild Pokemon stats" << endl;
    cout << "(5) Attempt to flee battle" << endl;
    cout << endl;

    cin >> choice;
    while (!cin || choice <= 0 || choice >= 6) {
        cout << "Invalid input" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> choice; 
    }

    if (choice == 1) {
        //view/use items
    } else if (choice == 2) {
        //view/edit pokemon team
    } else if (choice == 3) {
        //view active pokemon moveset
    } else if (choice == 4) {
        //view wild pokemon stats
    } else if (choice == 5) {
        // call flee function
    }
}

int Battle::randomNum(int min, int max) {
    return min + (rand() % (max-min+1));
}

bool Battle::checkBattleEnd() const {
    return player->getTeam()[0]->getBaseHP() <= 0 || wildPokemon->getBaseHP() <=0;
}

void Battle::startBattle() {
    cout << "A wild " << wildPokemon->speciesToString(wildPokemon->getSpecies()) << " appeared!" << endl;
    while (!checkBattleEnd()) {
        if (isPlayerTurn) {
            //playerTurn();
        } else {
            //wildPokemonTurn();
        }
        isPlayerTurn = !isPlayerTurn;
    }
    endBattle();
}

bool Battle::isCatchable() const {
    return wildPokemon->getBaseHP() < 40;
}

bool Battle::isCatchSuccess(const Pokeball& pokeball) {
    if (isCatchable()) {
        int baseChance = 70;
        double modifiedChance = baseChance * pokeball.getMultiplier();
        int chance = randomNum(1, 100);
        if (chance <= modifiedChance) {
            player->addPokemon(wildPokemon);
            wildPokemon->setBaseHP(0);
            cout << "You just caught the Pokemon!" << endl;
            endBattle();
            return true;
        } else {
            cout << "The Pokemon broke out of the Pokeball!" << endl;
            return false;
        }
    } else {
        cout << "The Pokemon is too strong to catch!" << endl;
        return false;
    }
}

void Battle::viewItems() const {
    player->accessInventory();
}

void Battle::viewTeam() const {
    vector<Pokemon*> team = player->getTeam();
    cout << "Your team: " << endl;
    for (int i=0; i<team.size(); i++) {
        cout << i+1 << ". " << endl;
        team[i]->displayInfo();

    }
}

void Battle::flee() {
    if (randomNum(1, 100) <= 50) {
        cout << "You got away safely!" << endl;
        wildPokemon->setBaseHP(0); //end battle
    } else {
        cout << "Could not escape" << endl;
    }
}

void Battle::endBattle() {
    if (player->getTeam()[0]->getBaseHP() <= 0) {
        loseScreen();
    } else if (wildPokemon->getBaseHP() <= 0) {
        cout << "You Won!" << endl;
        cout << endl;
        battleMenu();
    }
}