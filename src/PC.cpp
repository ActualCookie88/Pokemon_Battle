#include "../header/PC.h"
#include "../header/Display.h"
#include <iostream>
#include <limits>

void PC::initiatePC() {
    bool flag = true;
    int choice;
    Display* display;

    while (flag) {
        display->displayPCScreen();
        if (getCaughtPokemon().empty()) {
            cout << "You have no Pokemon in your PC!" << endl;
            cout << "Options: " << endl;
            flag = selectOptionHelper2();
            return;
        } 
        viewPokemonTeam();
        viewPokemonCaught();
        cout << "Options:" << endl;
        cout << "(1) View Pokemon stats" << endl;
        cout << "(2) View/Edit Pokemon Team" << endl;
        cout << "(3) Go Back" << endl;
        cout << endl;
        cout << "Select an option: ";

        cin >> choice;
        cout << endl;
                
        while (cin.fail() || choice < 1 || choice > 3) {
            cout << "INVALID OPTION. TRY AGAIN: ";
            choice = clearInputHelper();
        }
        if (choice == 1) {
            viewPokemonStats();
        }
        else if (choice == 2) {
            viewPokemonTeam();
        }
        else if (choice == 3) {
            flag = false;
        }
    }
}

void PC::viewPokemonCaught() {
    cout << "Pokemon in your PC:" << endl;
    for (int i = 0; i < getCaughtPokemon().size(); i++) {
        cout << "(" << i + getTeamPokemon().size() + 1 << ") " << getCaughtPokemon().at(i)->speciesToString(getCaughtPokemon().at(i)->getSpecies());
        cout << endl;
    }
    cout << endl;
}

void PC::addPokemon(Pokemon* pokemon) {
    caughtPokemon.push_back(pokemon);
}

void PC::viewPokemonStats() {
    int i = 0;
    bool flag = true;

    while(flag) {
        viewPokemonTeam();
        viewPokemonCaught();
        cout << "Enter Pokemon's number to view stats: ";
        i = selectOptionHelper3();
        cout << endl;

        if(i > getCaughtPokemon().size() + getTeamPokemon().size()) {
            return;
        }
        if (i > 0 && i <= 3) {
            getTeamPokemon().at(i-1)->displayInfo();
        }
        if (i > 3 && i <= getCaughtPokemon().size() + getTeamPokemon().size()) {
            getCaughtPokemon().at(i-4)->displayInfo();
        }
        cout << endl;
        
        cout << "Options: " << endl;
        cout << "(1) View another Pokemon's stats" << endl;
        flag = selectOptionHelper1();
        
    }
}

void PC::viewPokemonTeam() {
    cout << "Pokemon in your Team:" << endl;
    for (int i = 0; i < getTeamPokemon().size(); i++) {
        cout << "(" << i + 1 << ") " << getTeamPokemon().at(i)->speciesToString(getTeamPokemon().at(i)->getSpecies());
        cout << endl;
    }
    cout << endl;
}

void PC::editPokemonTeam() {
    cout << "Currently owned Pokemon:" << endl;
    // Display all caught Pokemon
    for (int i = 0; i < getCaughtPokemon().size(); ++i) {
        cout << i + 1 << ". ";
        getCaughtPokemon().at(i)->displayInfo();
        cout << endl;
    }

    cout << endl;
    cout << "Select 3 Pokemon you want on your team:" << endl;
    vector<Pokemon*> selectedTeam;
    int choice;

    while (selectedTeam.size() < 3) {
        cout << "Enter the number of the Pokemon you want to add to your team (1-" << getCaughtPokemon().size() << "): ";
        cin >> choice;

        // Validate the input
        if (cin && choice > 0 && choice <= getCaughtPokemon().size()) {
            // Check if the Pokemon is already in the team
            bool alreadyInTeam = false;
            for (auto* pokemon : selectedTeam) {
                if (pokemon == getCaughtPokemon()[choice - 1]) {
                    alreadyInTeam = true;
                    break;
                }
            }

            if (!alreadyInTeam) {
                selectedTeam.push_back(getCaughtPokemon()[choice - 1]);
                cout << "Added " << getCaughtPokemon().at(choice - 1)->speciesToString(getCaughtPokemon().at(choice - 1)->getSpecies()) << " to your team." << endl;
            } else {
                cout << "This Pokemon is already in your team. Choose a different one." << endl;
            }
        } else {
            cout << "Invalid input. Please enter a valid Pokemon number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    // Now directly update the actual team
    selectedTeam = selectedTeam; // This line is redundant but ensures clarity.

    // Display the updated team
    cout << "Your team has been replaced! Here is your new team:" << endl;
    for (int i = 0; i < selectedTeam.size(); ++i) {
        cout << i + 1 << ". ";
        selectedTeam.at(i)->displayInfo();
        cout << endl;
    }
}

int PC::clearInputHelper() {
    int i = 0;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin >> i;
    //--i;
    cout << endl;

    return i;
}

bool PC::selectOptionHelper1() {
    bool flag = true;
    int i = 0;
    cout << "(2) Go Back" << endl << endl;
    cout << "Select an option: ";

    cin >> i;
    cout << endl; 

    while (cin.fail() || i < 1 || i > 2) {
        cout << "INVALID OPTION. TRY AGAIN: ";
        i = clearInputHelper();
    }

    if (i == 2) {
        flag = false;
    }

    return flag;
}

bool PC::selectOptionHelper2() {
    bool flag = true;
    int i = 0;
    cout << "(1) Go Back" << endl << endl;
    cout << "Select an option: ";

    cin >> i;
    cout << endl; 

    while (cin.fail() || i != 1) {
        cout << "INVALID OPTION. TRY AGAIN: ";
        i = clearInputHelper();
    }

    if (i == 1) {
        flag = false;
    }

    return flag;
}

int PC::selectOptionHelper3() {
    int i = 0;

    if(cin >> i) {
        //--i;
        cout << endl;
    }

    while (cin.fail() || i < 0 || i > getCaughtPokemon().size() + getTeamPokemon().size()) {
        cout << "INVALID OPTION. TRY AGAIN: ";
        i = clearInputHelper();
    }

    return i;
}