#include "../header/Display.h"

int main() {
    Display* screens = new Display();

    screens->displayStartScreen();
    screens->displayMenuScreen();
    screens->displayInventoryScreen();
    screens->displayPCScreen();
    screens->displayItemScreen();
    screens->displayStoreScreen();
    screens->displayBattleScreen();
    screens->displayMovesScreen();
    screens->displayLoseScreen();
    screens->displayTeamScreen();


    return 0;
}