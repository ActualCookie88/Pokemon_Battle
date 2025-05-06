#include "../header/battle.h"
#include "../header/player/Player.h"
#include "../header/Pokemon/moves.h"
#include <iostream>
#include <limits>
#include <fstream>
#include <dirent.h>
#include <cstring>
#include <ctime>
using namespace std;

void displayFileOptions() {
    const char* directoryPath = ".";
    DIR* dir = opendir(directoryPath);
    if(dir == nullptr) {
        cerr << "Error opening directory." << endl;
        return;
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != nullptr) {
        // Check if the file is a regular file and ends with ".txt"
        if(entry->d_type == DT_REG && strstr(entry->d_name, ".txt") != nullptr) {
            string filename(entry->d_name);
            // Skip specific files that are not game save files
            if(filename != "CMakeLists.txt" && filename != "CMakeCache.txt") {
                cout << filename << endl;
            }
        }
    }
    closedir(dir);  // Close the directory after reading it.
}

bool loadGame(Player* myPlayer, const string& filename) {
    ifstream myFile(filename);
    if(!myFile) {
        cerr << "Error opening file!" << endl;
        return false;  // Return false if the file can't be opened.
    }

    string line;
    // Load Caught Pokemon
    while (getline(myFile, line) && line != "-----------") {
        string currSp = line;
        getline(myFile, line);
        int lvl = stoi(line);  // Convert string to int
        getline(myFile, line);
        int EXP = stoi(line);  // Convert string to int
        string move1Name, move2Name, move3Name;
        getline(myFile, move1Name);
        getline(myFile, move2Name);
        getline(myFile, move3Name);
        // Skip placeholder line
        getline(myFile, line); 
            }

    // Load Money
    if(getline(myFile, line)) {
        myPlayer->getStore()->setMoney(stoi(line));  // Set the player's money
    }

    // Load Inventory
    int i = 0;
    while (getline(myFile, line)) {
        if (i < myPlayer->getItems().size()) {
            int itemAmount = stoi(line);
            myPlayer->getItems().at(i)->addAmount(itemAmount);
            i++;
        }
    }

    myFile.close();  // Close the file after reading
    return true;  // Return true if the file was loaded successfully.
}

void saveGame(Player* myPlayer, const string& filename) {
    ofstream myFile(filename, ofstream::trunc);  // Open file with truncation mode to overwrite
    if(!myFile) {
        cerr << "Error creating file!" << endl;
        return;  // Exit if the file can't be created.
    }

    // Save Caught Pokemon to file
    for (const auto& myPokemon : myPlayer->getPC()->getCaughtPokemon()) {
        myFile << myPokemon->speciesToString(myPokemon->getSpecies()) << endl;
        myFile << myPokemon->getLevel() << endl;
        myFile << myPokemon->getEXP() << endl;
        myFile << myPokemon->getMove1()->getName() << endl;
        myFile << myPokemon->getMove2()->getName() << endl;
        myFile << myPokemon->getMove3()->getName() << endl;
        myFile << "..." << endl;
    }
    myFile << "-----------" << endl;  // Marker for the end of Pokemon data
    myFile << myPlayer->getStore()->getMoney() << endl;  // Save money
    // Save inventory items
    for (const auto& item : myPlayer->getItems()) {
        myFile << item->getAmount() << endl;
    }
    myFile.close();  // Close the file after writing
    cout << "File created and saved successfully." << endl;
}

int clearInputHelper() {
    int choice = 0;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin >> choice;
    cout << endl;
    return choice;
}

int selectOptionHelper(int min, int max) {
    string input;
    int number;
    while (true) {
        cin >> input;
        cout << endl;

        if(input == "CANCEL") {
            return -1;
        }

        try {
            number = stoi(input);  // string to int
        } catch (...) {
            cout << "INVALID OPTION. TRY AGAIN: ";
            continue;
        }

        if(number >= min && number <= max) {
            return number;
        } else {
            cout << "INVALID OPTION. TRY AGAIN: ";
        }
    }
}

int main() {
    srand(time(0));  // Seed the random number generator
    bool isLoaded = false;
    Player* myPlayer = new Player();
    Display* display = myPlayer->getDisplay();
    display->displayStartScreen();  // Display the start screen

    string filename; 
    
    while (true) {
        cout << "SELECT OPTION: ";
        int choice = selectOptionHelper(1, 2);  // Get user input for game choice

        if(choice == 1) {
            break;  // Exit if the user chooses option 1
        } else if(choice == 2) {
            cout << "Enter filename: ";
            displayFileOptions();  // Display available game files

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            string filename;
            getline(cin, filename);  // Get the filename from user input

            // Attempt to load the game from the selected file
            if (loadGame(myPlayer, filename)) {
                cout << "Game loaded successfully!" << endl;
                isLoaded = true;
                break;
            } else {
                cout << "Failed to load game. Try again.\n";
            }
        } else {
            cout << "\nInvalid Input\n" << endl;
        }
    }

    if (isLoaded) {
        cout << "Saving loaded game..." << endl;
        saveGame(myPlayer, filename);
    } else {
        cout << "Enter filename to save: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, filename);
        if (filename.find(".txt") == string::npos) {
            filename += ".txt";
        }
        saveGame(myPlayer, filename);
    }

    delete myPlayer;  // Free memory allocated for the player
    return 0;  // Exit program
}