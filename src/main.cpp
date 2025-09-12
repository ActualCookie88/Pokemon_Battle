#include "../header/battle.h"
#include "../header/player/Player.h"
#include <iostream>
#include <fstream>
#include <limits>
#include <ctime>
#include <chrono>
#include <thread>
#include <cstring>
#include <sys/stat.h>

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

bool fileExists(const string& filename) {
    struct stat buffer;
    return (stat(filename.c_str(), &buffer) == 0);
}

void loading(const string& message) {
    cout << message << " " << flush;
    sleep_for(0.75s); cout << "." << flush;
    sleep_for(0.75s); cout << " ." << flush;
    sleep_for(0.75s); cout << " ." << endl << endl;
    sleep_for(1s);
}

bool loadGame(Player* player, string& filename) {
    cout << "Enter filename (without .txt): ";
    const char* directoryPath = ".";

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, filename);
    filename += ".txt";

    if (!fileExists(filename)) {
        cerr << "File \"" << filename << "\" does not exist!" << endl << endl;
        return false;
    }

    loading("LOADING " + filename);

    ifstream myFile(filename);
    if(!myFile) {
        cerr << "Error opening file!" << endl;
        return false;
    }

    int pokemonCount = 0;

    string line;
    while(getline(myFile, line) && line != "-----------") {
        string speciesStr = line;
        getline(myFile, line); Type type = static_cast<Type>(stoi(line));
        getline(myFile, line); GrowthRate growth = static_cast<GrowthRate>(stoi(line));
        getline(myFile, line); int baseCatch = stoi(line);
        getline(myFile, line); int baseHP = stoi(line);
        getline(myFile, line); int baseAtk = stoi(line);
        getline(myFile, line); int baseDef = stoi(line);
        getline(myFile, line); int hp = stoi(line);
        getline(myFile, line); int maxHP = stoi(line);
        getline(myFile, line); int atk = stoi(line);
        getline(myFile, line); int def = stoi(line);
        getline(myFile, line); int lvl = stoi(line);
        getline(myFile, line); int exp = stoi(line);
        string m1, m2, m3;
        getline(myFile, m1);
        getline(myFile, m2);
        getline(myFile, m3);
        getline(myFile, line); // delimiter "---"

        Pokemon* p = new Pokemon(
            Pokemon::stringToSpecies(speciesStr),
            lvl,
            exp,
            Pokemon::stringToMove(m1),
            Pokemon::stringToMove(m2),
            Pokemon::stringToMove(m3)
        );

        // Set additional stats
        p->setType(type);
        p->setGrowthRate(growth);
        p->setBaseCatchRate(baseCatch);
        p->setBaseHP(baseHP);
        p->setBaseAttack(baseAtk);
        p->setBaseDefense(baseDef);
        p->setHP(hp);
        p->setMaxHP(maxHP);
        p->setAttack(atk);
        p->setDefense(def);

        if(pokemonCount < 3) {
            player->addTeamPokemon(p);
        } else {
            player->addCaughtPokemon(p);
        }
        pokemonCount++;
    }

    if(getline(myFile, line)) {
        player->getStore()->setMoney(stoi(line));
    }

    int i = 0;
    while(getline(myFile, line)) {
        int itemAmount = stoi(line);
        if(i <(int)player->getItems().size()) {
            player->getItems().at(i)->addAmount(itemAmount);
        }
        i++;
    }

    myFile.close();
    return true;
}

