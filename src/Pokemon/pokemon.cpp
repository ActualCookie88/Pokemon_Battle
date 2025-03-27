#include "../../header/Pokemon/pokemon.h"
#include "../../header/Pokemon/attack.h"
#include <algorithm>
#include <random> 

vector<Moves> fireTypeMoves = {Moves::FireSpin, Moves::Flamethrower, Moves::FireBlast, Moves::Ember, Moves::FirePunch};
vector<Moves> waterTypeMoves = {Moves::Clamp, Moves::Crabhammer, Moves::HydroPump, Moves::Surf, Moves::WaterGun, Moves::Waterfall, Moves::Withdraw};
vector<Moves> grassTypeMoves = {Moves::Absorb, Moves::LeechSeed, Moves::MegaDrain, Moves::PetalDance, Moves::RazorLeaf, Moves::SleepPowder, Moves::SolarBeam, Moves::Spore, Moves::StunSpore, Moves::VineWhip};
vector<Moves> normalTypeMoves = {
    Moves::Barrage, Moves::Bide, Moves::Bind, Moves::BodySlam, Moves::CometPunch, Moves::Cut, Moves::DefenseCurl, Moves::DizzyPunch, Moves::DoubleSlap, Moves::DoubleEdge, Moves::EggBomb, Moves::Explosion, 
    Moves::FuryAttack, Moves::FurySwipes, Moves::Glare, Moves::Growl, Moves::Growth, Moves::Guillotine, Moves::Harden, Moves::Headbutt, Moves::HornAttack, Moves::HornDrill, Moves::HyperBeam, Moves::HyperFang, 
    Moves::Leer, Moves::LovelyKiss, Moves::MegaKick, Moves::MegaPunch, Moves::Pound, Moves::QuickAttack, Moves::Rage, Moves::RazorWind, Moves::Recover, Moves::Scratch, Moves::Screech, Moves::SelfDestruct, 
    Moves::Sharpen, Moves::Sing, Moves::SkullBash, Moves::Slam, Moves::Slash, Moves::SoftBoiled, Moves::SonicBoom, Moves::SpikeCannon, Moves::Splash, Moves::Stomp, Moves::Strength, Moves::SuperFang, 
    Moves::Supersonic, Moves::SwordsDance, Moves::Tackle, Moves::TailWhip, Moves::TakeDown, Moves::Thrash, Moves::ViseGrip, Moves::Wrap};

Pokemon::Pokemon() : species(PokemonSpecies::none), type(Type::Normal), hp(100), attack(50), defense(30), move1(nullptr), move2(nullptr), move3(nullptr)
{
}

Pokemon::Pokemon(PokemonSpecies sp): species(sp){ // constructor for all pokemon
    level = 1;
    exp = 0;
    initializeStats(sp);

    vector<Moves> selectedMoves;
    if (type != Type::Normal) {
        vector<Moves> availableMoves;  // This will hold the type-specific Moves

        // Populate availableMoves based on the Pokémon type
        if (type == Type::Fire) {
            availableMoves = fireTypeMoves;
        } else if (type == Type::Water) {
            availableMoves = waterTypeMoves;
        } else if (type == Type::Grass) {
            availableMoves = grassTypeMoves;
        }

        // Shuffle the available Moves for random selection
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(availableMoves.begin(), availableMoves.end(), g);

        // Select the first two random Moves of the same type
        selectedMoves.push_back(availableMoves[0]);
        selectedMoves.push_back(availableMoves[1]);
    }

    // Add one random normal-type move
    selectedMoves.push_back(normalTypeMoves[rand() % normalTypeMoves.size()]);

    // Initialize Moves
    move1 = new Attack(selectedMoves[0]); 
    move2 = new Attack(selectedMoves[1]); 
    move3 = new Attack(selectedMoves[2]); 
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
    hp = other.hp;
    attack = other.attack;
    defense = other.defense;

    // Deep copy of dynamically allocated memory
    move1 = other.move1 ? new Attack(*other.move1) : nullptr;
    move2 = other.move2 ? new Attack(*other.move2) : nullptr;
    move3 = other.move3 ? new Attack(*other.move3) : nullptr;

    return *this;
}


