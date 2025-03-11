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

moves stringToMove(const std::string& move) {
    if (move == "FireSpin") return moves::FireSpin;
    if (move == "Flamethrower") return moves::Flamethrower;
    if (move == "FireBlast") return moves::FireBlast;
    if (move == "Ember") return moves::Ember;
    if (move == "FirePunch") return moves::FirePunch;
    if (move == "Absorb") return moves::Absorb;
    if (move == "LeechSeed") return moves::LeechSeed;
    if (move == "MegaDrain") return moves::MegaDrain;
    if (move == "PetalDance") return moves::PetalDance;
    if (move == "RazorLeaf") return moves::RazorLeaf;
    if (move == "SleepPowder") return moves::SleepPowder;
    if (move == "SolarBeam") return moves::SolarBeam;
    if (move == "Spore") return moves::Spore;
    if (move == "StunSpore") return moves::StunSpore;
    if (move == "VineWhip") return moves::VineWhip;
    if (move == "Clamp") return moves::Clamp;
    if (move == "Crabhammer") return moves::Crabhammer;
    if (move == "HydroPump") return moves::HydroPump;
    if (move == "Surf") return moves::Surf;
    if (move == "WaterGun") return moves::WaterGun;
    if (move == "Waterfall") return moves::Waterfall;
    if (move == "Withdraw") return moves::Withdraw;
    if (move == "Barrage") return moves::Barrage;
    if (move == "Bide") return moves::Bide;
    if (move == "Bind") return moves::Bind;
    if (move == "BodySlam") return moves::BodySlam;
    if (move == "CometPunch") return moves::CometPunch;
    if (move == "Cut") return moves::Cut;
    if (move == "DefenseCurl") return moves::DefenseCurl;
    if (move == "DizzyPunch") return moves::DizzyPunch;
    if (move == "DoubleSlap") return moves::DoubleSlap;
    if (move == "DoubleEdge") return moves::DoubleEdge;
    if (move == "EggBomb") return moves::EggBomb;
    if (move == "Explosion") return moves::Explosion;
    if (move == "FuryAttack") return moves::FuryAttack;
    if (move == "FurySwipes") return moves::FurySwipes;
    if (move == "Glare") return moves::Glare;
    if (move == "Growl") return moves::Growl;
    if (move == "Growth") return moves::Growth;
    if (move == "Guillotine") return moves::Guillotine;
    if (move == "Harden") return moves::Harden;
    if (move == "Headbutt") return moves::Headbutt;
    if (move == "HornAttack") return moves::HornAttack;
    if (move == "HornDrill") return moves::HornDrill;
    if (move == "HyperBeam") return moves::HyperBeam;
    if (move == "HyperFang") return moves::HyperFang;
    if (move == "Leer") return moves::Leer;
    if (move == "LovelyKiss") return moves::LovelyKiss;
    if (move == "MegaKick") return moves::MegaKick;
    if (move == "MegaPunch") return moves::MegaPunch;
    if (move == "Pound") return moves::Pound;
    if (move == "QuickAttack") return moves::QuickAttack;
    if (move == "Rage") return moves::Rage;
    if (move == "RazorWind") return moves::RazorWind;
    if (move == "Recover") return moves::Recover;
    if (move == "Scratch") return moves::Scratch;
    if (move == "Screech") return moves::Screech;
    if (move == "SelfDestruct") return moves::SelfDestruct;
    if (move == "Sharpen") return moves::Sharpen;
    if (move == "Sing") return moves::Sing;
    if (move == "SkullBash") return moves::SkullBash;
    if (move == "Slam") return moves::Slam;
    if (move == "Slash") return moves::Slash;
    if (move == "SoftBoiled") return moves::SoftBoiled;
    if (move == "SonicBoom") return moves::SonicBoom;
    if (move == "SpikeCannon") return moves::SpikeCannon;
    if (move == "Splash") return moves::Splash;
    if (move == "Stomp") return moves::Stomp;
    if (move == "Strength") return moves::Strength;
    if (move == "SuperFang") return moves::SuperFang;
    if (move == "Supersonic") return moves::Supersonic;
    if (move == "SwordsDance") return moves::SwordsDance;
    if (move == "Tackle") return moves::Tackle;
    if (move == "TailWhip") return moves::TailWhip;
    if (move == "TakeDown") return moves::TakeDown;
    if (move == "Thrash") return moves::Thrash;
    if (move == "ViseGrip") return moves::ViseGrip;
    if (move == "Wrap") return moves::Wrap;
    return moves::None; // Add an Unknown case to handle invalid strings
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
        Pokemon* currPokemon= new Pokemon(stringtoSpecies(currSp), lvl, EXP, iv, stringToMove(move1Name), stringToMove(move2Name), stringToMove(move3Name));

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
            myFile << myPokemon -> getIV() << endl;
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