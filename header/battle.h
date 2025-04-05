#pragma once

#include "player/Player.h"
#include "Pokemon/pokemon.h"
#include "Pokemon/wildPokemon.h"
#include "Display.h"

using namespace std;

class Battle {
    private:
        WildPokemon* wildPokemon;
        Display* display;
        Player* player;
        bool isPlayerTurn;

    public: 
        Battle() : player(nullptr), wildPokemon(nullptr), isPlayerTurn(true) {}
        Battle(Player*& p, WildPokemon* wp) : player(p), wildPokemon(wp), isPlayerTurn(true) {}
        // actions
        void initiateBattle();

        void viewUseItems();
        void viewItem();
        void useItem();

        void catchPokemon(WildPokemon* wildPokemon, Pokeball* item);

        void viewTeam();


        void flee();

        bool checkBattleEnd() const;

        void startBattle();

        void endBattle(bool pokemonCaught);
        void playerTurn();
        void wildPokemonTurn();
        // helpers
        int clearInputHelper();
        int selectOptionHelper(int min, int max);
        int validateInput(int input, int min, int max);
        // getters
        Player* getPlayer() { return player;}
        WildPokemon* getWildPokemon() { return wildPokemon; }
       
};