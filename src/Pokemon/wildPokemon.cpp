#include "../../header/Pokemon/wildPokemon.h"

WildPokemon::WildPokemon(int area){
    int randomIndex = rand() % allPokemonSpecies.size();
    PokemonSpecies species = allPokemonSpecies[randomIndex/3*area];
    initializeStats(species);
    setBaseHP(getBaseHP()*1.5);
    setBaseAttack(getBaseAttack()*1.5);
    setBaseDefense(getBaseDefense()*1.5);
    int randomLevel = 5 + rand() % 10;
    for(int i=0;i<randomLevel;i++){
        addLevel();
    }
}

Attack* WildPokemon::wildPokemonMove(Pokemon& opponent){
    Pokemon dummy =Pokemon();
    dummy = opponent;
    int move1Damage=dummy.getMove1()->calculateDamage(dummy, opponent);
    int max = move1Damage;
    int move2Damage=dummy.getMove2()->calculateDamage(dummy, opponent);
    int move3Damage=dummy.getMove3()->calculateDamage(dummy, opponent);
    if(move2Damage >max){
        max = dummy.getMove2()->calculateDamage(dummy, opponent);
    }
    if(move3Damage >max){
        max = dummy.getMove3()->calculateDamage(dummy, opponent);
    }
    if(move1Damage==max){
        return dummy.getMove1();
    }
    else if(move2Damage==max){
        return dummy.getMove2();
    }
    else{
        return dummy.getMove3();
    }
}

