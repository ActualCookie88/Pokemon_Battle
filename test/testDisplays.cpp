#include "../header/Display.h"

int main() {
    Display* screens = new Display();

    screens->border();
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

    delete screens;

    return 0;
}