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