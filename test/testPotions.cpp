#include "../header/Potions/StandardPotion.h"
#include "../header/Potions/SuperPotion.h"
#include "../header/Potions/HyperPotion.h"
#include <iostream>

using namespace std;

int main() {
    // Create an array of Potions
    Potion* potions[] = { new StandardPotion(), new SuperPotion(), new HyperPotion()};

    // Use and display all Potions
    for (Potion* potion : potions) {
        potion->useItem();            // Calls the correct useItem method
        potion->displayInfo(); // Calls the correct displayInformation method
        cout << endl;
    }

    return 0;
}