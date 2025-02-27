#include "../header/Pokeballs/StandardBall.h"
#include "../header/Pokeballs/GreatBall.h"
#include "../header/Pokeballs/UltraBall.h"
#include <iostream>

using namespace std;

int main() {
    // Create an array of Pokéballs
    Pokeball* balls[] = { new StandardBall(), new GreatBall(), new StandardBall() };

    // Use and display all Pokéballs
    for (Pokeball* ball : balls) {
        ball->useItem();            // Calls the correct useItem method
        ball->displayInfo(); // Calls the correct displayInformation method
        cout << endl;
    }

    return 0;
}