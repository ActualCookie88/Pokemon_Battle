#include "../header/Pokemon/attack.h"
#include "../header/Pokemon/moves.h"
#include "../header/Pokemon/pokemon.h"
#include "../header/Pokemon/pokemonSpecies.h"
#include "../header/Pokemon/type.h"
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

    Attack* fireSpin = new Attack(Moves::FireSpin);

    if(fireSpin->isSuperEffective(Bulbasaur->getType())) {
        cout << fireSpin->getName() << " was Super Effective! " << endl;
    }
    if(fireSpin->isNotVeryEffective(Squirtle->getType())) {
        cout << fireSpin->getName() << " was Not Very Effective! " << endl;
    }
    

    /*
    Pokemon* pokemons[] = { attacker, defender };
    for (Pokemon* pokemon : pokemons) { 
        cout << "Species: " << pokemon->speciesToString(pokemon->getSpecies()) << endl;
        cout << "Type: " << pokemon->typeToString(pokemon->getType()) << endl;
        cout << "Health: " <<  pokemon->gethp() << endl;
        cout << "Attack: " <<  pokemon->getAttack() << endl;
        cout << "Defense: " <<  pokemon->getDefense() << endl;
        cout << "Level: " << pokemon->getLevel() << endl;
        cout << "Exp: " << pokemon->getEXP() << endl;
        cout << "Moves: " << endl;
        cout << " " << pokemon->getMove1()->getName() << endl;
        cout << " " <<  pokemon->getMove2()->getName() << endl;
        cout << " " <<  pokemon->getMove3()->getName() << endl << endl;
        
    }
    */
    
}