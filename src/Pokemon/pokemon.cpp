#include "../../header/Pokemon/pokemon.h"
#include "../../header/Pokemon/attack.h"
#include <algorithm>
#include <random>
#include <cstdlib>
#include <ctime>

vector<Moves> fireTypeMoves = {Moves::FireSpin, Moves::Flamethrower, Moves::FireBlast, Moves::Ember, Moves::FirePunch};
vector<Moves> waterTypeMoves = {Moves::Clamp, Moves::Crabhammer, Moves::HydroPump, Moves::Surf, Moves::WaterGun, Moves::Waterfall, Moves::Withdraw};
vector<Moves> grassTypeMoves = {Moves::Absorb, Moves::LeechSeed, Moves::MegaDrain, Moves::PetalDance, Moves::RazorLeaf, Moves::SleepPowder, Moves::SolarBeam, Moves::Spore, Moves::StunSpore, Moves::VineWhip};
vector<Moves> normalTypeMoves = {
    Moves::Barrage, Moves::Bide, Moves::Bind, Moves::BodySlam, Moves::CometPunch, Moves::Cut, Moves::DefenseCurl, Moves::DizzyPunch, Moves::DoubleSlap, Moves::DoubleEdge, Moves::EggBomb, Moves::Explosion, 
    Moves::FuryAttack, Moves::FurySwipes, Moves::Glare, Moves::Growl, Moves::Growth, Moves::Guillotine, Moves::Harden, Moves::Headbutt, Moves::HornAttack, Moves::HornDrill, Moves::HyperBeam, Moves::HyperFang, 
    Moves::Leer, Moves::LovelyKiss, Moves::MegaKick, Moves::MegaPunch, Moves::Pound, Moves::QuickAttack, Moves::Rage, Moves::RazorWind, Moves::Recover, Moves::Scratch, Moves::Screech, Moves::SelfDestruct, 
    Moves::Sharpen, Moves::Sing, Moves::SkullBash, Moves::Slam, Moves::Slash, Moves::SoftBoiled, Moves::SonicBoom, Moves::SpikeCannon, Moves::Splash, Moves::Stomp, Moves::Strength, Moves::SuperFang, 
    Moves::Supersonic, Moves::SwordsDance, Moves::Tackle, Moves::TailWhip, Moves::TakeDown, Moves::Thrash, Moves::ViseGrip, Moves::Wrap};

Pokemon::Pokemon() : species(PokemonSpecies::none), type(Type::Normal), baseHP(100), baseAttack(50), baseDefense(30), move1(nullptr), move2(nullptr), move3(nullptr)
{
}

Pokemon::Pokemon(PokemonSpecies sp): species(sp){ // constructor for all pokemon
    level = 1;
    exp = 0;
    initializeStats(sp);
    vector<Moves> selectedMoves = generateRandomMoves(type);
    // Initialize Moves
    move1 = new Attack(selectedMoves[0]); 
    move2 = new Attack(selectedMoves[1]); 
    move3 = new Attack(selectedMoves[2]); 
}

Pokemon::Pokemon(PokemonSpecies sp, int lvl, int EXP, Moves m1, Moves m2, Moves m3){
    species = sp;
    level = lvl;
    exp = EXP;
    initializeStats(sp);
    move1 = new Attack(m1); 
    move2 = new Attack(m2); 
    move3 = new Attack(m3); 
}

Pokemon::~Pokemon() {
    delete move1;
    delete move2;
    delete move3;
}

Pokemon& Pokemon::operator=(const Pokemon& other){
    if (this == &other) {
        return *this;
    }

    // Clean up dynamically allocated memory
    delete move1;
    delete move2;
    delete move3;

    // Copy all members from the other object
    species = other.species;
    type = other.type;
    level = other.level;
    exp = other.exp;
    baseHP = other.baseHP;
    baseAttack = other.baseAttack;
    baseDefense = other.baseDefense;

    // Deep copy of dynamically allocated memory
    move1 = other.move1 ? new Attack(*other.move1) : nullptr;
    move2 = other.move2 ? new Attack(*other.move2) : nullptr;
    move3 = other.move3 ? new Attack(*other.move3) : nullptr;

    return *this;
}

