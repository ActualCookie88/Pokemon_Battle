#include "../header/battle.h"
#include <iostream>
#include <limits>
#include <fstream>
#include <dirent.h>
#include <cstring>
#include "../header/player/Player.h"
using namespace std;

PokemonSpecies stringtoSpecies(string& sp) {
    if (sp == "Bulbasaur") return PokemonSpecies::Bulbasaur;
    if (sp == "Squirtle") return PokemonSpecies::Squirtle;
    if (sp == "Charmander") return PokemonSpecies::Charmander;
    if (sp == "Pidgey") return PokemonSpecies::Pidgey;
    if (sp == "Ivysaur") return PokemonSpecies::Ivysaur;
    if (sp == "Horsea") return PokemonSpecies::Horsea;
    if (sp == "Vulpix") return PokemonSpecies::Vulpix;
    if (sp == "Rattata") return PokemonSpecies::Rattata;
    if (sp == "Venusaur") return PokemonSpecies::Venusaur;
    if (sp == "Psyduck") return PokemonSpecies::Psyduck;
    if (sp == "Growlithe") return PokemonSpecies::Growlithe;
    if (sp == "Spearow") return PokemonSpecies::Spearow;
    if (sp == "Oddish") return PokemonSpecies::Oddish;
    if (sp == "Tentacool") return PokemonSpecies::Tentacool;
    if (sp == "Ponyta") return PokemonSpecies::Ponyta;
    if (sp == "Meowth") return PokemonSpecies::Meowth;
    if (sp == "Gloom") return PokemonSpecies::Gloom;
    if (sp == "Staryu") return PokemonSpecies::Staryu;
    if (sp == "Charmeleon") return PokemonSpecies::Charmeleon;
    if (sp == "Jigglypuff") return PokemonSpecies::Jigglypuff;
    if (sp == "Vileplume") return PokemonSpecies::Vileplume;
    if (sp == "Slowpoke") return PokemonSpecies::Slowpoke;
    if (sp == "Rapidash") return PokemonSpecies::Rapidash;
    if (sp == "Farfetch’d") return PokemonSpecies::Farfetchd;
    if (sp == "Paras") return PokemonSpecies::Paras;
    if (sp == "Seel") return PokemonSpecies::Seel;
    if (sp == "Magmar") return PokemonSpecies::Magmar;
    if (sp == "Raticate") return PokemonSpecies::Raticate;
    if (sp == "Parasect") return PokemonSpecies::Parasect;
    if (sp == "Wartortle") return PokemonSpecies::Wartortle;
    if (sp == "Ninetales") return PokemonSpecies::Ninetales;
    if (sp == "Fearow") return PokemonSpecies::Fearow;
    if (sp == "Bellsprout") return PokemonSpecies::Bellsprout;
    if (sp == "Dewgong") return PokemonSpecies::Dewgong;
    if (sp == "Flareon") return PokemonSpecies::Flareon;
    if (sp == "Wigglytuff") return PokemonSpecies::Wigglytuff;
    if (sp == "Weepinbell") return PokemonSpecies::Weepinbell;
    if (sp == "Blastoise") return PokemonSpecies::Blastoise;
    if (sp == "Arcanine") return PokemonSpecies::Arcanine;
    if (sp == "Persian") return PokemonSpecies::Persian;
    if (sp == "Victreebel") return PokemonSpecies::Victreebel;
    if (sp == "Lapras") return PokemonSpecies::Lapras;
    if (sp == "Charizard") return PokemonSpecies::Charizard;
    if (sp == "Kangaskhan") return PokemonSpecies::Kangaskhan;
    if (sp == "Tangela") return PokemonSpecies::Tangela;
    if (sp == "Gyarados") return PokemonSpecies::Gyarados;
    if (sp == "Moltres") return PokemonSpecies::Moltres;
    if (sp == "Snorlax") return PokemonSpecies::Snorlax;
    return PokemonSpecies::none;
}

