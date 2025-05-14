#include "../header/battle.h"
#include "../header/player/Player.h"
#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>
using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

void newGame() {
    cout << "Enter filename to save to: ";

    string filename;
    cin >> filename;

    cout << endl;
    cout << "SAVING TO " << filename << " " << flush;
    sleep_for(0.75s);
    cout << "." << flush;
    sleep_for(0.75s);
    cout << " ."  << flush;
    sleep_for(0.75s);
    cout << " ." << endl << endl;
    sleep_for(1s);
}

void loadGame(Player*& player) {
    cout << "Enter filename to load: ";

    string filename;
    cin >> filename;

    cout << endl;
    cout << "LOADING " << filename << " " << flush;
    sleep_for(0.75s);
    cout << "." << flush;
    sleep_for(0.75s);
    cout << " ."  << flush;
    sleep_for(0.75s);
    cout << " ." << endl << endl;
    sleep_for(1s);
}

void saveGame(Player* player, const string& filename) {
    cout << "SAVING GAME " << flush;
    sleep_for(0.75s);
    cout << "." << flush;
    sleep_for(0.75s);
    cout << " ."  << flush;
    sleep_for(0.75s);
    cout << " ." << endl << endl;
    sleep_for(1s);
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
            number = stoi(input); // if fails, throws exception to catch
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
    string filename;
    bool flag = true;
    Player* player = new Player();
    Display* display = player->getDisplay();

    player->initiateAll(0);
    display->displayStartScreen();

    while(flag) {
        cout << "SELECT OPTION: ";
        int startChoice = selectOptionHelper(1,2);
        if(startChoice == 1) {
            newGame();
        }
        else if(startChoice == 2) {
            loadGame(player);
        }

        bool inMainMenu = true;

        while(inMainMenu) {\
            display->displayMenuScreen();
            cout << "SELECT OPTION: ";
            int mainChoice = selectOptionHelper(1,5);

            if(mainChoice == 1) {
                bool inInventory = true;
                while(inInventory) {
                    display->displayInventoryScreen();
                    cout << "SELECT OPTION: ";
                    int inventoryChoice = selectOptionHelper(1,3);
                    if(inventoryChoice == 1) {
                        player->accessPC();
                    }
                    else if(inventoryChoice == 2) {
                        player->viewMyItems(true);
                    }
                    else if(inventoryChoice == 3) {
                        inInventory = false;;
                    }
                }
            }
            else if(mainChoice == 2) {
                player->accessStore();
            }
            else if(mainChoice == 3) {
                WildPokemon* wildPokemon = new WildPokemon(player);
           
                Battle* battle = new Battle(player, wildPokemon);

                battle->initiateBattle();
                if(!battle->getPokemonIsCaught()) { delete wildPokemon; }
                delete battle;
            }
            else if(mainChoice == 4) {
                saveGame(player, filename);
                delete player;
                return 0;
            }
        }
    }
    return 0;
}