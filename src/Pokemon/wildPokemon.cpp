#include "../../header/Pokemon/wildPokemon.h"
#include <cstdlib>
#include <ctime>

WildPokemon::WildPokemon(Player*& player) : Pokemon() {
    int maxLevel = player->getMaxLevelPokemon();
    static bool seeded = false;
    if (!seeded) {
        srand(time(0));  // Seed only once
        seeded = true;
    }

    int randomIndex = rand() % allPokemonSpecies.size();
    PokemonSpecies species = allPokemonSpecies[randomIndex];
    initializeStats(species);
    vector<Moves> selectedMoves = generateRandomMoves(getType());
    
    int levelVariation = (rand() % 11) - 5; 
    int finalLevel = max(1, min(maxLevel + levelVariation, 100));

    setMove1(new Attack(selectedMoves[0])); 
    setMove2(new Attack(selectedMoves[1])); 
    setMove3(new Attack(selectedMoves[2])); 
    
    setSpecies(species);
    setLevel(finalLevel);
}

Attack* WildPokemon::wildPokemonMove(Pokemon* opponent){
    int randomMoveIndex = rand() % 3; // Random index between 0 and 2

    switch (randomMoveIndex) {
        case 0:
            return getMove1();
        case 1:
            return getMove2();
        case 2:
            return getMove3();
        default:
            return getMove1();
    }
}

