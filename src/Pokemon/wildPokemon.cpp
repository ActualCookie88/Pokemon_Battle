#include "../../header/Pokemon/wildPokemon.h"
#include <random>

WildPokemon::WildPokemon(Player*& player) : Pokemon() {
    int maxLevel = player->getMaxLevelPokemon();
    int avgLevel = player->getAVGLevelPokemon();
    int newMaxLevel = max(maxLevel, avgLevel);   

    static mt19937 rng(random_device{}());
    
    int randomIndex = rng() % allPokemonSpecies.size();
    PokemonSpecies species = allPokemonSpecies[randomIndex];
    initializeStats(species);
    vector<Moves> selectedMoves = generateRandomMoves(getType());

    int baseCatchRate = getBaseCatchRate();

    if (baseCatchRate < 5) baseCatchRate = 3;
    if (baseCatchRate > 255) baseCatchRate = 255;

    if (newMaxLevel < 1) newMaxLevel = 1;
    if (newMaxLevel > 100) newMaxLevel = 100;

    double minScale, maxScale;
    if (baseCatchRate <= 50) { // rare
        minScale = 1.0;
        maxScale = 1.2;
    } else if (baseCatchRate <= 150) { // uncommon
        minScale = 0.8;
        maxScale = 1.0;
    } else { // common
        minScale = 0.7;
        maxScale = 0.9;
    }

    // random base scaling
    uniform_real_distribution<> baseDist(minScale, maxScale);
    int baseLevel = static_cast<int>(maxLevel * baseDist(rng));

    // random (+-2 levels)
    uniform_int_distribution<> smallAdjustment(-2, 2);
    baseLevel += smallAdjustment(rng);

    if (baseLevel < 5) baseLevel = 5;
    if (baseLevel > 100) baseLevel = 100;

    setMove1(new Attack(selectedMoves[0])); 
    setMove2(new Attack(selectedMoves[1])); 
    setMove3(new Attack(selectedMoves[2])); 
    
    setSpecies(species);
    setLevel(baseLevel);
}

WildPokemon::WildPokemon(PokemonSpecies sp, int lvl) {
    setSpecies(sp);
    setLevel(lvl);
    setEXP(0);
    initializeStats(sp);
    vector<Moves> selectedMoves = generateRandomMoves(getType());
    // Initialize Moves
    setMove1(new Attack(selectedMoves[0])); 
    setMove2(new Attack(selectedMoves[1]));
    setMove3(new Attack(selectedMoves[2])); 
}

Attack* WildPokemon::wildPokemonMove(Pokemon* opponent) {
    static mt19937 rng(random_device{}()); // Better random engine
    uniform_int_distribution<int> moveDist(0, 2); // Ensures a uniform choice between 0 and 2

    int randomMoveIndex = moveDist(rng);

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

