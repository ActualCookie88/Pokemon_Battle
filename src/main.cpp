#include "../header/battle.h"
#include <iostream>
#include <limits>
#include <fstream>
#include <dirent.h>
#include <cstring>
#include "../header/player/Player.h"
using namespace std;

int main() {
    srand(time(0));
    ifstream inFS;
    string filename;
    int choice;
    bool isLoaded = false;
    Player* myPlayer = new Player();
    Display* display;
    display->displayStartScreen();
    
    while (true)
    {
        cout << endl;
        cout << "Select an option: ";
        cin >> choice;
        cout << endl;


        if (choice == 1) {
            break;
        }

        else if (choice == 2) {
            cout << "What game do you want to load?" << endl << endl;
             const char* directoryPath = ".";


            DIR* dir = opendir(directoryPath);
            if (dir == nullptr) {
                cerr << "Error opening directory." << endl;
                delete myPlayer;
                return 1;
            }


            struct dirent* entry;
            while ((entry = readdir(dir)) != nullptr) {
                if (entry->d_type == DT_REG && strstr(entry->d_name, ".txt") != nullptr) {
                    if (strcmp(entry->d_name, "CMakeLists.txt") == 0 || strcmp(entry->d_name, "CMakeCache.txt") == 0) {
                        continue; // Skip these files
                    }
                    cout << entry->d_name << endl;  
                }
            }


            closedir(dir);
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, filename);
            ifstream myFile(filename);
    if (!myFile) {
        cerr << "Error opening file!" << endl;
        delete myPlayer;
        return 1;
    }

    string line;

    // Load Caught Pokemon
    while (getline(myFile, line) && line != "-----------") {
        string currSp= line;
        getline(myFile, line);
        int lvl = stoi(line);
        getline(myFile, line);
        int EXP = stoi(line);
        getline(myFile,line);
        int iv = stoi(line);
        string move1Name, move2Name, move3Name;
        getline(myFile, move1Name);
        getline(myFile, move2Name);
        getline(myFile, move3Name);
        Pokemon* currPokemon = new Pokemon(currPokemon->stringToSpecies(currSp), lvl, EXP, currPokemon->stringToMove(move1Name), 
                                            currPokemon->stringToMove(move2Name), currPokemon->stringToMove(move3Name));

        // Skip placeholder line
        getline(myFile, line); 
        
        myPlayer->getPC()->addPokemon(currPokemon);
    }

    // Load Money
    if (getline(myFile, line)) {
        myPlayer->getStore()->setMoney(stoi(line));
    }

    // Load Inventory
    int i=0;
    while (getline(myFile, line)) {
        int itemAmount = stoi(line);
        myPlayer->getItems().at(i)->addAmount(itemAmount);  // Assuming inventory handles adding items
        i++;
    }

    myFile.close();
    cout << "Game loaded successfully!" << endl;
    isLoaded=true;
    break;
        }

        else if(cin.fail() || 1 > choice || 2 < choice){
            cout << "\nInvalid Input\n" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << endl;
    }

    /*while (!(myPlayer->logout()))
    {
        myPlayer->menu();
    }
        */
    ofstream myFile;
        if(!isLoaded){
            cout << "How would you like to save (type the file name)?" << endl;
            string filename;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, filename);
            filename+=".txt";
            myFile.open(filename, ofstream::trunc);
            if (!myFile) {
                cerr << "Error creating file!" << endl;
                delete myPlayer;
                return 1;
            }
        }
        else{
            myFile.open(filename, ofstream::trunc);
            if (!myFile) {
                cerr << "Error creating file!" << endl;
                delete myPlayer;
                return 1;
            }
        }
        Pokemon* myPokemon;
        for(int i=0;i<myPlayer->getPC()->getCaughtPokemon().size();i++){
            myPokemon = myPlayer->getPC()->getCaughtPokemon().at(i);
            myFile << myPokemon->speciesToString(myPokemon->getSpecies()) << endl;
            myFile << myPokemon->getLevel() << endl;
            myFile << myPokemon->getEXP() << endl;
            //myFile << myPokemon -> getIV() << endl;
            myFile << myPokemon -> getMove1()->getName() << endl;
            myFile << myPokemon -> getMove2()->getName() << endl;
            myFile << myPokemon -> getMove3()->getName() << endl;
            
            myFile << "..." << endl;
        }
        myFile << "-----------" << endl;
        myFile << myPlayer->getStore()->getMoney() << endl;
        for(int i=0;i<myPlayer->getItems().size();i++){
            myFile << myPlayer->getItems().at(i)->getAmount() << endl;
        }
        
        myFile.close();

        cout << "File created and saved successfully." << endl;
        delete myPlayer;
        return 0;
}