#include "../header/Potions/StandardPotion.h"
#include "../header/Potions/SuperPotion.h"
#include "../header/Potions/HyperPotion.h"
#include <iostream>

using namespace std;

int main() {
    StandardPotion standardPotion("A basic potion for healing.", 100);
    SuperPotion superPotion("A super potion for moderate healing.", 300);
    HyperPotion hyperPotion("A hyper potion for massive healing.", 600);

    // Create an array of Potions
    Potion* potions[] = { &standardPotion, &superPotion, &hyperPotion };

    // Use and display all Potions
    for (Potion* potion : potions) {
        potion->useItem();            // Calls the correct useItem method
        potion->displayInfo(); // Calls the correct displayInformation method
        cout << endl;
    }

    return 0;
}