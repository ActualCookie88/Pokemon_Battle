#include "../header/Revives/StandardRevive.h"
#include "../header/Revives/MaxRevive.h"
#include <iostream>

using namespace std;

int main() {
    StandardRevive standardRevive("Revives a fainted Pokémon and restores half its maximum HP.", 100);
    MaxRevive maxRevive("Revives a fainted Pokémon, fully restoring its HP.", 300);

    // Create an array of Revives
    Revive* revives[] = { &standardRevive, &maxRevive};

    // Use and display all Revives
    for (Revive* revive : revives) {
        revive->useItem();            // Calls the correct useItem method
        revive->displayInfo(); // Calls the correct displayInformation method
        cout << endl;
    }

    return 0;
}