vector<Moves> Pokemon::generateRandomMoves(Type pokemonType) {
    static bool seeded = false;
    if (!seeded) {
        srand(time(0));  // Seed only once
        seeded = true;
    }
    vector<Moves> selectedMoves;
    vector<Moves> availableMoves;

    if (pokemonType != Type::Normal) {
        // Populate availableMoves based on Pokémon type
        if (pokemonType == Type::Fire) {
            availableMoves = fireTypeMoves;
        } else if (pokemonType == Type::Water) {
            availableMoves = waterTypeMoves;
        } else if (pokemonType == Type::Grass) {
            availableMoves = grassTypeMoves;
        }

        // Shuffle the available moves for random selection
        random_device rd;
        mt19937 g(rd());
        shuffle(availableMoves.begin(), availableMoves.end(), g);
    }
    else {
        availableMoves.insert(availableMoves.end(), fireTypeMoves.begin(), fireTypeMoves.end());
        availableMoves.insert(availableMoves.end(), waterTypeMoves.begin(), waterTypeMoves.end());
        availableMoves.insert(availableMoves.end(), grassTypeMoves.begin(), grassTypeMoves.end());
        availableMoves.insert(availableMoves.end(), normalTypeMoves.begin(), normalTypeMoves.end());
    }
    // Select the first two random moves
    selectedMoves.push_back(availableMoves[rand() % availableMoves.size()]);
    // Remove the selected move to avoid repetition
    availableMoves.erase(remove(availableMoves.begin(), availableMoves.end(), selectedMoves.back()), availableMoves.end());
    selectedMoves.push_back(availableMoves[rand() % availableMoves.size()]);
    // Add one random Normal-type move
    selectedMoves.push_back(normalTypeMoves[rand() % normalTypeMoves.size()]);

    return selectedMoves;
}

void Pokemon::displayInfo() {
    cout << "Species: " << speciesToString(species)
        << "\nType: " << typeToString(type)
        << "\nHP: " << getHP()
        << "\nAttack: " << getAttack()
        << "\nDefense: " << getDefense() 
        << "\nLevel: " << getLevel()
        << "\nEXP: " << getEXP()
        << "\nMove 1: " << move1->getName()
        << "\nMove 2: " << move2->getName()
        << "\nMove 3: " << move3->getName()<< "\n";
}

