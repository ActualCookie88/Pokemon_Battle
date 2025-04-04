#pragma once

#include "player/Player.h"
#include "Pokemon/pokemon.h"
#include "Display.h"

using namespace std;

class Battle {
    private:
        Pokemon* wildPokemon;
        Display* display;
        bool isPlayerTurn;
        Player* player;

    public: 
        Battle() : player(nullptr), wildPokemon(nullptr), isPlayerTurn(true) {}
        Battle(Player*& p, Pokemon* wp) : player(p), wildPokemon(wp), isPlayerTurn(true) {}
        // actions
        void initiateBattle();

        void viewItems() const;
        void viewTeam() const;
        

        void flee();


        bool checkBattleEnd() const;
        int randomNum(int , int);
        void startBattle();
        bool isCatchable() const;
        bool isCatchSuccess(const Pokeball& pokeball);
        void endBattle();
       
};