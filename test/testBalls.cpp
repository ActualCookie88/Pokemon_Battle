#include "../header/Pokeballs/StandardBall.h"
#include "../header/Pokeballs/GreatBall.h"
#include "../header/Pokeballs/UltraBall.h"
#include <iostream>

using namespace std;

int main() {
    int input = 0;
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
    
    Pokeball* ball = new StandardBall();
    cout << ball->getName() << endl;
    cout << "Amount: " << ball->getAmount() << endl;
    cout << "Enter amount to add: ";
    cin >> input;
    ball->addAmount(input);
    cout << "New Amount: " << ball->getAmount() << endl;

    for(Pokeball* ball : balls) {
        delete ball;
    }
    delete ball;

    return 0;
}