#include "../../header/Pokemon/wildPokemon.h"
#include <random>

WildPokemon::WildPokemon(Player*& player) : Pokemon() {
    int maxLevel = player->getMaxLevelPokemon();
    static mt19937 rng(random_device{}());
    
    int randomIndex = rng() % allPokemonSpecies.size();
    PokemonSpecies species = allPokemonSpecies[randomIndex];
    initializeStats(species);
    vector<Moves> selectedMoves = generateRandomMoves(getType());

    int baseCatchRate = getBaseCatchRate();
    double levelModifier = 1.0 - (baseCatchRate / 255.0);
    int variationRange = static_cast<int>(50 * levelModifier);

    uniform_int_distribution<int> levelOffsetDist(-variationRange / 2, variationRange / 2);
    int levelOffset = levelOffsetDist(rng);
    int finalLevel = max(1, std::min(maxLevel - levelOffset, 100));

    setMove1(new Attack(selectedMoves[0])); 
    setMove2(new Attack(selectedMoves[1])); 
    setMove3(new Attack(selectedMoves[2])); 
    
    setSpecies(species);
    setLevel(finalLevel);
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

