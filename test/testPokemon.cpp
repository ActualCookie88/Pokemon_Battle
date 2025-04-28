#include "../header/Pokemon/attack.h"
#include "../header/Pokemon/moves.h"
#include "../header/Pokemon/pokemon.h"
#include "../header/Pokemon/pokemonSpecies.h"
#include "../header/Pokemon/type.h"
#include "../header/Pokemon/wildPokemon.h"
#include <iostream>

using namespace std;

int main() {
    Pokemon* Charmander = new Pokemon(PokemonSpecies::Charmander);
    Pokemon* Bulbasaur = new Pokemon(PokemonSpecies::Bulbasaur);
    Pokemon* Squirtle = new Pokemon(PokemonSpecies::Squirtle);

    Charmander->displayInfo();
    cout << endl;
    Bulbasaur->displayInfo();
    cout << endl;
    Squirtle->displayInfo();
    cout << endl;
    
    cout << Charmander->calculateDamage(Charmander->getMove1(), Charmander, Bulbasaur) << endl;
    cout << Charmander->calculateDamage(Charmander->getMove2(), Charmander, Bulbasaur) << endl;
    cout << Charmander->calculateDamage(Charmander->getMove3(), Charmander, Bulbasaur) << endl;

    Attack* fireSpin = new Attack(Moves::FireSpin);

    if(fireSpin->isSuperEffective(Bulbasaur->getType())) {
        cout << fireSpin->getName() << " was Super Effective! " << endl;
    }
    if(fireSpin->isNotVeryEffective(Squirtle->getType())) {
        cout << fireSpin->getName() << " was Not Very Effective! " << endl;
    }
    cout << endl;

    Charmander->addEXP(100);
    cout << endl;
    Charmander->displayInfo();
    cout << endl;
    Charmander->displayMoveset(Bulbasaur);
    cout << endl;
    
    WildPokemon* victree = new WildPokemon(PokemonSpecies::Victreebel, 52);
    Charmander->setLevel(50);

    cout << Charmander->calculateDamage(fireSpin, Charmander, victree) << endl;

    delete victree;
    delete Charmander;
    delete Bulbasaur;
    delete Squirtle;
    delete fireSpin;
    return 0;
}