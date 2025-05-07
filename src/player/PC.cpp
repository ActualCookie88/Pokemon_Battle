#include "../../header/player/PC.h"

#include <iostream>
#include <limits>

PC::~PC() {
}

void PC::initiatePC() {
    bool flag = true;
    int choice = 0;

    while (flag) {
        display->displayPCScreen();
        viewPokemonTeam();
        viewPokemonCaught();
        cout << "Options:" << endl;
        cout << "(1) VIEW STATS" << endl;
        cout << "(2) EDIT TEAM" << endl;
        cout << "(3) BACK" << endl;
        cout << endl;
        cout << "SELECT OPTION: ";

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


void PC::addPokemon(Pokemon* pokemon) {
    caughtPokemon.push_back(pokemon);
}

void PC::viewPokemonCaught() {
    cout << "PC:" << endl;
    if(caughtPokemon.size() <= 0) {
        cout << "You have no Pokemon in your PC!" << endl;
    }
    for (int i = 0; i < getCaughtPokemon().size(); i++) {
        cout << "(" << i + getTeamPokemon().size() + 1 << ") " << getCaughtPokemon().at(i)->getName();;
        cout << endl;
    }
    display->border2();
}

void PC::viewPokemonStats() {
    int i = 0;
    int choice = 0;
    bool flag = true;
    while(flag) {
        display->border();
        viewPokemonTeam();
        viewPokemonCaught();
        cout << "(Enter CANCEL to cancel)" << endl << endl;
        cout << "(Enter TEAM to view all TEAM stats)" << endl << endl;
        cout << "Select Pokemon: ";
        i = selectOptionHelper(1, getCaughtPokemon().size() + getTeamPokemon().size());
        cout << endl;
        if (i == -1) {
            cout << "CANCELED" << endl;
            break;
        }

        if (i == -2) {
            display->displayTeamScreen();
            displayTeamStats();
        }
        else {
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
        }
        display->border2();
        cout << "Options: " << endl;
        cout << "(1) VIEW MORE STATS" << endl;
        cout << "(2) BACK" << endl << endl;
        cout << "SELECT OPTION: ";
        choice = selectOptionHelper(1,2);
        if(choice == 2) {
            flag = false;
        }
    }
}

void PC::viewPokemonTeam() {
    cout << "TEAM:" << endl;
    for (int i = 0; i < getTeamPokemon().size(); i++) {
        cout << "(" << i + 1 << ") " << getTeamPokemon().at(i)->getName();
        cout << endl;
    }
    cout << endl;
}

void PC::editPokemonTeam() {
    int choice1 = 0, choice2 = 0, choice3 = 0;
    bool flag = true;

    if(caughtPokemon.size() <= 0) {
        display->border();
        cout << "You have no Pokemon in your PC to swap!" << endl << endl;
        display->border2();
        cout << "Options: " << endl;
        cout << "(1) BACK" << endl << endl;
        cout << "SELECT OPTION: ";
        choice3 = selectOptionHelper(1,1);
        return;
    }

    while(flag) {
        display->border();
        viewPokemonTeam();
        viewPokemonCaught();
        cout << "(Enter CANCEL to cancel swap)" << endl << endl;
        cout << "Select Pokemon in TEAM: ";
        choice1 = selectOptionHelper(1,3);
        if (choice1 == -1) {
            cout << "SWAP CANCELED" << endl;
            break;
        }
        cout << "Select Pokemon in PC: ";
        choice2 = selectOptionHelper(4, getCaughtPokemon().size() + getTeamPokemon().size());
        if (choice2 == -1) {
            cout << "SWAP CANCELED" << endl;
            break;
        }

        int caughtIndex = choice2 - getTeamPokemon().size() - 1; 
        Pokemon* pokemonInTeam = teamPokemon.at(choice1 - 1);
        Pokemon* pokemonInCaught = caughtPokemon.at(caughtIndex);

        teamPokemon.at(choice1 - 1) = pokemonInCaught;
        caughtPokemon.at(caughtIndex) = pokemonInTeam;

        display->border();
        cout << "SWAPPED (" << choice1 << ") " << pokemonInTeam->getName()
             << " AND (" << choice2 << ") " << pokemonInCaught->getName()
             << "!" << endl << endl;
        viewPokemonTeam();
        viewPokemonCaught();
        cout << "Options: " << endl;
        cout << "(1) EDIT AGAIN" << endl;
        cout << "(2) BACK" << endl << endl;
        cout << "SELECT OPTION: ";
        choice3 = selectOptionHelper(1,2);
        if(choice3 == 2) {
            flag = false;
        }
    }
}

void PC::displayTeamStats() {
    for (const auto& pokemon : teamPokemon) {
        pokemon->displayInfo();
        cout << endl;
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
    string input;
    int number;
    while (true) {
        cin >> input;
        cout << endl;

        if (input == "CANCEL") {
            return -1;
        }

        if (input == "TEAM") {
            return -2;
        }

        try {
            number = stoi(input); // if fails, throws exception to catch
        } catch (...) {
            cout << "INVALID OPTION. TRY AGAIN: ";
            continue;
        }

        if (number >= min && number <= max) {
            return number;
        } else {
            cout << "INVALID OPTION. TRY AGAIN: ";
        }
    }
}

int PC::validateInput(int input, int min, int max) {
    while (cin.fail() || input < min || input > max) {
        cout << "INVALID OPTION. TRY AGAIN: ";
        input = clearInputHelper();
    }
    return input;
}

void PC::setTeamAndCaught(vector<Pokemon*> team) {
    teamPokemon = team;
    caughtPokemon = team;
}