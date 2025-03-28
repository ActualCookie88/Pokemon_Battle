#include "../../header/player/PC.h"

#include <iostream>
#include <limits>

PC::~PC() {
    for (Pokemon* p : teamPokemon) {
        delete p;
    }
    for (Pokemon* p : caughtPokemon) {
        delete p;
    }
}

void PC::initiatePC() {
    bool flag = true;
    int choice;

    while (flag) {
        display->displayPCScreen();
        if (getCaughtPokemon().empty()) {
            cout << "You have no Pokemon in your PC!" << endl;
            cout << "Options: " << endl;
            flag = selectOptionHelper(1,1);
            delete display;
            return;
        } 
        viewPokemonTeam();
        viewPokemonCaught();
        cout << "Options:" << endl;
        cout << "(1) View Pokemon stats" << endl;
        cout << "(2) Edit Pokemon Team" << endl;
        cout << "(3) Go Back" << endl;
        cout << endl;
        cout << "Select an option: ";

        cin >> choice;
        cout << endl;
                
        choice = validateInput(choice, 1, 3);

        if (choice == 1) {
            viewPokemonStats();
        }
        else if (choice == 2) {
            editPokemonTeam();
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
    int choice = 0;
    bool flag = true;
    while(flag) {
        display->border();
        viewPokemonTeam();
        viewPokemonCaught();
        cout << "Enter Pokemon's number to view stats: ";
        i = selectOptionHelper(1, getCaughtPokemon().size() + getTeamPokemon().size());
        cout << endl;
        display->border();

        if(i > getCaughtPokemon().size() + getTeamPokemon().size() || i <= 0) {
            return;
        }
        if (i <= getTeamPokemon().size()) {
            getTeamPokemon().at(i-1)->displayInfo();
        }
        else {
            getCaughtPokemon().at(i - getTeamPokemon().size() - 1)->displayInfo();
        }
        cout << endl;
        
        cout << "Options: " << endl;
        cout << "(1) View another Pokemon's stats" << endl;
        cout << "(2) Go back" << endl;
        cout << "Select option: ";
        choice = selectOptionHelper(1,2);
        if(choice == 2) {
            flag = false;
        }
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
    int choice1, choice2, choice3 = 0;
    bool flag = true;

    while(flag) {
        display->border();
        viewPokemonTeam();
        viewPokemonCaught();

        cout << "Enter number of Pokemon in Team to switch: ";
        choice1 = selectOptionHelper(1,3);
        cout << "Enter number of Pokemon in PC to switch: ";
        choice2 = selectOptionHelper(4, getCaughtPokemon().size() + getTeamPokemon().size());

        int caughtIndex = choice2 - getTeamPokemon().size() - 1; 
        Pokemon* pokemonInTeam = teamPokemon.at(choice1 - 1);
        Pokemon* pokemonInCaught = caughtPokemon.at(caughtIndex);

        teamPokemon.at(choice1 - 1) = pokemonInCaught;
        caughtPokemon.at(caughtIndex) = pokemonInTeam;

        display->border();
        cout << "SWAPPED (" << choice1 << ") " << pokemonInTeam->speciesToString(pokemonInTeam->getSpecies())
             << " AND (" << choice2 << ") " << pokemonInCaught->speciesToString(pokemonInCaught->getSpecies())
             << "!" << endl << endl;
        viewPokemonTeam();
        viewPokemonCaught();

        cout << "Options: " << endl;
        cout << "(1) Edit Pokemon Team again" << endl;
        cout << "(2) Go back" << endl << endl;
        cout << "Select option: ";
        choice3 = selectOptionHelper(1,2);
        if(choice3 == 2) {
            flag = false;
        }
    }
}


int PC::clearInputHelper() {
    int i = 0;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin >> i;
    cout << endl;
    return i;
}

int PC::selectOptionHelper(int min, int max) {
    int i = 0;
    cin >> i;
    cout << endl;
    return validateInput(i, min, max);
}

int PC::validateInput(int input, int min, int max) {
    while (cin.fail() || input < min || input > max) {
        cout << "INVALID OPTION. TRY AGAIN: ";
        input = clearInputHelper();
    }
    return input;
}
