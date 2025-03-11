#include <iostream>
#include "../header/player/Player.h"

using namespace std;

int main() {
    Player* player = new Player();
    player->getStore()->setMoney(10000);
    player->accessStore();

    delete player;
    
    return 0;
}