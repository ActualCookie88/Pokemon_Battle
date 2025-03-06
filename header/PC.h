#pragma once
using namespace std;

#include "Pokemon/pokemon.h"

class PC {
    private:
        vector<Pokemon*> teamPokemon;
        vector<Pokemon*> caughtPokemon;

    public:
        PC() : teamPokemon( { } ), caughtPokemon( { } ) {}
        PC(vector<Pokemon*>& team, vector<Pokemon*>& caught) : teamPokemon(team), caughtPokemon(caught) {}
        ~PC();
        //actions
        void initiatePC();
        void addPokemon(Pokemon* pokemon);
        void viewPokemonCaught();
        void viewPokemonStats();
        void viewPokemonTeam();
        void editPokemonTeam();
        //helpers
        int clearInputHelper();
        int selectOptionHelper(int min, int max);
        int validateInput(int input, int min, int max);
        //getters and setters
        vector<Pokemon*> getCaughtPokemon() const { return caughtPokemon; }
        vector<Pokemon*> getCaughtPokemon() { return caughtPokemon; }
        vector<Pokemon*> getTeamPokemon() const { return teamPokemon; }
        vector<Pokemon*> getTeamPokemon() { return teamPokemon; }
        void setCaughtPokemon(vector<Pokemon*> pokemon) { caughtPokemon = pokemon; }
        void setTeamPokemon(vector<Pokemon*> pokemon) { teamPokemon = pokemon; }
}; 