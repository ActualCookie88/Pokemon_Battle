#include "../header/Pokeballs/StandardBall.h"
#include "../header/Pokeballs/GreatBall.h"
#include "../header/Pokeballs/UltraBall.h"
#include <iostream>

using namespace std;

int main() {
    // Create an array of Pokéballs
    Pokeball* balls[] = { new StandardBall(), new GreatBall(), new UltraBall() };

    // Display all Pokéballs
    for(Pokeball* ball : balls) {
        ball->displayInfo();       
        cout << endl;
    }
    // Use all Pokeballs
    for(Pokeball* ball : balls) {
        ball->useItem();
        ball->catchPokemon(25);    // catch chance in %
        cout << endl;
    }

    return 0;
}