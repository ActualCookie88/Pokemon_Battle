#pragma once
#include "Pokemon/pokemon.h"

#include <iostream>
#include <vector>

using namespace std;

class Display {
    public:

        void displayStartScreen() const;

        void displayMenuScreen() const;

        void displayInventoryScreen() const;

        void displayPCScreen(const vector<Pokemon*>& team) const;

        void displayItemScreen() const;

        void displayStoreScreen() const;

        void displayBattleScreen() const;

        void displayMovesScreen() const;

        void displayLoseScreen() const;

        void displayTeamScreen() const;

};
