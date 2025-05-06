#include "../header/Pokemon/attack.h"
#include "../header/Pokemon/moves.h"
#include "../header/Pokemon/pokemon.h"
#include "../header/Pokemon/pokemonSpecies.h"
#include "../header/Pokemon/type.h"
#include "../header/Pokemon/wildPokemon.h"
#include "../header/player/Player.h"
#include "../header/battle.h"
#include <iostream>

using namespace std;

int main() {
    Player* player = new Player();
    player->getStore()->setAllAmount(50);
    player->setTeamlevel(50);

    WildPokemon* wildPokemon = new WildPokemon(player);
    WildPokemon* Blastoise = new WildPokemon(PokemonSpecies::Blastoise, 100);
    WildPokemon* Ratata = new WildPokemon(PokemonSpecies::Rattata, 10);

    //Battle* battle = new Battle(player, wildPokemon);
    //Battle* battle = new Battle(player, Blastoise);
    Battle* battle = new Battle(player, Ratata);

    battle->initiateBattle();
    player->accessPC();
    player->accessStore();

    delete battle;
    delete Ratata;
    delete Blastoise;
    delete wildPokemon;
    delete player;
    
    return 0;
}