void saveGame(Player* player, const string& filename) {
    loading("SAVING GAME");

    ofstream myFile(filename, ofstream::trunc);
    if(!myFile) {
        cerr << "Error creating file!" << endl;
        return;
    }

    // Save team Pokémon first(max 3)
    for(Pokemon* p : player->getTeam()) {
        myFile << p->speciesToString(p->getSpecies()) << endl;
        myFile << static_cast<int>(p->getType()) << endl;
        myFile << static_cast<int>(p->getGrowthRate()) << endl;
        myFile << p->getBaseCatchRate() << endl;
        myFile << p->getBaseHP() << endl;
        myFile << p->getBaseAttack() << endl;
        myFile << p->getBaseDefense() << endl;
        myFile << p->getHP() << endl;
        myFile << p->getMaxHP() << endl;
        myFile << p->getAttack() << endl;
        myFile << p->getDefense() << endl;
        myFile << p->getLevel() << endl;
        myFile << p->getEXP() << endl;
        myFile << p->getMove1()->getName() << endl;
        myFile << p->getMove2()->getName() << endl;
        myFile << p->getMove3()->getName() << endl;
        myFile << "---" << endl;
    }

    // Save caught Pokémon next
    for(Pokemon* p : player->getCaught()) {
        myFile << p->speciesToString(p->getSpecies()) << endl;
        myFile << static_cast<int>(p->getType()) << endl;
        myFile << static_cast<int>(p->getGrowthRate()) << endl;
        myFile << p->getBaseCatchRate() << endl;
        myFile << p->getBaseHP() << endl;
        myFile << p->getBaseAttack() << endl;
        myFile << p->getBaseDefense() << endl;
        myFile << p->getHP() << endl;
        myFile << p->getMaxHP() << endl;
        myFile << p->getAttack() << endl;
        myFile << p->getDefense() << endl;
        myFile << p->getLevel() << endl;
        myFile << p->getEXP() << endl;
        myFile << p->getMove1()->getName() << endl;
        myFile << p->getMove2()->getName() << endl;
        myFile << p->getMove3()->getName() << endl;
        myFile << "---" << endl;
    }

    myFile << "-----------" << endl;

    myFile << player->getStore()->getMoney() << endl;

    for(auto item : player->getItems()) {
        myFile << item->getAmount() << endl;
    }

    myFile.close();
    cout << "File created and saved successfully." << endl;
}

bool deleteGame(const string& filename) {
    string fullFilename = filename;
    if(filename.find(".txt") == string::npos) {
        fullFilename += ".txt";
    }
    
    if(remove(fullFilename.c_str()) != 0) {
        cerr << "Error deleting file \"" << fullFilename << "\"!" << endl;
        return false;
    }
    else {
        cout << "File \"" << fullFilename << "\" deleted successfully." << endl << endl;
        return true;
    }
}

int selectOptionHelper(int min, int max) {
    string input;
    int number;
    while(true) {
        cin >> input;
        cout << endl;

        if(input == "CANCEL") {
            return -1;
        }

        try {
            number = stoi(input); // if fails, throws exception to catch
        } catch(...) {
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
    srand(time(0));
    Player* player = new Player();
    Display* display = player->getDisplay();
    string filename;
    bool gameLoaded = false;

    player->initiateAll(0);
    display->displayStartScreen();

    while(!gameLoaded) {
        cout << "SELECT OPTION: ";
        int choice = selectOptionHelper(1, 3);
        if(choice == -1) {
            cout << "CANCELED" << endl;
            delete player;
            return 0;
        } 
        else if(choice == 1) {
            cout << "Enter filename to save to (without .txt): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, filename);
            filename += ".txt";
            loading("SAVING TO " + filename);
            gameLoaded = true;
        } 
        else if(choice == 2) {
            gameLoaded = loadGame(player, filename);
        }
        else if(choice == 3) {
            cout << "Enter filename to delete (without .txt): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            string delFile;
            getline(cin, delFile);
            
            cout << "Are you sure you want to delete \"" << delFile << ".txt\"? (Y/N): ";
            string confirm;
            getline(cin, confirm);
            if(confirm == "Y" || confirm == "y") {
                deleteGame(delFile);
            } else {
                cout << "Deletion canceled." << endl;
            }
        }
    }   

    bool inMainMenu = true;
    while(inMainMenu) {
        display->displayMenuScreen();
        cout << "SELECT OPTION: ";
        int mainChoice = selectOptionHelper(1, 4);

        if(mainChoice == 1) {
            bool inInventory = true;
            while(inInventory) {
                display->displayInventoryScreen();
                cout << "SELECT OPTION: ";
                int invChoice = selectOptionHelper(1, 3);
                if(invChoice == 1) player->accessPC();
                else if(invChoice == 2) player->viewMyItems(true);
                else if(invChoice == 3) inInventory = false;
            }
        }
        else if(mainChoice == 2) {
            player->accessStore();
        }
        else if(mainChoice == 3) {
            WildPokemon* wild = new WildPokemon(player);
            Battle* battle = new Battle(player, wild);
            battle->initiateBattle();
            if(!battle->getPokemonIsCaught()) delete wild;
            delete battle;
        }
        else if(mainChoice == 4) {
            saveGame(player, filename);
            delete player;
            return 0;
        }
    }

    delete player;
    return 0;
}