void Pokemon::displayInfo() {
    cout << "Species: " << speciesToString(species)
        << "\nType: " << typeToString(type)
        << "\nHP: " << gethp()
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
        hp = 45;
        attack = 49;
        defense = 49;
        exp = 64;
        growthRate = GrowthRate::Medium;
        break;
    case PokemonSpecies::Squirtle:
        type = Type::Water;
        hp = 44;
        attack = 48;
        defense = 65;
        exp = 63;
        growthRate = GrowthRate::Fast;
        break;
    case PokemonSpecies::Charmander:
        type = Type::Fire;
        hp = 39;
        attack = 52;
        defense = 43;
        exp = 62;
        growthRate = GrowthRate::Fast;
        break;
    case PokemonSpecies::Pidgey:
        type = Type::Normal;
        hp = 40;
        attack = 45;
        defense = 40;
        exp = 50;
        growthRate = GrowthRate::Fast;
        break;
    case PokemonSpecies::Ivysaur:
        type = Type::Grass;
        hp = 60;
        attack = 62;
        defense = 63;
        exp = 142;
        growthRate = GrowthRate::Medium;
        break;
    case PokemonSpecies::Horsea:
        type = Type::Water;
        hp = 30;
        attack = 40;
        defense = 35;
        exp = 61;
        growthRate = GrowthRate::Fast;
        break;
    case PokemonSpecies::Vulpix:
        type = Type::Fire;
        hp = 38;
        attack = 41;
        defense = 40;
        exp = 60;
        growthRate = GrowthRate::Fast;
        break;
    case PokemonSpecies::Rattata:
        type = Type::Normal;
        hp = 30;
        attack = 56;
        defense = 35;
        exp = 30;
        growthRate = GrowthRate::Fast;
        break;
    case PokemonSpecies::Venusaur:
        type = Type::Grass;
        hp = 80;
        attack = 82;
        defense = 83;
        exp = 236;
        growthRate = GrowthRate::Medium;
        break;
    case PokemonSpecies::Psyduck:
        type = Type::Water;
        hp = 50;
        attack = 52;
        defense = 48;
        exp = 64;
        growthRate = GrowthRate::Fast;
        break;
    case PokemonSpecies::Growlithe:
        type = Type::Fire;
        hp = 55;
        attack = 70;
        defense = 45;
        exp = 70;
        growthRate = GrowthRate::Fast;
        break;
    case PokemonSpecies::Spearow:
        type = Type::Normal;
        hp = 40;
        attack = 60;
        defense = 30;
        exp = 52;
        growthRate = GrowthRate::Fast;
        break;
    case PokemonSpecies::Oddish:
        type = Type::Grass;
        hp = 45;
        attack = 50;
        defense = 55;
        exp = 64;
        growthRate = GrowthRate::Medium;
        break;
    case PokemonSpecies::Tentacool:
        type = Type::Water;
        hp = 40;
        attack = 40;
        defense = 35;
        exp = 66;
        growthRate = GrowthRate::Fast;
        break;
    case PokemonSpecies::Ponyta:
        type = Type::Fire;
        hp = 50;
        attack = 65;
        defense = 40;
        exp = 67;
        growthRate = GrowthRate::Fast;
        break;
    case PokemonSpecies::Meowth:
        type = Type::Normal;
        hp = 40;
        attack = 45;
        defense = 35;
        exp = 58;
        growthRate = GrowthRate::Fast;
        break;
    case PokemonSpecies::Gloom:
        type = Type::Grass;
        hp = 60;
        attack = 65;
        defense = 70;
        exp = 119;
        growthRate = GrowthRate::Medium;
        break;
    case PokemonSpecies::Staryu:
        type = Type::Water;
        hp = 30;
        attack = 45;
        defense = 50;
        exp = 60;
        growthRate = GrowthRate::Fast;
        break;
    case PokemonSpecies::Charmeleon:
        type = Type::Fire;
        hp = 58;
        attack = 64;
        defense = 50;
        exp = 142;
        growthRate = GrowthRate::Fast;
        break;
    case PokemonSpecies::Jigglypuff:
        type = Type::Normal;
        hp = 115;
        attack = 45;
        defense = 20;
        exp = 95;
        growthRate = GrowthRate::Medium;
        break;
    case PokemonSpecies::Vileplume:
        type = Type::Grass;
        hp = 75;
        attack = 70;
        defense = 65;
        exp = 182;
        growthRate = GrowthRate::Medium;
        break;
    case PokemonSpecies::Slowpoke:
        type = Type::Water;
        hp = 90;
        attack = 65;
        defense = 65;
        exp = 63;
        growthRate = GrowthRate::Slow;
        break;
    case PokemonSpecies::Rapidash:
        type = Type::Fire;
        hp = 65;
        attack = 80;
        defense = 50;
        exp = 175;
        growthRate = GrowthRate::Fast;
        break;
    case PokemonSpecies::Farfetchd:
        type = Type::Normal;
        hp = 52;
        attack = 65;
        defense = 55;
        exp = 66;
        growthRate = GrowthRate::Fast;
        break;
    case PokemonSpecies::Paras:
        type = Type::Grass;
        hp = 35;
        attack = 70;
        defense = 55;
        exp = 60;
        growthRate = GrowthRate::Medium;
        break;
    case PokemonSpecies::Seel:
        type = Type::Water;
        hp = 65;
        attack = 45;
        defense = 55;
        exp = 65;
        growthRate = GrowthRate::Fast;
        break;
    case PokemonSpecies::Magmar:
        type = Type::Fire;
        hp = 50;
        attack = 95;
        defense = 57;
        exp = 64;
        growthRate = GrowthRate::Fast;
        break;
    case PokemonSpecies::Raticate:
        type = Type::Normal;
        hp = 55;
        attack = 81;
        defense = 60;
        exp = 128;
        growthRate = GrowthRate::Fast;
        break;
    case PokemonSpecies::Parasect:
        type = Type::Grass;
        hp = 60;
        attack = 95;
        defense = 80;
        exp = 142;
        growthRate = GrowthRate::Medium;
        break;
    case PokemonSpecies::Wartortle:
        type = Type::Water;
        hp = 59;
        attack = 63;
        defense = 80;
        exp = 142;
        growthRate = GrowthRate::Fast;
        break;
    case PokemonSpecies::Ninetales:
        type = Type::Fire;
        hp = 73;
        attack = 76;
        defense = 75;
        exp = 177;
        growthRate = GrowthRate::Fast;
        break;
    case PokemonSpecies::Fearow:
        type = Type::Normal;
        hp = 65;
        attack = 90;
        defense = 60;
        exp = 152;
        growthRate = GrowthRate::Fast;
        break;
    case PokemonSpecies::Bellsprout:
        type = Type::Grass;
        hp = 50;
        attack = 75;
        defense = 35;
        exp = 64;
        growthRate = GrowthRate::Medium;
        break;
    case PokemonSpecies::Dewgong:
        type = Type::Water;
        hp = 90;
        attack = 70;
        defense = 65;
        exp = 166;
        growthRate = GrowthRate::Fast;
        break;
    case PokemonSpecies::Flareon:
        type = Type::Fire;
        hp = 65;
        attack = 130;
        defense = 60;
        exp = 184;
        growthRate = GrowthRate::Fast;
        break;
    case PokemonSpecies::Wigglytuff:
        type = Type::Normal;
        hp = 140;
        attack = 70;
        defense = 45;
        exp = 260; // Base Experience for Wigglytuff
        growthRate = GrowthRate::Fast;
        break;
    case PokemonSpecies::Weepinbell:
        type = Type::Grass;
        hp = 65;
        attack = 90;
        defense = 50;
        exp = 210; // Base Experience for Weepinbell
        growthRate = GrowthRate::Medium;
        break;
    case PokemonSpecies::Blastoise:
        type = Type::Water;
        hp = 79;
        attack = 83;
        defense = 100;
        exp = 265; // Base Experience for Blastoise
        growthRate = GrowthRate::Fast;
        break;
    case PokemonSpecies::Arcanine:
        type = Type::Fire;
        hp = 90;
        attack = 110;
        defense = 80;
        exp = 235; // Base Experience for Arcanine
        growthRate = GrowthRate::Fast;
        break;
    case PokemonSpecies::Persian:
        type = Type::Normal;
        hp = 65;
        attack = 70;
        defense = 60;
        exp = 166; // Base Experience for Persian
        growthRate = GrowthRate::Fast;
        break;
    case PokemonSpecies::Victreebel:
        type = Type::Grass;
        hp = 75;
        attack = 100;
        defense = 70;
        exp = 220; // Base Experience for Victreebel
        growthRate = GrowthRate::Medium;
        break;
    case PokemonSpecies::Lapras:
        type = Type::Water;
        hp = 130;
        attack = 85;
        defense = 80;
        exp = 187; // Base Experience for Lapras
        growthRate = GrowthRate::Slow;
        break;
    case PokemonSpecies::Charizard:
        type = Type::Fire;
        hp = 78;
        attack = 84;
        defense = 78;
        exp = 240; // Base Experience for Charizard
        growthRate = GrowthRate::Fast;
        break;
    case PokemonSpecies::Kangaskhan:
        type = Type::Normal;
        hp = 105;
        attack = 95;
        defense = 80;
        exp = 173; // Base Experience for Kangaskhan
        growthRate = GrowthRate::Fast;
        break;
    case PokemonSpecies::Tangela:
        type = Type::Grass;
        hp = 65;
        attack = 55;
        defense = 115;
        exp = 87; // Base Experience for Tangela
        growthRate = GrowthRate::Medium;
        break;
    case PokemonSpecies::Gyarados:
        type = Type::Water;
        hp = 95;
        attack = 125;
        defense = 79;
        exp = 189; // Base Experience for Gyarados
        growthRate = GrowthRate::Slow;
        break;
    case PokemonSpecies::Moltres:
        type = Type::Fire;
        hp = 90;
        attack = 100;
        defense = 90;
        exp = 261; // Base Experience for Moltres
        growthRate = GrowthRate::Fast;
        break;
    case PokemonSpecies::Snorlax:
        type = Type::Normal;
        hp = 160;
        attack = 110;
        defense = 65;
        exp = 189; // Base Experience for Snorlax
        growthRate = GrowthRate::Slow;
        break;
    default:
        type = Type::Normal;
        hp = 0;
        attack = 0;
        defense = 0;
        exp = 0; // Default Base Experience
        growthRate = GrowthRate::Fast;
    }
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

