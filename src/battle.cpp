#include "../header/battle.h"
#include <iostream>
#include <vector>
#include <limits>
#include <random>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

void Battle::initiateBattle() {
    int choice = 0;
    bool flag = true;
    while(flag) {
        display->displayBattleScreen();
        cout << "A wild " << wildPokemon->getName() << " appeared!" << endl;
        wildPokemon->displayBattleInfo();
        cout << endl;

        cout << "Active Pokemon: " << activePokemon->getName() << endl;
        activePokemon->displayBattleInfo();
        cout << endl;
        cout << "Options:" << endl;
        cout << "(1) BAG" << endl;
        cout << "(2) POKEMON" << endl;
        cout << "(3) FIGHT" << endl;
        cout << "(4) FLEE" << endl << endl;
        cout << "Select option: ";
        choice = selectOptionHelper(1,4);
        
        if (choice == 1) {
            viewUseItems();
        } else if (choice == 2) {
            viewEditTeam();
        } else if (choice == 3) {
            //view active pokemon moveset
        } else if (choice == 4) {
            if(fleeSuccess()) {
                return;
            }
            else {
                wildPokemonTurn();
            }
        }
        if(pokemonIsCaught == true) {
            return;
        }
    }
}

void Battle::viewUseItems() {
    int choice = 0;
    bool flag = true;
    while(flag) {
        player->viewMyItems(false);
        cout << "Options: " << endl;
        cout << "(1) VIEW STATS" << endl;
        cout << "(2) USE ITEM" << endl;
        cout << "(3) BACK" << endl << endl;
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
        cout << "SELECT ITEM: ";
        i = selectOptionHelper(1, 8);
        cout << endl;

        player->viewItemStats(i);
        
        cout << endl;

        cout << "Options: " << endl;
        cout << "(1) VIEW MORE STATS" << endl;
        cout << "(2) BACK" << endl << endl;
        cout << "Select option: ";
        choice = selectOptionHelper(1,2);
        if(choice == 1) {
            player->viewMyItems(false);
        }
        else if(choice == 2) {
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
                useBall(wildPokemon, pokeball);
                return;
            }
            else if(item->isPotion()) {
                if(isTeamFullHP()) {
                    cout << "Your Pokemon are at full health!" << endl;
                    cout << "(1) Go back" << endl << endl;
                    cout << "Select option: ";
                    choice = selectOptionHelper(1,1);
                    if(choice == 1) {
                        flag = false;
                    }
                }
                else {
                    viewTeam(2);
                    cout << "Select Pokemon to use " << item->getName() << " on: ";
                    i = selectOptionHelper(1, 3);
    
                    Pokemon* pokemon = player->getTeam().at(i-1);
                    while (pokemon->getHP() <= 0) {
                        cout << "CANNOT CHOOSE A FAINTED POKEMON, TRY AGAIN: ";
                        i = selectOptionHelper(1, 3);
                        pokemon = player->getTeam().at(i-1);
                    }
                    Potion* potion = dynamic_cast<Potion*>(item);
                    item->useItem();
                    usePotion(pokemon, potion);
                    return;
                }
                
            }
            else if(item->isRevive()) {
                if(!hasFaintedPokemon()) {
                    cout << "You have no Pokemon to revive!" << endl;
                    cout << "(1) Go back" << endl << endl;
                    cout << "Select option: ";
                    choice = selectOptionHelper(1,1);
                    if(choice == 1) {
                        flag = false;
                    }
                }
                else {
                    viewTeam(2);
                    cout << "Select Pokemon to use " << item->getName() << " on: ";
                    i = selectOptionHelper(1, 3);

                    Pokemon* pokemon = player->getTeam().at(i-1);
                    while (pokemon->getHP() > 0) {
                        cout << "CAN ONLY CHOOSE A FAINTED POKEMON, TRY AGAIN: ";
                        i = selectOptionHelper(1, 3);
                        pokemon = player->getTeam().at(i-1);
                    }
                    
                    Revive* revive = dynamic_cast<Revive*>(item);
                    item->useItem();
                    useRevive(pokemon, revive);
                    return;
                }
            }
            else {
                cout << "Item does not exist" << endl;
            }
        }
    }
}

void Battle::useBall(WildPokemon* wildPokemon, Pokeball* pokeball) {
    srand(time(0));  // Only once per method call

    double baseCatchRate = wildPokemon->getBaseCatchRate();
    double ballMultiplier = pokeball->getMultiplier();
    double currentHP = wildPokemon->getHP();
    double maxHP = wildPokemon->getMaxHP();

    double hpRatio = currentHP / maxHP;
    double chance = ( ( (3 * maxHP) - (2 * currentHP) ) / (3 * maxHP) ) * baseCatchRate * ballMultiplier;
    double roll = rand() % 100 + 1;

    sleep_for(1s);
    cout << ". . ." << endl << endl;
    sleep_for(1s);
    if(roll > chance * 3) {
        cout << "The Pokemon broke free!" << endl;
        wildPokemonTurn();
        return;
    }
    cout << ". . ." << endl << endl;
    sleep_for(1s);
    if(roll > chance * 1.5) {
        cout << "The Pokemon broke free!" << endl;
        wildPokemonTurn();
        return;
    }
    cout << ". . ." << endl << endl;
    sleep_for(1s);
    if(roll <= chance) {
        cout << wildPokemon->getName() << " was caught!" << endl << endl;
        this->getPlayer()->getPC()->addPokemon(wildPokemon);  // Add Pokemon to PC
        wildPokemon->setBaseHP(0);  // Set wild Pokemon's HP to 0 (caught)
        pokemonIsCaught = true;
        endBattle(true);  // End the battle
    }
    else {
        cout << "The Pokemon broke free!" << endl;
        wildPokemonTurn();
        return;
    }
}