Moves stringToMove(const std::string& move) {
    if (move == "FireSpin") return Moves::FireSpin;
    if (move == "Flamethrower") return Moves::Flamethrower;
    if (move == "FireBlast") return Moves::FireBlast;
    if (move == "Ember") return Moves::Ember;
    if (move == "FirePunch") return Moves::FirePunch;
    if (move == "Absorb") return Moves::Absorb;
    if (move == "LeechSeed") return Moves::LeechSeed;
    if (move == "MegaDrain") return Moves::MegaDrain;
    if (move == "PetalDance") return Moves::PetalDance;
    if (move == "RazorLeaf") return Moves::RazorLeaf;
    if (move == "SleepPowder") return Moves::SleepPowder;
    if (move == "SolarBeam") return Moves::SolarBeam;
    if (move == "Spore") return Moves::Spore;
    if (move == "StunSpore") return Moves::StunSpore;
    if (move == "VineWhip") return Moves::VineWhip;
    if (move == "Clamp") return Moves::Clamp;
    if (move == "Crabhammer") return Moves::Crabhammer;
    if (move == "HydroPump") return Moves::HydroPump;
    if (move == "Surf") return Moves::Surf;
    if (move == "WaterGun") return Moves::WaterGun;
    if (move == "Waterfall") return Moves::Waterfall;
    if (move == "Withdraw") return Moves::Withdraw;
    if (move == "Barrage") return Moves::Barrage;
    if (move == "Bide") return Moves::Bide;
    if (move == "Bind") return Moves::Bind;
    if (move == "BodySlam") return Moves::BodySlam;
    if (move == "CometPunch") return Moves::CometPunch;
    if (move == "Cut") return Moves::Cut;
    if (move == "DefenseCurl") return Moves::DefenseCurl;
    if (move == "DizzyPunch") return Moves::DizzyPunch;
    if (move == "DoubleSlap") return Moves::DoubleSlap;
    if (move == "DoubleEdge") return Moves::DoubleEdge;
    if (move == "EggBomb") return Moves::EggBomb;
    if (move == "Explosion") return Moves::Explosion;
    if (move == "FuryAttack") return Moves::FuryAttack;
    if (move == "FurySwipes") return Moves::FurySwipes;
    if (move == "Glare") return Moves::Glare;
    if (move == "Growl") return Moves::Growl;
    if (move == "Growth") return Moves::Growth;
    if (move == "Guillotine") return Moves::Guillotine;
    if (move == "Harden") return Moves::Harden;
    if (move == "Headbutt") return Moves::Headbutt;
    if (move == "HornAttack") return Moves::HornAttack;
    if (move == "HornDrill") return Moves::HornDrill;
    if (move == "HyperBeam") return Moves::HyperBeam;
    if (move == "HyperFang") return Moves::HyperFang;
    if (move == "Leer") return Moves::Leer;
    if (move == "LovelyKiss") return Moves::LovelyKiss;
    if (move == "MegaKick") return Moves::MegaKick;
    if (move == "MegaPunch") return Moves::MegaPunch;
    if (move == "Pound") return Moves::Pound;
    if (move == "QuickAttack") return Moves::QuickAttack;
    if (move == "Rage") return Moves::Rage;
    if (move == "RazorWind") return Moves::RazorWind;
    if (move == "Recover") return Moves::Recover;
    if (move == "Scratch") return Moves::Scratch;
    if (move == "Screech") return Moves::Screech;
    if (move == "SelfDestruct") return Moves::SelfDestruct;
    if (move == "Sharpen") return Moves::Sharpen;
    if (move == "Sing") return Moves::Sing;
    if (move == "SkullBash") return Moves::SkullBash;
    if (move == "Slam") return Moves::Slam;
    if (move == "Slash") return Moves::Slash;
    if (move == "SoftBoiled") return Moves::SoftBoiled;
    if (move == "SonicBoom") return Moves::SonicBoom;
    if (move == "SpikeCannon") return Moves::SpikeCannon;
    if (move == "Splash") return Moves::Splash;
    if (move == "Stomp") return Moves::Stomp;
    if (move == "Strength") return Moves::Strength;
    if (move == "SuperFang") return Moves::SuperFang;
    if (move == "Supersonic") return Moves::Supersonic;
    if (move == "SwordsDance") return Moves::SwordsDance;
    if (move == "Tackle") return Moves::Tackle;
    if (move == "TailWhip") return Moves::TailWhip;
    if (move == "TakeDown") return Moves::TakeDown;
    if (move == "Thrash") return Moves::Thrash;
    if (move == "ViseGrip") return Moves::ViseGrip;
    if (move == "Wrap") return Moves::Wrap;
    return Moves::None; // Add an Unknown case to handle invalid strings
}
void destructor(Player* myPlayer){
    delete myPlayer;
}
int main()
{
    srand(time(0));
    ifstream inFS;
    int choice;
    Player* myPlayer = new Player();
    bool isLoaded = false;
    string filename;
    cout << "//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << " _________________________________________________________________________________________________________________________________" << endl;
    cout << "|                                                                                                                                 |" << endl;
    cout << "|     ____    _____   _    _   _____   _     _   _____   __   _          ____     _____   _______   _______   _       _____   _   |" << endl;
    cout << "|    |  _ \\  |  _  | | |  / / |  ___| | \\   / | |  _  | |  \\ | |        |  _  \\  |  _  | |__   __| |__   __| | |     |  ___| | |  |" << endl;
    cout << "|    | |_) | | | | | | | / /  | |___  |  \\ /  | | | | | |   \\| |        | |_)  | | |_| |    | |       | |    | |     | |___  | |  |" << endl;
    cout << "|    |  __/  | | | | |    /   |  ___| | |\\ /| | | | | | | |\\   |        |  _  /  |  _  |    | |       | |    | |     |  ___| |_|  |" << endl;
    cout << "|    | |     | |_| | | |\\ \\   | |___  | |   | | | |_| | | | \\  |        | |_) \\  | | | |    | |       | |    | |___  | |___   _   |" << endl;
    cout << "|    |_|     |_____| |_| \\_\\  |_____| |_|   |_| |_____| |_|  \\_|        |_____/  |_| |_|    |_|       |_|    |_____| |_____| |_|  |" << endl;
    cout << "|                                                                                                                                 |" << endl;
    cout << "|_________________________________________________________________________________________________________________________________|" << endl;
    while (true)
    {
        cout << endl;
        cout << "(1) New Game" << endl;
        cout << "(2) Load Game" << endl;
        cout << endl;
        cout << "Enter a number choice: ";
        cin >> choice;
        cout << endl;


        if (choice == 1) {
            break;
        }

        else if (choice == 2) {
            cout << "What game do you want to load?" << endl << endl;
             const char* directoryPath = ".";


            DIR* dir = opendir(directoryPath);
            if (dir == nullptr) {
                std::cerr << "Error opening directory." << std::endl;
                destructor(myPlayer);
                return 1;
            }


            struct dirent* entry;
            while ((entry = readdir(dir)) != nullptr) {
                if (entry->d_type == DT_REG && strstr(entry->d_name, ".txt") != nullptr) {
                    if (strcmp(entry->d_name, "CMakeLists.txt") == 0 || strcmp(entry->d_name, "CMakeCache.txt") == 0) {
                        continue; // Skip these files
                    }
                    std::cout << entry->d_name << std::endl;  
                }
            }


            closedir(dir);
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, filename);
            std::ifstream myFile(filename);
    if (!myFile) {
        std::cerr << "Error opening file!" << std::endl;
        destructor(myPlayer);
        return 1;
    }

    std::string line;

    // Load Caught Pokemon
    while (std::getline(myFile, line) && line != "-----------") {
        string currSp= line;
        getline(myFile, line);
        int lvl = stoi(line);
        getline(myFile, line);
        int EXP = stoi(line);
        getline(myFile,line);
        int iv = stoi(line);
        string move1Name, move2Name, move3Name;
        getline(myFile, move1Name);
        getline(myFile, move2Name);
        getline(myFile, move3Name);
        Pokemon* currPokemon= new Pokemon(stringtoSpecies(currSp), lvl, EXP, stringToMove(move1Name), stringToMove(move2Name), stringToMove(move3Name));

        // Skip placeholder line
        std::getline(myFile, line); 
        
        myPlayer->getPC()->addPokemon(currPokemon);
    }

    // Load Money
    if (std::getline(myFile, line)) {
        myPlayer->getStore()->setMoney(stoi(line));
    }

    // Load Inventory
    int i=0;
    while (std::getline(myFile, line)) {
        int itemAmount = std::stoi(line);
        myPlayer->getItems().at(i)->addAmount(itemAmount);  // Assuming inventory handles adding items
        i++;
    }

    myFile.close();
    std::cout << "Game loaded successfully!" << std::endl;
    isLoaded=true;
    break;
        }

        else if(cin.fail() || 1 > choice || 2 < choice){
            cout << "\nInvalid Input\n" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << endl;
    }

    /*while (!(myPlayer->logout()))
    {
        myPlayer->menu();
    }
        */
    ofstream myFile;
        if(!isLoaded){
            cout << "How would you like to save (type the file name)?" << endl;
            string filename;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, filename);
            filename+=".txt";
            myFile.open(filename, ofstream::trunc);
            if (!myFile) {
                std::cerr << "Error creating file!" << std::endl;
                destructor(myPlayer);
                return 1;
            }
        }
        else{
            myFile.open(filename, ofstream::trunc);
            if (!myFile) {
                std::cerr << "Error creating file!" << std::endl;
                destructor(myPlayer);
                return 1;
            }
        }
        Pokemon* myPokemon;
        for(int i=0;i<myPlayer->getPC()->getCaughtPokemon().size();i++){
            myPokemon = myPlayer->getPC()->getCaughtPokemon().at(i);
            myFile << myPokemon->speciesToString(myPokemon->getSpecies()) << endl;
            myFile << myPokemon->getLevel() << endl;
            myFile << myPokemon->getEXP() << endl;
            //myFile << myPokemon -> getIV() << endl;
            myFile << myPokemon -> getMove1()->getName() << endl;
            myFile << myPokemon -> getMove2()->getName() << endl;
            myFile << myPokemon -> getMove3()->getName() << endl;
            
            myFile << "..." << endl;
        }
        myFile << "-----------" << endl;
        myFile << myPlayer->getStore()->getMoney() << endl;
        for(int i=0;i<myPlayer->getItems().size();i++){
            myFile << myPlayer->getItems().at(i)->getAmount() << endl;
        }
        
        myFile.close();

        std::cout << "File created and saved successfully." << std::endl;
        destructor(myPlayer);
        return 0;
}