void Pokemon::initializeStats(PokemonSpecies sp){
    switch(sp){
    case PokemonSpecies::Bulbasaur:
        type = Type::Grass;
        baseHP = 45;
        baseAttack = 49;
        baseDefense = 49;
        exp = 64;
        growthRate = GrowthRate::Medium;
        baseCatchRate = 45; // Base catch rate for Bulbasaur
        break;
    case PokemonSpecies::Squirtle:
        type = Type::Water;
        baseHP = 44;
        baseAttack = 48;
        baseDefense = 65;
        exp = 63;
        growthRate = GrowthRate::Fast;
        baseCatchRate = 45; // Base catch rate for Squirtle
        break;
    case PokemonSpecies::Charmander:
        type = Type::Fire;
        baseHP = 39;
        baseAttack = 52;
        baseDefense = 43;
        exp = 62;
        growthRate = GrowthRate::Fast;
        baseCatchRate = 45; // Base catch rate for Charmander
        break;
    case PokemonSpecies::Pidgey:
        type = Type::Normal;
        baseHP = 40;
        baseAttack = 45;
        baseDefense = 40;
        exp = 50;
        growthRate = GrowthRate::Fast;
        baseCatchRate = 255; // Base catch rate for Pidgey
        break;
    case PokemonSpecies::Ivysaur:
        type = Type::Grass;
        baseHP = 60;
        baseAttack = 62;
        baseDefense = 63;
        exp = 142;
        growthRate = GrowthRate::Medium;
        baseCatchRate = 45; // Base catch rate for Ivysaur
        break;
    case PokemonSpecies::Horsea:
        type = Type::Water;
        baseHP = 30;
        baseAttack = 40;
        baseDefense = 35;
        exp = 61;
        growthRate = GrowthRate::Fast;
        baseCatchRate = 225; // Base catch rate for Horsea
        break;
    case PokemonSpecies::Vulpix:
        type = Type::Fire;
        baseHP = 38;
        baseAttack = 41;
        baseDefense = 40;
        exp = 60;
        growthRate = GrowthRate::Fast;
        baseCatchRate = 190; // Base catch rate for Vulpix
        break;
    case PokemonSpecies::Rattata:
        type = Type::Normal;
        baseHP = 30;
        baseAttack = 56;
        baseDefense = 35;
        exp = 30;
        growthRate = GrowthRate::Fast;
        baseCatchRate = 255; // Base catch rate for Rattata
        break;
    case PokemonSpecies::Venusaur:
        type = Type::Grass;
        baseHP = 80;
        baseAttack = 82;
        baseDefense = 83;
        exp = 236;
        growthRate = GrowthRate::Medium;
        baseCatchRate = 45; // Base catch rate for Venusaur
        break;
    case PokemonSpecies::Psyduck:
        type = Type::Water;
        baseHP = 50;
        baseAttack = 52;
        baseDefense = 48;
        exp = 64;
        growthRate = GrowthRate::Fast;
        baseCatchRate = 190; // Base catch rate for Psyduck
        break;
    case PokemonSpecies::Growlithe:
        type = Type::Fire;
        baseHP = 55;
        baseAttack = 70;
        baseDefense = 45;
        exp = 70;
        growthRate = GrowthRate::Fast;
        baseCatchRate = 190; // Base catch rate for Growlithe
        break;
    case PokemonSpecies::Spearow:
        type = Type::Normal;
        baseHP = 40;
        baseAttack = 60;
        baseDefense = 30;
        exp = 52;
        growthRate = GrowthRate::Fast;
        baseCatchRate = 255; // Base catch rate for Spearow
        break;
    case PokemonSpecies::Oddish:
        type = Type::Grass;
        baseHP = 45;
        baseAttack = 50;
        baseDefense = 55;
        exp = 64;
        growthRate = GrowthRate::Medium;
        baseCatchRate = 255; // Base catch rate for Oddish
        break;
    case PokemonSpecies::Tentacool:
        type = Type::Water;
        baseHP = 40;
        baseAttack = 40;
        baseDefense = 35;
        exp = 66;
        growthRate = GrowthRate::Fast;
        baseCatchRate = 190; // Base catch rate for Tentacool
        break;
    case PokemonSpecies::Ponyta:
        type = Type::Fire;
        baseHP = 50;
        baseAttack = 65;
        baseDefense = 40;
        exp = 67;
        growthRate = GrowthRate::Fast;
        baseCatchRate = 190; // Base catch rate for Ponyta
        break;
    case PokemonSpecies::Meowth:
        type = Type::Normal;
        baseHP = 40;
        baseAttack = 45;
        baseDefense = 35;
        exp = 58;
        growthRate = GrowthRate::Fast;
        baseCatchRate = 255; // Base catch rate for Meowth
        break;
        case PokemonSpecies::Gloom:
        type = Type::Grass;
        baseHP = 60;
        baseAttack = 65;
        baseDefense = 70;
        exp = 119;
        growthRate = GrowthRate::Medium;
        baseCatchRate = 45;  // Gloom base catch rate
        break;
    case PokemonSpecies::Staryu:
        type = Type::Water;
        baseHP = 30;
        baseAttack = 45;
        baseDefense = 50;
        exp = 60;
        growthRate = GrowthRate::Fast;
        baseCatchRate = 255;  // Staryu base catch rate
        break;
    case PokemonSpecies::Charmeleon:
        type = Type::Fire;
        baseHP = 58;
        baseAttack = 64;
        baseDefense = 50;
        exp = 142;
        growthRate = GrowthRate::Fast;
        baseCatchRate = 120;  // Charmeleon base catch rate
        break;
    case PokemonSpecies::Jigglypuff:
        type = Type::Normal;
        baseHP = 115;
        baseAttack = 45;
        baseDefense = 20;
        exp = 95;
        growthRate = GrowthRate::Medium;
        baseCatchRate = 170;  // Jigglypuff base catch rate
        break;
    case PokemonSpecies::Vileplume:
        type = Type::Grass;
        baseHP = 75;
        baseAttack = 70;
        baseDefense = 65;
        exp = 182;
        growthRate = GrowthRate::Medium;
        baseCatchRate = 45;  // Vileplume base catch rate
        break;
    case PokemonSpecies::Slowpoke:
        type = Type::Water;
        baseHP = 90;
        baseAttack = 65;
        baseDefense = 65;
        exp = 63;
        growthRate = GrowthRate::Slow;
        baseCatchRate = 190;  // Slowpoke base catch rate
        break;
    case PokemonSpecies::Rapidash:
        type = Type::Fire;
        baseHP = 65;
        baseAttack = 80;
        baseDefense = 50;
        exp = 175;
        growthRate = GrowthRate::Fast;
        baseCatchRate = 60;  // Rapidash base catch rate
        break;
    case PokemonSpecies::Farfetchd:
        type = Type::Normal;
        baseHP = 52;
        baseAttack = 65;
        baseDefense = 55;
        exp = 66;
        growthRate = GrowthRate::Fast;
        baseCatchRate = 255;  // Farfetch'd base catch rate
        break;
    case PokemonSpecies::Paras:
        type = Type::Grass;
        baseHP = 35;
        baseAttack = 70;
        baseDefense = 55;
        exp = 60;
        growthRate = GrowthRate::Medium;
        baseCatchRate = 255;  // Paras base catch rate
        break;
    case PokemonSpecies::Seel:
        type = Type::Water;
        baseHP = 65;
        baseAttack = 45;
        baseDefense = 55;
        exp = 65;
        growthRate = GrowthRate::Fast;
        baseCatchRate = 190;  // Seel base catch rate
        break;
    case PokemonSpecies::Magmar:
        type = Type::Fire;
        baseHP = 50;
        baseAttack = 95;
        baseDefense = 57;
        exp = 64;
        growthRate = GrowthRate::Fast;
        baseCatchRate = 45;  // Magmar base catch rate
        break;
    case PokemonSpecies::Raticate:
        type = Type::Normal;
        baseHP = 55;
        baseAttack = 81;
        baseDefense = 60;
        exp = 128;
        growthRate = GrowthRate::Fast;
        baseCatchRate = 255;  // Raticate base catch rate
        break;
    case PokemonSpecies::Parasect:
        type = Type::Grass;
        baseHP = 60;
        baseAttack = 95;
        baseDefense = 80;
        exp = 142;
        growthRate = GrowthRate::Medium;
        baseCatchRate = 120;  // Parasect base catch rate
        break;
    case PokemonSpecies::Wartortle:
        type = Type::Water;
        baseHP = 59;
        baseAttack = 63;
        baseDefense = 80;
        exp = 142;
        growthRate = GrowthRate::Fast;
        baseCatchRate = 45;  // Wartortle base catch rate
        break;
    case PokemonSpecies::Ninetales:
        type = Type::Fire;
        baseHP = 73;
        baseAttack = 76;
        baseDefense = 75;
        exp = 177;
        growthRate = GrowthRate::Fast;
        baseCatchRate = 75;  // Ninetales base catch rate
        break;
    case PokemonSpecies::Fearow:
        type = Type::Normal;
        baseHP = 65;
        baseAttack = 90;
        baseDefense = 60;
        exp = 152;
        growthRate = GrowthRate::Fast;
        baseCatchRate = 190;  // Fearow base catch rate
        break;
    case PokemonSpecies::Bellsprout:
        type = Type::Grass;
        baseHP = 50;
        baseAttack = 75;
        baseDefense = 35;
        exp = 64;
        growthRate = GrowthRate::Medium;
        baseCatchRate = 255;  // Bellsprout base catch rate
        break;
    case PokemonSpecies::Dewgong:
        type = Type::Water;
        baseHP = 90;
        baseAttack = 70;
        baseDefense = 65;
        exp = 166;
        growthRate = GrowthRate::Fast;
        baseCatchRate = 60;  // Dewgong base catch rate
        break;
    case PokemonSpecies::Flareon:
        type = Type::Fire;
        baseHP = 65;
        baseAttack = 130;
        baseDefense = 60;
        exp = 184;
        growthRate = GrowthRate::Fast;
        baseCatchRate = 45;  // Flareon base catch rate
        break;
    case PokemonSpecies::Wigglytuff:
        type = Type::Normal;
        baseHP = 140;
        baseAttack = 70;
        baseDefense = 45;
        exp = 260; // Base Experience for Wigglytuff
        growthRate = GrowthRate::Fast;
        baseCatchRate = 170;  // Wigglytuff base catch rate
        break;
    case PokemonSpecies::Weepinbell:
        type = Type::Grass;
        baseHP = 65;
        baseAttack = 90;
        baseDefense = 50;
        exp = 210; // Base Experience for Weepinbell
        growthRate = GrowthRate::Medium;
        baseCatchRate = 120;  // Weepinbell base catch rate
        break;
    case PokemonSpecies::Blastoise:
        type = Type::Water;
        baseHP = 79;
        baseAttack = 83;
        baseDefense = 100;
        exp = 265; // Base Experience for Blastoise
        growthRate = GrowthRate::Fast;
        baseCatchRate = 45;  // Blastoise base catch rate
        break;
    case PokemonSpecies::Arcanine:
        type = Type::Fire;
        baseHP = 90;
        baseAttack = 110;
        baseDefense = 80;
        exp = 235; // Base Experience for Arcanine
        growthRate = GrowthRate::Fast;
        baseCatchRate = 75;  // Arcanine base catch rate
        break;
    case PokemonSpecies::Persian:
        type = Type::Normal;
        baseHP = 65;
        baseAttack = 70;
        baseDefense = 60;
        exp = 166; // Base Experience for Persian
        growthRate = GrowthRate::Fast;
        baseCatchRate = 190;  // Persian base catch rate
        break;
    case PokemonSpecies::Victreebel:
        type = Type::Grass;
        baseHP = 75;
        baseAttack = 100;
        baseDefense = 70;
        exp = 220; // Base Experience for Victreebel
        growthRate = GrowthRate::Medium;
        baseCatchRate = 45;  // Victreebel base catch rate
        break;
    case PokemonSpecies::Lapras:
        type = Type::Water;
        baseHP = 130;
        baseAttack = 85;
        baseDefense = 80;
        exp = 187; // Base Experience for Lapras
        growthRate = GrowthRate::Slow;
        baseCatchRate = 60;  // Lapras base catch rate
        break;
    case PokemonSpecies::Charizard:
        type = Type::Fire;
        baseHP = 78;
        baseAttack = 84;
        baseDefense = 78;
        exp = 240; // Base Experience for Charizard
        growthRate = GrowthRate::Fast;
        baseCatchRate = 45;  // Charizard base catch rate
        break;
    case PokemonSpecies::Kangaskhan:
        type = Type::Normal;
        baseHP = 105;
        baseAttack = 95;
        baseDefense = 80;
        exp = 173; // Base Experience for Kangaskhan
        growthRate = GrowthRate::Fast;
        baseCatchRate = 45;  // Kangaskhan base catch rate
        break;
    case PokemonSpecies::Tangela:
        type = Type::Grass;
        baseHP = 65;
        baseAttack = 55;
        baseDefense = 115;
        exp = 87; // Base Experience for Tangela
        growthRate = GrowthRate::Medium;
        baseCatchRate = 45;  // Tangela base catch rate
        break;
    case PokemonSpecies::Gyarados:
        type = Type::Water;
        baseHP = 95;
        baseAttack = 125;
        baseDefense = 79;
        exp = 189; // Base Experience for Gyarados
        growthRate = GrowthRate::Slow;
        baseCatchRate = 45;  // Gyarados base catch rate
        break;
    case PokemonSpecies::Moltres:
        type = Type::Fire;
        baseHP = 90;
        baseAttack = 100;
        baseDefense = 90;
        exp = 261; // Base Experience for Moltres
        growthRate = GrowthRate::Fast;
        baseCatchRate = 3;  // Moltres base catch rate
        break;
    case PokemonSpecies::Snorlax:
        type = Type::Normal;
        baseHP = 160;
        baseAttack = 110;
        baseDefense = 65;
        exp = 189; // Base Experience for Snorlax
        growthRate = GrowthRate::Slow;
        baseCatchRate = 25;  // Snorlax base catch rate
        break;
    default:
        type = Type::Normal;
        baseHP = 0;
        baseAttack = 0;
        baseDefense = 0;
        exp = 0; // Default Base Experience
        growthRate = GrowthRate::Fast;
        baseCatchRate = 255;  // Default base catch rate
    }
    hp = calculateHP();
    attack = calculateAttack();
    defense = calculateDefense();
}

