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
        bool isPlayerTurn;
        bool pokemonIsCaught = false;

    public: 
        Battle() : player(nullptr), wildPokemon(nullptr), isPlayerTurn(true) {}
        Battle(Player*& p, WildPokemon* wp) : player(p), wildPokemon(wp), activePokemon(p->getTeam().at(0)), isPlayerTurn(true) {}
        // actions
        void initiateBattle();
        // BAG option (1)
        void viewUseItems();
        void viewItem();
        void useItem();
        void useBall(WildPokemon* wildPokemon, Pokeball* item);
        void usePotion(Pokemon*& pokemon, Potion* potion);
        void useRevive(Pokemon*& pokemon, Revive* revive);
        // POKEMON option (2)
        void viewEditTeam();
        void viewTeam(int option);
        void editTeam();
        // FIGHT option (3)
        void chooseMove();
        // FLEE option (4)
        bool fleeSuccess();

        bool checkBattleEnd() const;
        bool hasFaintedPokemon() const;
        bool isTeamFullHP() const;

        void endBattle(bool pokemonCaught);
        void wildPokemonTurn();
        // helpers
        int clearInputHelper();
        int selectOptionHelper(int min, int max);
        int validateInput(int input, int min, int max);
        // getters
        Player* getPlayer() { return player;}
        WildPokemon* getWildPokemon() { return wildPokemon; }
       
};