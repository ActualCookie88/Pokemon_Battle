#pragma once

#include "player/Player.h"
#include "Pokemon/pokemon.h"
#include "Pokemon/wildPokemon.h"
#include "Display.h"

using namespace std;

class Battle {
    private:
        Display* display;
        Player* player;
        WildPokemon* wildPokemon;
        Pokemon* activePokemon;
        bool pokemonIsCaught = false;
        bool playerTurnOver = false;

    public: 
        Battle() : player(nullptr), wildPokemon(nullptr) {}
        Battle(Player*& p, WildPokemon* wp) : player(p), wildPokemon(wp), activePokemon(p->getTeam().at(0)) {}
        // actions
        void initiateBattle();
        // BAG option (1)
        void viewUseItems();
        void useItem();
        void useBall(WildPokemon* wildPokemon, Pokeball* item);
        void usePotion(Pokemon*& pokemon, Potion* potion);
        void useRevive(Pokemon*& pokemon, Revive* revive);
        void useReviveAfterLost();
        // POKEMON option (2)
        void viewEditTeam();
        void viewTeam(int option);
        void editTeam();
        // FIGHT option (3)
        void chooseMove();
        // FLEE option (4)
        bool fleeSuccess();
        // misc
        void displayEffectiveness(Attack* move, Pokemon* defender);
        bool allFaintedPokemon() const;
        bool hasFaintedPokemon() const;
        bool checkBattleEnd() const;
        bool isTeamFullHP() const;
        void wildPokemonTurn();
        void choosePokemonAfterFaint();
        void updateWin();
        // helpers
        int clearInputHelper();
        int selectOptionHelper(int min, int max);
        int validateInput(int input, int min, int max);
        // getters
        Player* getPlayer() { return player;}
        WildPokemon* getWildPokemon() { return wildPokemon; }
       
};