#include "../header/Revives/StandardRevive.h"
#include "../header/Revives/MaxRevive.h"
#include <iostream>

using namespace std;

int main() {
    // Create an array of Revives
    Revive* revives[] = { new StandardRevive(), new MaxRevive()};

    // Use and display all Revives
    for (Revive* revive : revives) {
        revive->displayInfo(); 
        cout << endl;
    }
    for (Revive* revive : revives) {
        revive->useItem();            
        cout << endl;
    }

    return 0;
}