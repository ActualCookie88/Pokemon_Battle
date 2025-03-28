#include "../header/Pokemon/attack.h"
#include "../header/Pokemon/moves.h"
#include "../header/Pokemon/pokemon.h"
#include "../header/Pokemon/pokemonSpecies.h"
#include "../header/Pokemon/type.h"
#include "../header/Pokemon/wildPokemon.h"
#include <iostream>

using namespace std;

int main() {
    WildPokemon* wild = new WildPokemon(50);

    wild->displayInfo();
    cout << endl;

    delete wild;
}