string Pokemon::speciesToString(PokemonSpecies species) {
    switch (species) {
        case PokemonSpecies::Bulbasaur: return "Bulbasaur";
        case PokemonSpecies::Squirtle: return "Squirtle";
        case PokemonSpecies::Charmander:  return "Charmander";
        case PokemonSpecies::Pidgey: return "Pidgey";
        case PokemonSpecies::Ivysaur: return "Ivysaur";
        case PokemonSpecies::Horsea: return "Horsea";
        case PokemonSpecies::Vulpix:      return "Vulpix";
        case PokemonSpecies::Rattata: return "Rattata";
        case PokemonSpecies::Venusaur: return "Venusaur";
        case PokemonSpecies::Psyduck: return "Psyduck";
        case PokemonSpecies::Growlithe:   return "Growlithe";
        case PokemonSpecies::Spearow: return "Spearow";
        case PokemonSpecies::Oddish: return "Oddish";
        case PokemonSpecies::Tentacool: return "Tentacool";
        case PokemonSpecies::Ponyta:      return "Ponyta";
        case PokemonSpecies::Meowth: return "Meowth";
        case PokemonSpecies::Gloom: return "Gloom";
        case PokemonSpecies::Staryu: return "Staryu";
        case PokemonSpecies::Charmeleon:  return "Charmeleon";
        case PokemonSpecies::Jigglypuff: return "Jigglypuff";
        case PokemonSpecies::Vileplume: return "Vileplume";
        case PokemonSpecies::Slowpoke: return "Slowpoke";
        case PokemonSpecies::Rapidash:    return "Rapidash";
        case PokemonSpecies::Farfetchd: return "Farfetch’d";
        case PokemonSpecies::Paras: return "Paras";
        case PokemonSpecies::Seel: return "Seel";
        case PokemonSpecies::Magmar:      return "Magmar";
        case PokemonSpecies::Raticate: return "Raticate";
        case PokemonSpecies::Parasect: return "Parasect";
        case PokemonSpecies::Wartortle: return "Wartortle";
        case PokemonSpecies::Ninetales:   return "Ninetales";
        case PokemonSpecies::Fearow: return "Fearow";
        case PokemonSpecies::Bellsprout: return "Bellsprout";
        case PokemonSpecies::Dewgong: return "Dewgong";
        case PokemonSpecies::Flareon:     return "Flareon";
        case PokemonSpecies::Wigglytuff: return "Wigglytuff";
        case PokemonSpecies::Weepinbell: return "Weepinbell";
        case PokemonSpecies::Blastoise: return "Blastoise";
        case PokemonSpecies::Arcanine:    return "Arcanine";
        case PokemonSpecies::Persian: return "Persian";
        case PokemonSpecies::Victreebel: return "Victreebel";
        case PokemonSpecies::Lapras: return "Lapras";
        case PokemonSpecies::Charizard:   return "Charizard";
        case PokemonSpecies::Kangaskhan: return "Kangaskhan";
        case PokemonSpecies::Tangela: return "Tangela";
        case PokemonSpecies::Gyarados: return "Gyarados";
        case PokemonSpecies::Moltres:     return "Moltres";
        case PokemonSpecies::Snorlax: return "Snorlax";
        default: return "Unknown";
    }
}

