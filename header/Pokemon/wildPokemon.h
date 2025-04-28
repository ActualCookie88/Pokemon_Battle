#pragma once
#include "pokemon.h"
#include "../player/Player.h"
class WildPokemon : public Pokemon {
    private:
        std::vector<PokemonSpecies> allPokemonSpecies = {
            PokemonSpecies::Bulbasaur, PokemonSpecies::Squirtle, PokemonSpecies::Charmander,
            PokemonSpecies::Pidgey, PokemonSpecies::Ivysaur, PokemonSpecies::Horsea, PokemonSpecies::Vulpix,
            PokemonSpecies::Rattata, PokemonSpecies::Venusaur, PokemonSpecies::Psyduck,
            PokemonSpecies::Growlithe, PokemonSpecies::Spearow, PokemonSpecies::Oddish,
            PokemonSpecies::Tentacool, PokemonSpecies::Ponyta, PokemonSpecies::Meowth,
            PokemonSpecies::Gloom, PokemonSpecies::Staryu, PokemonSpecies::Charmeleon,
            PokemonSpecies::Jigglypuff, PokemonSpecies::Vileplume, PokemonSpecies::Slowpoke,
            PokemonSpecies::Rapidash, PokemonSpecies::Farfetchd, PokemonSpecies::Paras,
            PokemonSpecies::Seel, PokemonSpecies::Magmar, PokemonSpecies::Raticate,
            PokemonSpecies::Parasect, PokemonSpecies::Wartortle, PokemonSpecies::Ninetales,
            PokemonSpecies::Fearow, PokemonSpecies::Bellsprout, PokemonSpecies::Dewgong,
            PokemonSpecies::Flareon, PokemonSpecies::Wigglytuff, PokemonSpecies::Weepinbell,
            PokemonSpecies::Blastoise, PokemonSpecies::Arcanine, PokemonSpecies::Persian,
            PokemonSpecies::Victreebel, PokemonSpecies::Lapras, PokemonSpecies::Charizard,
            PokemonSpecies::Kangaskhan, PokemonSpecies::Tangela, PokemonSpecies::Gyarados,
            PokemonSpecies::Moltres, PokemonSpecies::Snorlax
        };
        
    public:
        WildPokemon(Player*& player);
        WildPokemon(PokemonSpecies sp, int lvl);
        Attack* wildPokemonMove(Pokemon* opponent);
};