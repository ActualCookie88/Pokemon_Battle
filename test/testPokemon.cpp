#include "../header/Pokemon/attack.h"
#include "../header/Pokemon/moves.h"
#include "../header/Pokemon/pokemon.h"
#include "../header/Pokemon/pokemonSpecies.h"
#include "../header/Pokemon/pokemonType.h"
#include <iostream>

using namespace std;

int main() {
    Pokemon* attacker = new Pokemon(PokemonSpecies::Charmander);
    Pokemon* defender = new Pokemon(PokemonSpecies::Bulbasaur);
    Pokemon* pokemons[] = { attacker, defender };

    for (Pokemon* pokemon : pokemons) { 
        cout << "Species: " << pokemon->speciesToString(pokemon->getSpecies()) << endl;
        cout << "Type: " << pokemon->typeToString(pokemon->getType()) << endl;
        cout << "Health: " <<  pokemon->gethp() << endl;
        cout << "Attack: " <<  pokemon->getAttack() << endl;
        cout << "Defense: " <<  pokemon->getDefense() << endl;
        cout << "Level: " << pokemon->getLevel() << endl;
        cout << "Moves: " << endl;
        cout << " " << pokemon->getMove1()->getName() << endl;
        cout << " " <<  pokemon->getMove2()->getName() << endl;
        cout << " " <<  pokemon->getMove3()->getName() << endl << endl;
        
    }

    cout << attacker->calculateDamage(attacker->getMove1(), attacker, defender) << endl;


}