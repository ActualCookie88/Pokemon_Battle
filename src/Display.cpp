#include "../header/Display.h"
#include "../header/Store.h"

void Display::displayStartScreen() const {
cout << "//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << " _________________________________________________________________________________________________________________________________" << endl;
    cout << "|                                                                                                                                 |" << endl;
    cout << "|     ____    _____   _    _   _____   _     _   _____   __   _          ____     _____   _______   _______   _       _____   _   |" << endl;
    cout << "|    |  _ \\  |  _  | | |  / / |  ___| | \\   / | |  _  | |  \\ | |        |  _  \\  |  _  | |__   __| |__   __| | |     |  ___| | |  |" << endl;
    cout << "|    | |_) | | | | | | | / /  | |___  |  \\ /  | | | | | |   \\| |        | |_)  | | |_| |    | |       | |    | |     | |___  | |  |" << endl;
    cout << "|    |  __/  | | | | |    /   |  ___| | |\\ /| | | | | | | |\\   |        |  _  /  |  _  |    | |       | |    | |     |  ___| |_|  |" << endl;
    cout << "|    | |     | |_| | | |\\ \\   | |___  | |   | | | |_| | | | \\  |        | |_) \\  | | | |    | |       | |    | |___  | |___   _   |" << endl;
    cout << "|    |_|     |_____| |_| \\_\\  |_____| |_|   |_| |_____| |_|  \\_|        |_____/  |_| |_|    |_|       |_|    |_____| |_____| |_|  |" << endl;
    cout << "|                                                                                                                                 |" << endl;
    cout << "|_________________________________________________________________________________________________________________________________|" << endl;
    cout << endl;
    cout << "(1) New Game" << endl;
    cout << "(2) Load Game" << endl;
    cout << endl;
}

void Display::displayMenuScreen() const {
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
    cout << "(4) Save Game" << endl;
    cout << "(5) Log Out" << endl;
    cout << endl;
}

void Display::displayInventoryScreen() const {
    cout << "//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << " _____________________________________________________________________________________" << endl;
    cout << "|                                                                                     |" << endl;
    cout << "|     _______   __   _   _    _   _____   __   _   _______   _____   _____   _   _    |" << endl;
    cout << "|    |__   __| |  \\ | | | |  / / |  ___| |  \\ | | |__   __| |  _  | |  _  \\ \\ \\ / /   |" << endl;
    cout << "|       | |    |   \\| | | | / /  | |___  |   \\| |    | |    | | | | | |_)  | \\ V /    |" << endl;
    cout << "|       | |    | |\\   | | |/ /   |  ___| | |\\   |    | |    | | | | |  _  /   | |     |" << endl;
    cout << "|     __| |__  | | \\  | |   /    | |___  | | \\  |    | |    | |_| | | | \\ \\   | |     |" << endl;
    cout << "|    |_______| |_|  \\_| |__/     |_____| |_|  \\_|    |_|    |_____| |_|  \\_\\  |_|     |" << endl;
    cout << "|                                                                                     |" << endl;
    cout << "|_____________________________________________________________________________________|" << endl;
    cout << endl;
    cout << "(1) View Pokemon in PC" << endl;
    cout << "(2) View Items" << endl;
    cout << "(3) Go Back" << endl;
    cout << endl;
}

void Display::displayPCScreen() const {
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
}

void Display::displayItemScreen() const {
    cout << "//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << " _____________________________________________________" << endl;
    cout << "|                                                     |" << endl;
    cout << "|     _______   _______   _____   _     _   _____     |" << endl;
    cout << "|    |__   __| |__   __| |  ___| | \\   / | |  ___|    |" << endl;
    cout << "|       | |       | |    | |___  |  \\ /  | | |___     |" << endl;
    cout << "|       | |       | |    |  ___| | |\\ /| | |___  |    |" << endl;
    cout << "|     __| |__     | |    | |___  | |   | |  ___| |    |" << endl;
    cout << "|    |_______|    |_|    |_____| |_|   |_| |_____|    |" << endl;
    cout << "|                                                     |" << endl;
    cout << "|_____________________________________________________|" << endl;
    cout << endl;
    cout << "Current owned items: " << endl;
}

void Display::displayStoreScreen() const {
    cout << "//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "Welcome to the Poké Mart!" << endl;
    cout << " __________________________________________________" << endl;
    cout << "|                                                  |" << endl;
    cout << "|     _____   _______   _____   _____    _____     |" << endl;
    cout << "|    |  ___| |__   __| |  _  | |  _  \\  |  ___|    |" << endl;
    cout << "|    | |___     | |    | | | | | |_)  | | |___     |" << endl;
    cout << "|    |___  |    | |    | | | | |  _  /  |  ___|    |" << endl;
    cout << "|     ___| |    | |    | |_| | | | \\ \\  | |___     |" << endl;
    cout << "|    |_____|    |_|    |_____| |_|  \\_\\ |_____|    |" << endl;
    cout << "|                                                  |" << endl;
    cout << "|__________________________________________________|" << endl;
    cout << endl;
    cout << "Options:" << endl;
    cout << "(1) Buy Items" << endl;
    cout << "(2) Sell Items" << endl;
    cout << "(3) View My Items" << endl;
    cout << "(4) Exit Poké Mart" << endl << endl;
}

