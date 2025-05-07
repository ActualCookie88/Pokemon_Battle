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
        Battle() : player(nullptr), wildPokemon(nullptr), activePokemon(nullptr) {}
        Battle(Player*& p, WildPokemon* wp) : player(p), wildPokemon(wp), activePokemon(nullptr) {}
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
        bool activePokemonLeft() const;
        bool isTeamFullHP() const;
        void wildPokemonTurn();
        void choosePokemonAfterFaint();
        // win loss results
        void updateLoss();
        void updateWin();
        // helpers
        int selectOptionHelper(int min, int max);
        double ownedByPlayer();
        // getters
        Player* getPlayer() { return player;}
        WildPokemon* getWildPokemon() { return wildPokemon; }
        bool getPokemonIsCaught() { return pokemonIsCaught; }
};