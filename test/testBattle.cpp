#include "../header/Pokemon/attack.h"
#include "../header/Pokemon/moves.h"
#include "../header/Pokemon/pokemon.h"
#include "../header/Pokemon/pokemonSpecies.h"
#include "../header/Pokemon/type.h"
#include "../header/Pokemon/wildPokemon.h"
#include "../header/player/Player.h"
#include "../header/player/battle.h"
#include <iostream>

using namespace std;

int main() {
    Player* player = new Player();
    WildPokemon* wildPokemon = new WildPokemon(player);

    Battle* battle = new Battle(player, wildPokemon);
    

    delete player;
    delete wildPokemon;
    return 0;
}