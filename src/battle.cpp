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
    activePokemon = player->getTeam().at(0);
    int choice = 0;
    bool flag = true;
    while(flag) {
        display->displayBattleScreen();
        cout << "A wild " << wildPokemon->getName() << " appeared!" << endl;
        wildPokemon->displayBattleInfo();
        cout << endl;
        cout << "Active Pokemon: " << activePokemon->getName() << endl;
        activePokemon->displayBattleInfo();
        display->border2();
        cout << "Options:" << endl;
        cout << "(1) BAG" << endl;
        cout << "(2) POKEMON" << endl;
        cout << "(3) FIGHT" << endl;
        cout << "(4) FLEE" << endl << endl;
        cout << "SELECT OPTION: ";
        choice = selectOptionHelper(1,4);

        if(choice == 1) {
            viewUseItems();
        } 
        else if(choice == 2) {
            viewEditTeam();
        } 
        else if(choice == 3) {
            chooseMove();
        } 
        else if(choice == 4) {
            if(fleeSuccess()) {
                updateLoss();
                return;
            }
        }
        if(wildPokemon->getHP() == 0 || pokemonIsCaught) {
            updateWin();
            return;
        }
        if(playerTurnOver) {
            wildPokemonTurn();
        }
        if(allFaintedPokemon()) {
            display->displayLoseScreen();
            cout << "Options:" << endl;
            if(player->hasRevives()) {
                cout << "(1) Use Revive Item" << endl;
                cout << "(2) Give up and flee" << endl;
                cout << "SELECT OPTION: ";
                choice = selectOptionHelper(1,2);
                if(choice == 1) {
                    display->border();
                    useReviveAfterLost();
                }
                else if(choice == 2) {
                    sleep_for(1s);
                    cout << "You fled the battle!" << endl;
                    sleep_for(1s);
                    updateLoss();
                    return;
                }
            }
            else {
                cout << "(1) Give up and flee" << endl;
                cout << "SELECT OPTION: ";
                choice = selectOptionHelper(1,1);
                sleep_for(1s);
                cout << "You fled the battle!" << endl;
                sleep_for(1s);
                updateLoss();
                return;
            }
            
        }
    }
}

void Battle::viewUseItems() {
    int choice = 0;
    bool flag = true;
    while(flag) {
        player->viewMyItems(false);
        display->border2();
        cout << "Options: " << endl;
        cout << "(1) USE ITEM" << endl;
        cout << "(2) BACK" << endl << endl;
        cout << "SELECT OPTION: ";
        choice = selectOptionHelper(1,2);
        if(choice == 1) {
            useItem();
            if(pokemonIsCaught || playerTurnOver) return;
        }
        else if(choice == 2) {
            return;
        }
    }
}

