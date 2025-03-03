#include "../header/player.h"


using namespace std;


Player::~Player() {
   //delete myInventory;
   
   for (Pokemon* p : caughtPokemons) {
      delete p;
   }
}

int Player::getMoney() const {
    return money;
}

string Player::getName() const {
    return "";
}

vector<Pokemon*> Player::getCaughtPokemon() const {
    return caughtPokemons;
}
vector<Pokemon*> Player::getCaughtPokemon() {
    return caughtPokemons;
}

void Player::addPokemon(Pokemon* p) {
    this->caughtPokemons.push_back(p);
}

vector<Pokemon*> Player::getTeam() const {
    return selectedTeam;
}
vector<Pokemon*> Player::getTeam(){
    return selectedTeam;
}

void Player::accessInventory() {
   myInventory->viewMyItems();
}

void Player::enterBattle() {
   Battle battle;
   battle.battleMenu();
}

bool Player::logout() {
   return isEnded;
}

void Player::menu() {
   int choice;

   cout << "//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
   cout << " _________________________________________" << endl;
   cout << "|                                         |" << endl;
   cout << "|     _     _   _____   __   _   _   _    |" << endl;
   cout << "|    | \\   / | |  ___| |  \\ | | | | | |   |" << endl;
   cout << "|    |  \\ /  | | |___  |   \\| | | | | |   |" << endl;
   cout << "|    | |\\ /| | |  ___| | |\\   | | | | |   |" << endl;
   cout << "|    | |   | | | |___  | | \\  | | |_| |   |" << endl;
   cout << "|    |_|   |_| |_____| |_|  \\_| |_____|   |" << endl;
   cout << "|                                         |" << endl;
   cout << "|_________________________________________|" << endl;
   cout << endl;
   cout << "(1) View Inventory" << endl;
   cout << "(2) Shop at Store" << endl;
   cout << "(3) Search for Wild Pokemon" << endl;
   cout << "(4) View Pokemon in PC" << endl;
   cout << "(5) Log Out" << endl;
   cout << endl;

   cin >> choice;
   while (!cin || choice <= 0 || choice >= 6) {
      cout << "Invalid input" << endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cin >> choice; 
   }
   
   if (choice == 1) {
      accessInventory();
   } else if (choice == 2) {
      myInventory->store();
   } else if (choice == 3) {
      enterBattle();
   } else if (choice == 4){
      displayPCMenu();
   } else if (choice == 5) {
      isEnded = true;
      logout();
   } 
   
   
}

void Player::displayPCMenu(){
    int choice;

    cout << "//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << " ______________________ " << endl;
    cout << "|                      |" << endl;
    cout << "|     ____    _____    |" << endl;
    cout << "|    |  _ \\  |  ___|   |" << endl;
    cout << "|    | |_) | | |       |" << endl;
    cout << "|    |  __/  | |       |" << endl;
    cout << "|    | |     | |___    |" << endl;
    cout << "|    |_|     |_____|   |" << endl;
    cout << "|                      |" << endl;
    cout << "|______________________|" << endl;
    cout << endl;
    
    cout << "Currently owned Pokemon in storage:" << endl;

    if (getCaughtPokemon().empty()) {
        cout << "Your PC is empty!" << endl;
    } else {
        cout << "Pokemon in your PC:" << endl;
        for (int i=0; i< getCaughtPokemon().size(); i++) {
            cout << i + 1 << ". " << getCaughtPokemon().at(i)->speciesToString(getCaughtPokemon().at(i)->getSpecies());
            cout << endl;
        }
        cout << "Total Caught Pokemon: " << getCaughtPokemon().size() << endl;
    }

    cout << endl;
    cout << "(1) View Pokemon stats" << endl; // should prompt user to enter number relative to Pokemon, will print its stats
    cout << "(2) View/Edit Pokemon Team" << endl;
    cout << "(3) Go Back" << endl;
    cout << endl;

    do {
        cout << "Enter your choice: ";
        cin >> choice;
        if (!cin || choice <= 0 || choice >= 4) {
            cout << "Invalid input. Please choose a valid option." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (!cin || choice <= 0 || choice >= 4);

    switch (choice) {
        case 1:
            viewPokemonStats();
            break;
        case 2:
            viewEditPokemonTeam();
            break;
        case 3:
            //return back to main menu screen
            break;
    }
}

void Player::viewPokemonStats() {
    if (getCaughtPokemon().empty()) {
        cout << "Your PC is empty!" << endl;
        return;
    }

    int index;
    cout << "Enter the number of the Pokemon you want to view it's stats: ";
    cin >> index;

    if (index > 0 && index <= getCaughtPokemon().size()) {
        getCaughtPokemon().at(index-1)->displayInfo();
    } else {
        cout << "Invalid selection." << endl;
        displayPCMenu();
    }
}

void Player::viewEditPokemonTeam() {
    if (getCaughtPokemon().empty()) {
        cout << "Your PC is empty!" << endl;
        return;
    }

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


