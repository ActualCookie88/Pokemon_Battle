#include "../header/battle.h"
#include <iostream>
#include <vector>
#include <limits>
#include <random>

using namespace std;

void Battle::battleMenu() {
    int choice;
    
    display->displayBattleScreen();

    cin >> choice;
    while (!cin || choice <= 0 || choice >= 6) {
        cout << "Invalid input" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> choice; 
    }

    if (choice == 1) {
        viewItems();
    } else if (choice == 2) {
        viewTeam();
    } else if (choice == 3) {
        //view active pokemon moveset
    } else if (choice == 4) {
        //view wild pokemon stats
    } else if (choice == 5) {
        flee();
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

bool Battle::isCatchSuccess(const Pokeball& pokeball) {
    int baseChance = 70;
    double modifiedChance = baseChance * pokeball.getMultiplier();
    int chance = randomNum(1, 100);
    if (chance <= modifiedChance) {
        player->getPC()->addPokemon(wildPokemon);
        wildPokemon->setBaseHP(0);
        cout << "You just caught the Pokemon!" << endl;
        endBattle();
        return true;
    } else {
        cout << "The Pokemon broke out of the Pokeball!" << endl;
        return false;
    }
    return false;
}

void Battle::viewItems() const {
    player->viewMyItems();
}

void Battle::viewTeam() const {
    player->viewPokemonTeam();
}

void Battle::flee() {
    static random_device rd;
    static mt19937 gen(rd());
    static bernoulli_distribution dist(0.5); // 50% chance

    if (dist(gen)) {
        cout << "You got away safely!" << endl;
        wildPokemon->setBaseHP(0); // End battle

    } else {
        cout << "You failed to escape!" << endl;
    }
}

void Battle::endBattle() {
    if (player->getTeam()[0]->getHP() <= 0) {
        display->displayLoseScreen();
    } 
    else if (wildPokemon->getHP() <= 0) {
        cout << "You Won!" << endl;
        cout << endl;
    }
}