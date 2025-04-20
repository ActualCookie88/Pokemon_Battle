#pragma once

#include "../Pokemon/pokemon.h"
#include "../../header/Display.h"

using namespace std;

class PC {
    private:
        vector<Pokemon*> teamPokemon;
        vector<Pokemon*> caughtPokemon;
        Display* display;

    public:
        PC() : teamPokemon( { } ), caughtPokemon( { } ) {}
        PC(vector<Pokemon*>& team, vector<Pokemon*>& caught) : teamPokemon(team), caughtPokemon(caught) {}
        ~PC();
        // actions
        void initiatePC();
        void addPokemon(Pokemon* pokemon);
        void viewPokemonCaught();
        void viewPokemonStats();
        void viewPokemonTeam();
        void editPokemonTeam();
        void displayTeamStats();
        // helpers
        int clearInputHelper();
        int selectOptionHelper(int min, int max);
        int validateInput(int input, int min, int max);
        // getters
        vector<Pokemon*>& getCaughtPokemon() { return caughtPokemon; }
        vector<Pokemon*>& getTeamPokemon() { return teamPokemon; }
        // setters
        void setCaughtPokemon(vector<Pokemon*> pokemon) { caughtPokemon = pokemon; }
        void setTeamPokemon(vector<Pokemon*> pokemon) { teamPokemon = pokemon; }
        void setTeamAndCaught(vector<Pokemon*> team);
}; 