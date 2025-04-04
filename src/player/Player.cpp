#include "../../header/player/Player.h"
#include "../../header/player/PC.h"

Player::~Player() {
    for (Item* item : playerItems) {
        delete item;
    }
    for (Pokemon* pokemon : teamPokemon) {
        delete pokemon;
    }
    for (Pokemon* pokemon : caughtPokemon) {
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

void Player::viewMyItems(bool isViewing) {
    myStore->viewMyItems(isViewing);
}

void Player::viewPokemonTeam() {
    myPC->viewPokemonTeam();
}
void Player::displayTeamStats() {
    myPC->displayTeamStats();
}

vector<Item*> Player::getItems() const {
     return playerItems; 
}
vector<Pokemon*> Player::getTeam() { 
    return teamPokemon; 
}
vector<Pokemon*> Player::getCaught() { 
    return caughtPokemon; 
}
Store* Player::getStore() { 
    return myStore; 
}
PC* Player::getPC() { 
    return myPC; 
}
int Player::getMaxLevelPokemon() {
    int max = teamPokemon[0]->getLevel();
    for (const auto& pokemon : teamPokemon) {
        if(pokemon->getLevel() >= max) {
            max = pokemon->getLevel();
        }
    }
    return max;
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
    for (auto& pokemon : teamPokemon) {
        pokemon->setLevel(val);
    }
}