void Display::displayBattleScreen() const {
    cout << "//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << " _____________________________________________________________________________________________________" << endl;
    cout << "|                                                                                                     |" << endl;
    cout << "|     ____     _____   _______   _______   _       ____          _     _   _____   __   _   _   _     |" << endl;
    cout << "|    |  _  \\  |  _  | |__   __| |__   __| | |     |  __|        | \\   / | |  ___| |  \\ | | | | | |    |" << endl;
    cout << "|    | |_)  | | |_| |    | |       | |    | |     | |__         |  \\ /  | | |___  |   \\| | | | | |    |" << endl;
    cout << "|    |  _  /  |  _  |    | |       | |    | |     |  __|        | |\\ /| | |  ___| | |\\   | | | | |    |" << endl;
    cout << "|    | |_) \\  | | | |    | |       | |    | |___  | |__         | |   | | | |___  | | \\  | | |_| |    |" << endl;
    cout << "|    |_____/  |_| |_|    |_|       |_|    |_____| |____|        |_|   |_| |_____| |_|  \\_| |_____|    |" << endl;
    cout << "|                                                                                                     |" << endl;
    cout << "|_____________________________________________________________________________________________________|" << endl;
    cout << endl;
    cout << "(1) View/Use Items" << endl;
    cout << "(2) View/Edit Pokemon Team" << endl;
    cout << "(3) View Active Pokemon Moveset" << endl;
    cout << "(4) View Wild Pokemon stats" << endl;
    cout << "(5) Attempt to flee battle" << endl;
    cout << endl;
}

void Display::displayMovesScreen() const {
    cout << "//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << " __________________________________________________" << endl;
    cout << "|                                                  |" << endl;
    cout << "|     _     _   _____   _    _   _____   _____     |" << endl;
    cout << "|    | \\   / | |  _  | | |  / / |  ___| |  ___|    |" << endl;
    cout << "|    |  \\ /  | | | | | | | / /  | |___  | |___     |" << endl;
    cout << "|    | |\\ /| | | | | | | |/ /   |  ___| |___  |    |" << endl;
    cout << "|    | |   | | | |_| | |   /    | |___   ___| |    |" << endl;
    cout << "|    |_|   |_| |_____| |__/     |_____| |_____|    |" << endl;
    cout << "|                                                  |" << endl;
    cout << "|__________________________________________________|" << endl;
    cout << endl;

    string pokemon = "Pikachu";
    cout << pokemon << "\'s Moveset: " << endl;
    // access and print Active Pokemon's moves, example:
    cout << "1. Thunderbolt" << endl;
    cout << "2. Headbutt" << endl;
    cout << "3. Shock" << endl;
    cout << "4. Iron Tail" << endl;
    cout << endl;
    cout << "Enter move number to use: " << endl; // prompt user for number input relative to move
    cout << "(Enter 5 to Go Back)" << endl;
    cout << endl;
}

void Display::displayLoseScreen() const {
    cout << "//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << " __________________________________________________________________________" << endl;
    cout << "|                                                                          |" << endl;
    cout << "|     _   _   _____   _   _          _       _____   _____   _____   _     |" << endl;
    cout << "|    \\ \\ / / |  _  | | | | |        | |     |  _  | |  ___| |  ___| | |    |" << endl;
    cout << "|     \\ V /  | | | | | | | |        | |     | | | | | |___  | |___  | |    |" << endl;
    cout << "|      | |   | | | | | | | |        | |     | | | | |___  | |  ___| |_|    |" << endl;
    cout << "|      | |   | |_| | | |_| |        | |___  | |_| |  ___| | | |___   _     |" << endl;
    cout << "|      |_|   |_____| |_____|        |_____| |_____| |_____| |_____| |_|    |" << endl;
    cout << "|                                                                          |" << endl;
    cout << "|__________________________________________________________________________|" << endl;
    cout << endl;
    cout << "ALL OF YOUR POKEMON HAVE FAINTED!" << endl;
    cout << "(1) Use Revive Item" << endl; // only works if the user actually owns one, use conditional
    cout << "(2) Give up and flee" << endl;
    cout << endl;
}

void Display::displayTeamScreen() const {
    cout << "//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << " ___________________________________________" << endl;
    cout << "|                                           |" << endl;
    cout << "|     _______   _____   _____   _     _     |" << endl;
    cout << "|    |__   __| |  ___| |  _  | | \\   / |    |" << endl;
    cout << "|       | |    | |___  | |_| | |  \\ /  |    |" << endl;
    cout << "|       | |    |  ___| |  _  | | |\\ /| |    |" << endl;
    cout << "|       | |    | |___  | | | | | |   | |    |" << endl;
    cout << "|       |_|    |_____| |_| |_| |_|   |_|    |" << endl;
    cout << "|                                           |" << endl;
    cout << "|___________________________________________|" << endl;
    cout << endl;

    cout << "Pokemon in main team (MAX 3): "<< endl;
    // access and print user's team, example:
    cout << "1. Gyrados" << endl;
    cout << "2. Charmander" << endl;
    cout << "3. Ghastly" << endl;
    
    cout << endl;
    cout << "(1) View Pokemon stats" << endl; // should prompt user to enter number relative to Pokemon, will print its stats
    cout << "(2) Swap Active Pokemon with Pokemon from PC" << endl; // also prompt user two numbers (Active Pokemon and PC Pokemon), will swap them and redisplay Team
    cout << "(3) Go Back" << endl;
    cout << endl;
}
