#pragma once

class Player;

#include "Player.h"
#include "Pokemon/pokemon.h"

using namespace std;

class Battle {
    private:
        Player* player;
        Pokemon* wildPokemon;
        bool isPlayerTurn;
        bool checkBattleEnd() const;
        int randomNum(int , int);
        Pokemon* displayBattleMenu;

    public: 
        Battle() : player(nullptr), wildPokemon(nullptr), isPlayerTurn(true), displayBattleMenu(nullptr) {}
        Battle(Player* p, Pokemon* wp) : player(p), wildPokemon(wp), isPlayerTurn(true), displayBattleMenu(nullptr) {}
        void startBattle();
        bool isCatchable() const;
        bool isCatchSuccess(const Pokeball& pokeball);
        void viewItems() const;
        void viewTeam() const;
        void flee();
        void endBattle();
        void battleMenu();
};