PokemonSpecies Pokemon::stringToSpecies(string& sp) {
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

Moves Pokemon::stringToMove(const string& move) {
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

string Pokemon::typeToString(Type type) {
    switch (type) {
        case Type::Normal:   return "Normal";
        case Type::Fire:     return "Fire";
        case Type::Water:    return "Water";
        case Type::Grass:    return "Grass";
        default: return "Unknown";
    }
}

int Pokemon::calculateDamage(Attack* move, Pokemon* attacker, Pokemon* defender) const {//this is the actual damage that will do to the opponent
    int damage = ( ( ( ( 2 * attacker->getLevel() / 5 ) + 2) * (move->getPower() * ( attacker->calculateAttack() / defender->calculateDefense()) ) ) / 50 ) + 2;
    if(move->isSuperEffective(defender->getType())){
        damage *= 2;
    }
    else if(move->isNotVeryEffective(defender->getType())){
        damage *= 0.5;
    }
    srand(time(0));
    if(rand() % 10000 <= 625){
        damage *= 1.5;
    }
    return damage * (85 + rand() % 30) / 100;
}

int Pokemon::calculateHP() const {
    return ( ( (2 * baseHP) * level ) / 100 ) + level + 10;
}
int Pokemon::calculateAttack() const {
    return ( ( ( 2 * baseAttack) * level ) / 100 ) + 5;
}
int Pokemon::calculateDefense() const {
    return ( ( (2 * baseDefense) * level ) / 100 ) + 5;
}
int Pokemon::calculateEXP(const Pokemon& defeatedPokemon) const{
    return exp * defeatedPokemon.level / 7;
}

PokemonSpecies Pokemon::getSpecies() const {
    return species;
}
Type Pokemon::getType() const {
    return type;
}
int Pokemon::getBaseCatchRate() const {
    return baseCatchRate;
}
int Pokemon::getBaseHP() const {
    return baseHP;
}
int Pokemon::getBaseAttack() const {
    return baseAttack;
}
int Pokemon::getBaseDefense() const {
    return baseDefense;
}
int Pokemon::getHP() const {
    return hp;
}
int Pokemon::getAttack() const {
    return attack;
}
int Pokemon::getDefense() const {
    return defense;
}
int Pokemon::getLevel() const{
    return level;
}
int Pokemon::getEXP() const {
    return exp;
}
Attack* Pokemon::getMove1() const{
    return move1;
}
Attack* Pokemon::getMove2() const{
    return move2;
}
Attack* Pokemon::getMove3() const{
    return move3;
}

void Pokemon::setSpecies(PokemonSpecies newSpecies) {
    species = newSpecies;
}
void Pokemon::setBaseHP(int val) {
    baseHP = val;
}
void Pokemon::setBaseAttack(int val) {
    baseAttack = val;
}
void Pokemon::setBaseDefense(int val) {
    baseDefense = val;
}
void Pokemon::setLevel(int val) {
    level = val;
    hp = calculateHP();
    attack = calculateAttack();
    defense = calculateDefense();
}
void Pokemon::setMove1(Attack* newMove) {
    move1 = newMove;
}
void Pokemon::setMove2(Attack* newMove) {
    move2 = newMove;
}
void Pokemon::setMove3(Attack* newMove) {
    move3 = newMove;
}

void Pokemon::addEXP(int val) {
    if(level >= 100){
        cout << speciesToString(species) << "is already lvl 100." << endl;
        return;
    }

    cout << speciesToString(species) << " gained " << val << " exp" << endl;
    exp += val;
    int requiredEXP = 0;

    while(true) {
        if (growthRate == GrowthRate::Fast) {
            requiredEXP = (4 * level * level * level) / 5;
        } else if (growthRate == GrowthRate::Medium) {
            requiredEXP = level * level * level;
        } else if (growthRate == GrowthRate::Slow) {
            requiredEXP = (5 * level * level * level) / 4;
        }

        if (exp >= requiredEXP) {
            cout << "Level Up!   " << level;
            addLevel();
            cout << "  ->  " << level << endl;
        } else {
            break; 
        }
    }
    
}

void Pokemon::addLevel(){
    level++;
    hp = calculateHP();
    attack = calculateAttack();
    defense = calculateDefense();
}