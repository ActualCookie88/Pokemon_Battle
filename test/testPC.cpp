#include <iostream>
#include "../header/player/Player.h"
#include "../header/Pokemon/pokemon.h"

using namespace std;

int main() {
    Player* player = new Player();
    PC* PC = player->getPC();
    PC->setTeamPokemon({
        new Pokemon(PokemonSpecies::Bulbasaur), 
        new Pokemon(PokemonSpecies::Charmander), 
        new Pokemon(PokemonSpecies::Squirtle)
    });
    PC->setCaughtPokemon({
        new Pokemon(PokemonSpecies::Venusaur), 
        new Pokemon(PokemonSpecies::Charizard), 
        new Pokemon(PokemonSpecies::Blastoise)
    });

    PC->displayTeamStats();

    player->accessPC();

    delete player;

    return 0;
}