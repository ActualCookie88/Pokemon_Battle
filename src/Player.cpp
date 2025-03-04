#include "../header/Player.h"
#include "../header/PC.h"

void Player::accessStore() {
    myStore->initiateStore();
}

void Player::accessPC() {
    myPC->initiatePC();
}
