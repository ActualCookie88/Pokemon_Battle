#include "../header/player/Player.h"

int main() {
    Player* player = new Player();
    player->setTeamlevel(50);
    player->viewMyItems(false);
    player->viewPokemonTeam();
    player->displayTeamStats();

    

    return 0;
}