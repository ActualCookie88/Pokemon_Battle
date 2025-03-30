#include "../header/Pokemon/attack.h"
#include "../header/Pokemon/moves.h"
#include "../header/Pokemon/pokemon.h"
#include "../header/Pokemon/pokemonSpecies.h"
#include "../header/Pokemon/type.h"
#include "../header/Pokemon/wildPokemon.h"
#include "../header/player/Player.h"
#include <iostream>

using namespace std;

int main() {
    Player* player = new Player();
    WildPokemon* wild = new WildPokemon(player);

    wild->displayInfo();
    cout << endl;

    cout << wild->wildPokemonMove(wild)->getName() << endl;

}