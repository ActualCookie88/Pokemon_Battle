#pragma once
#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Display {
    public:

        void border() const;

        void border2() const;

        void displayStartScreen() const;

        void displayMenuScreen() const;

        void displayInventoryScreen() const;

        void displayPCScreen() const;

        void displayItemScreen() const;

        void displayStoreScreen() const;

        void displayBattleScreen() const;

        void displayMovesScreen() const;

        void displayLoseScreen() const;

        void displayTeamScreen() const;

};