int Pokemon::calculateHP() const{
    return ( ( (2 * hp) * level ) / 100 ) + level + 10;
}
int Pokemon::calculateAttack() const{
    return ( ( ( 2 * attack) * level ) / 100 ) + 5;
}
int Pokemon::calculateDefense() const{
    return ( ( (2 * defense) * level ) / 100 ) + 5;
}
int Pokemon::calculateEXP(Pokemon defeatedPokemon) const{
    return exp * defeatedPokemon.level / 7;
}

PokemonSpecies Pokemon::getSpecies() const {
    return species;
}
Type Pokemon::getType() const {
    return type;
}
int Pokemon::gethp() const {
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

void Pokemon::addEXP(int val) {
    if(level >= 100){
        cout << speciesToString(species) << "is already lvl 100." << endl;
        return;
    }
    cout << speciesToString(species) << " gained " << val << " exp" << endl;
    exp += val;
    if(growthRate == GrowthRate::Fast){
        if(exp == level * level * level){
            cout << "Level Up!   " << level;
            addLevel();
            cout << "  ->  " << level << endl;
        }
    }
    else if(growthRate == GrowthRate::Medium){
        if(exp == 1.2 * level * level * level - 15 * level * level + 100 * level - 140){
            cout << "Level Up!   " << level;
            addLevel();
            cout << "  ->  " << level << endl;
        }
    }
    else if(growthRate == GrowthRate::Slow){
        if(exp == 1.25 * level * level * level){
            cout << "Level Up!   " << level;
            addLevel();
            cout << "  ->  " << level << endl;
        }
    }
}

void Pokemon::addLevel(){
    level++;
}