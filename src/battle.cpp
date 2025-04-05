#include "../header/battle.h"
#include <iostream>
#include <vector>
#include <limits>
#include <random>
#include <cstdlib>
#include <ctime>

using namespace std;

void Battle::initiateBattle() {
    int choice = 0;
    bool flag = true;
    while(flag) {
        display->displayBattleScreen();
        cout << "A wild " << wildPokemon->speciesToString(wildPokemon->getSpecies()) << " appeared!" << endl;
        cout << endl;
        cout << "Options:" << endl;
        cout << "(1) View / Use Items" << endl;
        cout << "(2) View / Edit Pokemon Team" << endl;
        cout << "(3) View Active Pokemon Moveset" << endl;
        cout << "(4) View Wild Pokemon stats" << endl;
        cout << "(5) Attempt to flee battle" << endl << endl;
        cout << "Select option: ";
        choice = selectOptionHelper(1,5);
        
        while (!cin || choice <= 0 || choice >= 5) {
            cout << "Invalid input" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> choice; 
        }
        if (choice == 1) {
            viewUseItems();
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
}

void Battle::viewUseItems() {
    int choice = 0;
    bool flag = true;
    while(flag) {
        player->viewMyItems(false);
        cout << "Options: " << endl;
        cout << "(1) View item's stats" << endl;
        cout << "(2) Use an item" << endl;
        cout << "(3) Go back" << endl << endl;
        cout << "Select option: ";
        choice = selectOptionHelper(1,3);
        if(choice == 1) {
            viewItem();
        }
        else if(choice == 2) {
            useItem();
        }
        else if(choice == 3) {
            flag = false;
        }
    }
}

void Battle::viewItem() {
    int i = 0;
    int choice = 0;
    bool flag = true;
    while(flag) {
        cout << "Select item to view: ";
        i = selectOptionHelper(1, 8);
        cout << endl;

        player->viewItemStats(i);
        
        cout << endl;

        cout << "Options: " << endl;
        cout << "(1) View another Item's stats" << endl;
        cout << "(2) Go back" << endl << endl;
        cout << "Select option: ";
        choice = selectOptionHelper(1,2);
        if(choice == 1) {
            player->viewMyItems(false);
        }
        if(choice == 2) {
            flag = false;
        }
    }
}

void Battle::useItem() {
    int i = 0;
    int choice = 0;
    bool flag = true;
    while(flag) {
        cout << "Select item to use: ";
        i = selectOptionHelper(1, 8);

        Item* item = player->getItems().at(i - 1);
        if(item->getAmount() == 0) {
            cout << "INSUFFICIENT AMOUNT." << endl << endl;
        }
        else {
            if(item->isPokeball()) {
                item->useItem();
                Pokeball* pokeball = dynamic_cast<Pokeball*>(item);
                if(pokeball) {  // Check if the cast was successful
                    catchPokemon(wildPokemon, pokeball);
                } else {
                    cout << "Error: This item is not a Pokeball!" << endl;
                }
            }
            else if(item->isPotion()) {
    
            }
            else if(item->isRevive()) {
    
            }
            else {
                cout << "Item does not exist" << endl;
            }
        }
    }
}

void Battle::catchPokemon(WildPokemon* wildPokemon, Pokeball* item) {
    srand(time(0));  // Only once per method call

    double baseCatchRate = wildPokemon->getBaseCatchRate();
    double ballMultiplier = item->getMultiplier();
    double currentHP = wildPokemon->getHP();
    double maxHP = wildPokemon->getMaxHP();

    double hpRatio = currentHP / maxHP;
    double chance = ( (3 * maxHP) - (2 * currentHP) / (3 * maxHP) ) * baseCatchRate * ballMultiplier;
    double roll = rand() % 100 + 1;

    cout << baseCatchRate << endl;

    cout << "Rate to catch: " << chance << endl;
    cout << "Rate rolled: " << roll << endl << endl;

    if(roll <= chance) {
        cout << wildPokemon->speciesToString(wildPokemon->getSpecies()) << " was caught!" << endl << endl;
        this->getPlayer()->getPC()->addPokemon(wildPokemon);  // Add Pokémon to PC
        wildPokemon->setBaseHP(0);  // Set wild Pokémon's HP to 0 (caught)
        endBattle();  // End the battle
    }
    else {
        cout << "The Pokémon broke free!" << endl;
    }
}





void Battle::viewTeam() {
    player->viewPokemonTeam();
}

int Battle::randomNum(int min, int max) {
    return min + (rand() % (max-min+1));
}

bool Battle::checkBattleEnd() const {
    int sum = 0;
    for (Pokemon* pokemon : player->getTeam()) {
        sum += pokemon->getHP();
    }
    return sum <= 0 || wildPokemon->getHP() <= 0;
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

void Battle::endBattle() {
    if (player->getTeam()[0]->getHP() <= 0) {
        display->displayLoseScreen();
    } 
    else if (wildPokemon->getHP() <= 0) {
        cout << "You Won!" << endl;
        cout << endl;
    }
}

void Battle::flee() {
    static random_device rd;
    static mt19937 gen(rd());
    static bernoulli_distribution dist(0.5); // 50% chance

    if (dist(gen)) {
        cout << "You got away safely!" << endl;
        return;

    } else {
        cout << "You failed to escape!" << endl;
    }
}

int Battle::clearInputHelper() {
    int i = 0;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin >> i;
    cout << endl;
    return i;
}

int Battle::selectOptionHelper(int min, int max) {
    int i = 0;
    cin >> i;
    cout << endl;
    return validateInput(i, min, max);
}

int Battle::validateInput(int input, int min, int max) {
    while (cin.fail() || input < min || input > max) {
        cout << "INVALID OPTION. TRY AGAIN: ";
        input = clearInputHelper();
    }
    return input;
}