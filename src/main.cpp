#include "../header/Pokeballs/StandardBall.h"
#include "../header/Pokeballs/GreatBall.h"
#include "../header/Pokeballs/UltraBall.h"
#include <iostream>

using namespace std;

int main() {
    StandardBall standardBall("A basic Pokéball for catching Pokémon.", 200);
    GreatBall greatBall("A great ball for catching wild Pokémon.", 600);
    UltraBall ultraBall("An ultra ball for better catching power.", 1200);

    // Create an array of Pokéballs
    Pokeball* balls[] = { &standardBall, &greatBall, &ultraBall };

    // Use and display all Pokéballs
    for (Pokeball* ball : balls) {
        ball->useItem();            // Calls the correct useItem method
        ball->displayInfo(); // Calls the correct displayInformation method
        cout << endl;
    }

    return 0;
}