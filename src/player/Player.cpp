#include "../../header/player/Player.h"
#include "../../header/player/PC.h"

Player::~Player() {
    for(Item* item : playerItems) {
        delete item;
    }
    for(Pokemon* pokemon : teamPokemon) {
        delete pokemon;
    }
    for(Pokemon* pokemon : caughtPokemon) {
        delete pokemon;
    }
    
    delete myStore;
    delete myPC;
}

void Player::accessStore() {
    myStore->initiateStore();
}

void Player::accessPC() {
    myPC->initiatePC();
}

void Player::initiateAll(int auth) { // start player w/ money and items
    if(auth == 0) { // default
        setTeamlevel(5);
        playerItems.at(0)->setAmount(5);
        playerItems.at(3)->setAmount(5);
        playerItems.at(6)->setAmount(5);
        myStore->setMoney(500);
    }
    else if(auth == 1) { // for admin
        setTeamlevel(100);
        myStore->setAllAmount(100);
        myStore->setMoney(100000);
    }
    else if(auth == 2) { // for admin
        setTeamlevel(10);
        myStore->setAllAmount(100);
        myStore->setMoney(100000);
    }
}

void Player::addTeamPokemon(Pokemon* p) {
    if((int)teamPokemon.size() < 3) {
                teamPokemon.push_back(p);
    } 
    else {
        // If team full, add to caught
        caughtPokemon.push_back(p);
    }
}
void Player::addCaughtPokemon(Pokemon* p) {
    caughtPokemon.push_back(p);
}

bool Player::hasRevives() {
    int sum = 0;
    sum += playerItems.at(6)->getAmount() + playerItems.at(7)->getAmount();
    return sum > 0;
}

void Player::displayRevives() {
    cout << "(1) ";
    playerItems.at(6)->displayInfo2();
    cout << endl;
    cout << "(2) ";
    playerItems.at(7)->displayInfo2();
}

void Player::viewMyItems(bool isViewing) {
    myStore->viewMyItems(isViewing);
}

void Player::viewItemStats(int itemNum) {
    myStore->viewItemStats(itemNum);
}

void Player::viewPokemonTeam(int option) {
    if(option == 0) {
        display->displayTeamScreen();
        cout << "Pokemon in your Team:" << endl;
    }
    for(int i = 0; i < teamPokemon.size(); i++) {
        cout << "(" << i + 1 << ") " << teamPokemon.at(i)->getName();
        if(option == 1) {
            cout << "( HP: " << teamPokemon.at(i)->getHP() << " / " << teamPokemon.at(i)->getMaxHP() << " )";
        }
        cout << endl;
    }
    cout << endl;
}

void Player::displayTeamStats() {
    myPC->displayTeamStats();
}

vector<Item*>& Player::getItems() {
     return playerItems; 
}
vector<Pokemon*>& Player::getTeam() { 
    return teamPokemon; 
}
vector<Pokemon*>& Player::getCaught() { 
    return caughtPokemon; 
}
vector<Pokemon*> Player::getTeamAndCaught() {
    vector<Pokemon*> teamAndCaught;
    for(int i = 0; i < teamPokemon.size(); i++) {
        teamAndCaught.push_back(teamPokemon.at(i));
    }
    for(int i = 0; i < caughtPokemon.size(); i++) {
        teamAndCaught.push_back(caughtPokemon.at(i));
    }
    
    return teamAndCaught;
}
Store* Player::getStore() { 
    return myStore; 
}
PC* Player::getPC() { 
    return myPC; 
}
Display* Player::getDisplay() {
    return display;
}

int Player::getMaxLevelPokemon() {
    int max = teamPokemon[0]->getLevel();
    for(const auto& pokemon : teamPokemon) {
        if(pokemon->getLevel() >= max) {
            max = pokemon->getLevel();
        }
    }
    return max;
}
int Player::getAVGLevelPokemon() {
    int sum = 0;
    for(const auto& pokemon : teamPokemon) {
        sum += pokemon->getLevel();
    }
    return sum / 3;
}

int Player::getTotalPokemon() {
    return caughtPokemon.size() + 3;
}

void Player::setItems(vector<Item*> items) { 
    playerItems = items; 
}
void Player::setStore(Store* store) {  
    myStore = store; 
}
void Player::setPC(PC* pc) { 
    myPC = pc; 
}
void Player::setTeamlevel(int val) {
    for(auto& pokemon : teamPokemon) {
        pokemon->setLevel(val);
    }
}