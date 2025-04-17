#include "../../header/Pokemon/wildPokemon.h"
#include <random>

WildPokemon::WildPokemon(Player*& player) : Pokemon() {
    int perc = 0;
    int diff = 0;
    int maxLevel = player->getMaxLevelPokemon();
    static std::mt19937 rng(std::random_device{}());
    
    int randomIndex = rng() % allPokemonSpecies.size();
    PokemonSpecies species = allPokemonSpecies[randomIndex];
    initializeStats(species);
    vector<Moves> selectedMoves = generateRandomMoves(getType());

    int baseCatchRate = getBaseCatchRate();
    int variationRange = 0;

    if(baseCatchRate >= 190) {
        variationRange = 10;
    } 
    else if(baseCatchRate >= 75) {
        variationRange = 25;
    } 
    else if(baseCatchRate >= 25) {
        variationRange = 50;
    } 
    else if(baseCatchRate >= 3) {
        variationRange = 100;
    } 

    uniform_int_distribution<int> levelOffsetDist(-(variationRange / 2), variationRange / 2);
    int levelOffset = levelOffsetDist(rng);
    int finalLevel = max(1, min(maxLevel + levelOffset, 100));

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