void Battle::usePotion(Pokemon*& pokemon, Potion* potion) {
    cout << endl;
    pokemon->addHP(potion->getHealingAmount());
    cout << pokemon->getName() << " now has " << pokemon->getHP() << " HP!" << endl;
    cout << endl;
}

void Battle::useRevive(Pokemon*& pokemon, Revive* revive) {
    cout << endl;
    pokemon->addHP(pokemon->getMaxHP() * revive->getRestorePercent());
    cout << pokemon->getName() << " now has " << pokemon->getHP() << " HP!" << endl;
    cout << endl;
}

void Battle::viewEditTeam() {
    int choice = 0;
    bool flag = true;
    while(flag) {
        viewTeam(0);
        cout << "Active Pokemon: " << activePokemon->getName() << endl << endl;
        cout << "Options: " << endl;
        cout << "(1) SWAP POKEMON" << endl;
        cout << "(2) BACK" << endl << endl;
        cout << "Select option: ";
        choice = selectOptionHelper(1,2);
        if(choice == 1) {
            editTeam();
            return;
        }
        else if(choice == 2) {
            flag = false;
        }
    }
}

void Battle::viewTeam(int option) {
    player->viewPokemonTeam(option);
}

void Battle::editTeam() {
    int i = 0;
    bool flag = true;

    vector<Pokemon*>& team = player->getTeam();

    while(flag) {
        cout << "Select Pokemon to swap: ";
        i = selectOptionHelper(1,3);

        Pokemon* pokemonToSwap = team.at(i-1);
        while (pokemonToSwap == activePokemon) {
            cout << "POKEMON IS ALREADY ACTIVE, TRY AGAIN: ";
            i = selectOptionHelper(1, 3);
            pokemonToSwap = team.at(i-1);
        }
        cout << activePokemon->getName() << ", switch out!" << endl << endl;

        swap(team[0], team[i - 1]);
        
        activePokemon = team[0];

        sleep_for(0.75s);
        cout << "." << flush;;
        sleep_for(0.75s);
        cout << " ."  << flush;;
        sleep_for(0.75s);
        cout << " ." << endl << endl;
        sleep_for(0.75s);
        cout << pokemonToSwap->getName() << ", I choose you!" << endl << endl;
        flag = false;
    }
}

bool Battle::checkBattleEnd() const {
    int sum = 0;
    for (Pokemon* pokemon : player->getTeam()) {
        sum += pokemon->getHP();
    }
    return sum <= 0 || wildPokemon->getHP() <= 0;
}

bool Battle::hasFaintedPokemon() const {
    for (Pokemon* pokemon : player->getTeam()) {
        if(pokemon->getHP() <= 0 ) {
            return true;
        }
    }
    return false;
}

bool Battle::isTeamFullHP() const {
    for (Pokemon* pokemon : player->getTeam()) {
        if(pokemon->getHP() != pokemon->getMaxHP()) {
            return false;
        }
    }
    return true;
}

void Battle::endBattle(bool pokemonCaught) {
    if(pokemonCaught) {
        cout << wildPokemon->getName() << " has been added to your PC!" << endl;
    }
    else if (player->getTeam()[0]->getHP() <= 0) {
        display->displayLoseScreen();
    } 
    else if (wildPokemon->getHP() <= 0) {
        cout << "The wild " << wildPokemon->getName() << " has fainted!" << endl;
        cout << endl;
    }
    return;
}

void Battle::wildPokemonTurn() {
    cout << endl;
    sleep_for(0.75s);
    cout << "." << flush;;
    sleep_for(0.75s);
    cout << " ."  << flush;;
    sleep_for(0.75s);
    cout << " ." << endl << endl;
    sleep_for(0.75s);
    Attack* attack = wildPokemon->wildPokemonMove(activePokemon);
    cout << wildPokemon->getName() << " used " << attack->getName() << "!" << endl;
    sleep_for(3s);
}

bool Battle::fleeSuccess() {
    static random_device rd;
    static mt19937 gen(rd());
    static bernoulli_distribution dist(0.5); // 50% chance

    if (dist(gen)) {
        cout << "You got away safely!" << endl;
        return true;
    } 
    else {
        cout << "You failed to escape!" << endl;
        return false;
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