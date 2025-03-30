#include "../header/player/Player.h"

int main() {
    Player* player = new Player();
    player->setTeamlevel(50);
    player->viewMyItems(false);
    player->viewPokemonTeam();
    player->displayTeamStats();

    cout << player->getMaxLevelPokemon() << endl;

    return 0;
}