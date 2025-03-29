#include "../../header/player/Player.h"
#include "../../header/player/PC.h"

Player::~Player() {
    for (Item* item : playerItems) {
        delete item;
    }
    playerItems.clear();
    
    delete myStore;
    delete myPC;
}

void Player::accessStore() {
    myStore->initiateStore();
}

void Player::accessPC() {
    myPC->initiatePC();
}

void Player::viewMyItems() {
    myStore->viewMyItems(true);
}

void Player::viewPokemonTeam() {
    myPC->viewPokemonTeam();
}