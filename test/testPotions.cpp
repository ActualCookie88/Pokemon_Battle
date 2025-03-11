#include "../header/items/Potions/StandardPotion.h"
#include "../header/items/Potions/SuperPotion.h"
#include "../header/items/Potions/HyperPotion.h"
#include <iostream>

using namespace std;

int main() {
    // Create an array of Potions
    Potion* potions[] = { new StandardPotion(), new SuperPotion(), new HyperPotion()};

    // Use and display all Potions
    for (Potion* potion : potions) {          
        potion->displayInfo();         
        cout << endl;
    }
    for (Potion* potion : potions) {          
        potion->useItem(); 
        cout << endl; 
    }

    for (Potion* potion : potions) {          
        delete potion;
    }

    return 0;
}