void Battle::useItem() {
    int choice = 0;
    bool flag = true;
    while(flag) {
        cout << "(Enter CANCEL to cancel choice)" << endl << endl;
        cout << "Select item to use: ";
        choice = selectOptionHelper(1, 8);
        if(choice == -1) {
            cout << "CANCELED" << endl;
            break;
        }

        Item* item = player->getItems().at(choice - 1);
        if(item->getAmount() == 0) {
            cout << "INSUFFICIENT AMOUNT." << endl << endl;
        }
        else {
            if(item->isPokeball()) {
                item->useItem();
                Pokeball* pokeball = dynamic_cast<Pokeball*>(item);
                useBall(wildPokemon, pokeball);
                playerTurnOver = true;
                return;
            }
            else if(item->isPotion()) {
                if(isTeamFullHP()) {
                    cout << "Your Pokemon are at full health!" << endl;
                    cout << "(1) BACK" << endl << endl;
                    cout << "SELECT OPTION: ";
                    choice = selectOptionHelper(1,1);
                    return;
                }
                else {
                    viewTeam(1);
                    cout << "(Enter CANCEL to cancel choice)" << endl << endl;
                    cout << "Select Pokemon to use " << item->getName() << " on: ";
                    choice = selectOptionHelper(1, 3);
                    if(choice == -1) {
                        cout << "CANCELED" << endl;
                        break;
                    }
    
                    Pokemon* pokemon = player->getTeam().at(choice-1);
                    while (pokemon->getHP() <= 0) {
                        cout << "CANNOT CHOOSE A FAINTED POKEMON, TRY AGAIN: ";
                        choice = selectOptionHelper(1, 3);
                        pokemon = player->getTeam().at(choice-1);
                    }
                    Potion* potion = dynamic_cast<Potion*>(item);
                    item->useItem();
                    usePotion(pokemon, potion);
                    playerTurnOver = true;
                    return;
                }
                
            }
            else if(item->isRevive()) {
                if(!hasFaintedPokemon()) {
                    cout << "You have no Pokemon to revive!" << endl;
                    cout << "(1) BACK" << endl << endl;
                    cout << "SELECT OPTION: ";
                    choice = selectOptionHelper(1,1);
                    if(choice == 1) {
                        flag = false;
                    }
                }
                else {
                    viewTeam(1);
                    cout << "(Enter CANCEL to cancel choice)" << endl << endl;
                    cout << "Select Pokemon to use " << item->getName() << " on: ";
                    choice = selectOptionHelper(1, 3);
                    if(choice == -1) {
                        cout << "CANCELED" << endl;
                        break;
                    }

                    Pokemon* pokemon = player->getTeam().at(choice-1);
                    while (pokemon->getHP() > 0) {
                        cout << "CAN ONLY CHOOSE A FAINTED POKEMON, TRY AGAIN: ";
                        choice = selectOptionHelper(1, 3);
                        pokemon = player->getTeam().at(choice-1);
                    }
                    
                    Revive* revive = dynamic_cast<Revive*>(item);
                    item->useItem();
                    useRevive(pokemon, revive);
                    playerTurnOver = true;
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

    sleep_for(1.5s);
    cout << ". . ." << endl << endl;
    sleep_for(1.5s);
    if(roll > chance * 3) {
        cout << "The Pokemon broke free!" << endl;
        return;
    }
    cout << ". . ." << endl << endl;
    sleep_for(1.5s);
    if(roll > chance * 1.5) {
        cout << "The Pokemon broke free!" << endl;
        return;
    }
    cout << ". . ." << endl << endl;
    sleep_for(1.5s);
    if(roll <= chance) {
        cout << "The wild " << wildPokemon->getName() << " was caught!" << endl << endl;
        sleep_for(1.5s);
        pokemonIsCaught = true;
        cout << wildPokemon->getName() << " has been added to your PC!" << endl << endl;
        wildPokemon->resetHPtoMax();


        Pokemon* newCaught = dynamic_cast<Pokemon*>(wildPokemon);
        player->getPC()->addPokemon(newCaught);
        return;
    }
    else {
        cout << "The Pokemon broke free!" << endl;
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
    sleep_for(2s);
    pokemon->addHP(pokemon->getMaxHP() * revive->getRestorePercent());
    cout << pokemon->getName() << " now has " << pokemon->getHP() << " HP!" << endl;
    cout << endl;
    sleep_for(2s);
}

void Battle::useReviveAfterLost() {
    int choice = 0;
    bool flag = true;
    player->displayRevives();
    cout << endl;
    while(flag) {
        cout << "(Enter CANCEL to cancel choice)" << endl << endl;
        cout << "Select revive to use: ";
        choice = selectOptionHelper(1, 2);
        if(choice == -1) {
            cout << "CANCELED" << endl;
            break;
        }
        Item* item = player->getItems().at(choice + 5);
        if(item->getAmount() == 0) {
            cout << "INSUFFICIENT AMOUNT." << endl << endl;
        }
        else {
            display->border2();
            viewTeam(1);
            cout << "(Enter CANCEL to cancel choice)" << endl << endl;
            cout << "Select Pokemon to use " << item->getName() << " on: ";
            choice = selectOptionHelper(1, 3);
            if(choice == -1) {
                cout << "CANCELED" << endl;
                break;
            }
            Pokemon* pokemon = player->getTeam().at(choice-1);
            Revive* revive = dynamic_cast<Revive*>(item);
            revive->useItem();
            useRevive(pokemon, revive);
            activePokemon = pokemon;
            playerTurnOver = true;
            return;
        }
    }
}


void Battle::viewEditTeam() {
    int choice = 0;
    bool flag = true;
    while(flag) {
        display->displayTeamScreen();
        viewTeam(1);
        cout << "Active Pokemon: " << activePokemon->getName() << endl;
        display->border2();
        cout << "Options: " << endl;
        cout << "(1) SWAP POKEMON" << endl;
        cout << "(2) VIEW STATS" << endl;
        cout << "(3) BACK" << endl << endl;
        cout << "SELECT OPTION: ";
        choice = selectOptionHelper(1,3);
        if(choice == 1) {
            editTeam();
            return;
        }
        if(choice == 2) {
            display->border();
            player->displayTeamStats();
            display->border2();
            cout << "Options: " << endl;
            cout << "(1) BACK" << endl << endl;
            cout << "SELECT OPTION: ";
            choice = selectOptionHelper(1,1);
        }
        else if(choice == 3) {
            flag = false;
        }
    }
}

void Battle::viewTeam(int option) {
    player->viewPokemonTeam(option);
}

void Battle::editTeam() {
    int choice = 0;
    bool flag = true;

    vector<Pokemon*>& team = player->getTeam();

    while(flag) {
        if(activePokemonLeft()) {
            cout << "You have no Pokemon to swap out!" << endl;
            cout << "(1) BACK" << endl << endl;
            cout << "SELECT OPTION: ";
            choice = selectOptionHelper(1,1);
            if(choice == 1) {
                flag = false;
            }
            return;
        }
        cout << "(Enter CANCEL to cancel choice)" << endl << endl;
        cout << "Select Pokemon to swap: ";
        choice = selectOptionHelper(1,3);
        if(choice == -1) {
            cout << "CANCELED" << endl;
            break;
        }

        Pokemon* pokemonToSwap = team.at(choice-1);
        while (pokemonToSwap->getHP() <= 0 || pokemonToSwap == activePokemon) {
            cout << "INVALID OPTION. TRY AGAIN: ";
            choice = selectOptionHelper(1, 3);
            if(choice == -1) {
                cout << "CANCELED" << endl;
                return;
            }
            pokemonToSwap = team.at(choice-1);
        }
        cout << activePokemon->getName() << ", switch out!" << endl << endl;

        swap(team[0], team[choice - 1]);
        
        activePokemon = team[0];
        
        sleep_for(1.0s);
        cout << "." << flush;
        sleep_for(0.50s);
        cout << " ."  << flush;
        sleep_for(0.50s);
        cout << " ." << endl << endl;
        sleep_for(1s);
        cout << pokemonToSwap->getName() << ", I choose you!" << endl << endl;
        sleep_for(2s);
        playerTurnOver = true;
        flag = false;
    }
}

void Battle::chooseMove() {
    int choice = 0;
    display->displayMovesScreen();
    Pokemon* wild = dynamic_cast<WildPokemon*>(wildPokemon);
    activePokemon->displayMoveset(wild);

    cout << endl;
    cout << "(Enter CANCEL to cancel choice)" << endl << endl;
    cout << "Select MOVE: ";
    choice = selectOptionHelper(1,3);
    if(choice == -1) {
        cout << "CANCELED" << endl;
        return;
    }
    Attack* move = activePokemon->getMoves().at(choice-1);

    sleep_for(1s);
    cout << activePokemon->getName() << " used " << move->getName() << "!" << endl << endl;
    sleep_for(0.50s);
    cout << "." << flush;
    sleep_for(0.50s);
    cout << " ."  << flush;
    sleep_for(0.50s);
    cout << " ." << endl << endl;
    sleep_for(1s);

    int damage = activePokemon->calculateDamage(move, activePokemon, wild);

    if(rand() % 10000 < 39) { // 0.39% miss chance
        if(move->getPower() <= 0) {
            cout << "The move failed!" << endl;
            playerTurnOver = true;
        }
        if(rand() % 2 == 0) {
            cout << "The attack missed!" << endl;
            playerTurnOver = true;
        }
        else {
            cout << "The wild " << wild->getName() << " dodged the attack!" << endl;
            playerTurnOver = true;
        }
        return;
    }

    if(rand() % 10000 < 625) { // 6.25% crit chance
        cout << "A critical hit!!" << endl << endl;
        damage *= 1.5;
    }

    cout << "The wild " << wild->getName() << " received " << damage << " damage!" << endl;
    displayEffectiveness(move, wild);
    wild->removeHP(damage); 
    if(wild->getHP() <= 0) {
        sleep_for(2s);
        cout << endl << "The wild " << wildPokemon->getName() << " has fainted!" << endl << endl;
        sleep_for(2s);
        return;
    }
    playerTurnOver = true;
    sleep_for(1.5s);
}

void Battle::displayEffectiveness(Attack* move, Pokemon* defender) {
    if(move->isSuperEffective(defender->getType())) {
        sleep_for(1.5s);
        cout << endl << move->getName() << " was Super Effective! " << endl;
    } 
    else if(move->isNotVeryEffective(defender->getType())) {
        sleep_for(1.5s);
        cout << endl << move->getName() << " was Not Very Effective! " << endl;
    }
}

bool Battle::allFaintedPokemon() const {
    int sum = 0;
    for (Pokemon* pokemon : player->getTeam()) {
        sum += pokemon->getHP();
    }
    return sum <= 0;
}

bool Battle::hasFaintedPokemon() const {
    for (Pokemon* pokemon : player->getTeam()) {
        if(pokemon->getHP() <= 0 ) {
            return true;
        }
    }
    return false;
}

bool Battle::activePokemonLeft() const {
    return player->getTeam().at(1)->getHP() == 0 && player->getTeam().at(2)->getHP() == 0;
}

bool Battle::isTeamFullHP() const {
    for (Pokemon* pokemon : player->getTeam()) {
        if(pokemon->getHP() != pokemon->getMaxHP()) {
            return false;
        }
    }
    return true;
}

void Battle::wildPokemonTurn() {
    display->border2();
    sleep_for(1s);
    cout << "The wild " << wildPokemon->getName() << " is about to move!" << endl << endl;
    sleep_for(1s);
    cout << "." << flush;
    sleep_for(0.50s);
    cout << " ."  << flush;
    sleep_for(0.50s);
    cout << " ." << endl << endl;

    Attack* move = wildPokemon->wildPokemonMove(activePokemon);
    sleep_for(1s);
    cout << "The wild " << wildPokemon->getName() << " used " << move->getName() << "!" << endl << endl;
    sleep_for(0.50s);
    cout << "." << flush;
    sleep_for(0.50s);
    cout << " ."  << flush;
    sleep_for(0.50s);
    cout << " ." << endl << endl;
    sleep_for(1s);

    int damage = wildPokemon->calculateDamage(move, wildPokemon, activePokemon);

    if(rand() % 10000 < 39) { // 0.39% miss chance
        if(move->getPower() == 0) {
            cout << "The move failed!" << endl;
            playerTurnOver = false;
        }
        if(rand() % 2 == 0) {
            cout << "The attack missed!" << endl;
            playerTurnOver = false;
        }
        else {
            cout << activePokemon->getName() << " dodged the attack!" << endl;
            playerTurnOver = false;
        }
        return;
    }

    if(rand() % 10000 < 625) { // 6.25% crit chance
        cout << "A critical hit!!" << endl << endl;
        damage *= 1.5;
    }
    
    cout << activePokemon->getName() << " received " << damage << " damage!" << endl;
    displayEffectiveness(move, activePokemon);
    activePokemon->removeHP(damage); 
    if(activePokemon->getHP() <= 0) {
        sleep_for(2s);
        cout << endl << activePokemon->getName() << " has fainted!" << endl << endl;
        sleep_for(2s);
        if(!allFaintedPokemon()) {
            display->border();
            viewTeam(1);
            editTeam();
            playerTurnOver = true;
        }
        return;
    }
    playerTurnOver = false;
    sleep_for(1.5s);
}

bool Battle::fleeSuccess() {
    static random_device rd;
    static mt19937 gen(rd());
    static bernoulli_distribution dist(0.5); // 50% chance
    sleep_for(0.75s);
    cout << "." << flush;
    sleep_for(0.75s);
    cout << " ."  << flush;
    sleep_for(0.75s);
    cout << " ." << endl << endl;
    sleep_for(1s);

    if(dist(gen)) {
        cout << "You got away safely!" << endl;
        sleep_for(2s);
        return true;
    } 
    else {
        cout << "You failed to escape!" << endl;
        sleep_for(2s);
        playerTurnOver = true;
        return false;
    }
}

void Battle::updateLoss() {
    for(int i = 0; i < 3; i++) {
        player->getTeam().at(i)->resetHPtoMax();
    }
}

void Battle::updateWin() {
    updateLoss();
    for(int i = 0; i < 3; i++) {
        player->getTeam().at(i)->addEXP(
            ( ( wildPokemon->getEXP() * wildPokemon->getLevel() ) / 7 ) * ownedByPlayer()
        );
    }
}

double Battle::ownedByPlayer() {
    const vector<Pokemon*>& owned = player->getTeamAndCaught();
    for (Pokemon* pokemon : owned) {
        if (pokemon->getSpecies() == wildPokemon->getSpecies()) {
            return 1.5;
        }
    }
    return 1.0;
}

int Battle::selectOptionHelper(int min, int max) {
    string input;
    int number;
    while (true) {
        cin >> input;
        cout << endl;

        if(input == "CANCEL") {
            return -1;
        }

        try {
            number = stoi(input); // if fails, throws exception to catch
        } catch (...) {
            cout << "INVALID OPTION. TRY AGAIN: ";
            continue;
        }

        if(number >= min && number <= max) {
            return number;
        } else {
            cout << "INVALID OPTION. TRY AGAIN: ";
        }
    }
}