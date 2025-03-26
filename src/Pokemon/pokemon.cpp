#include "../../header/Pokemon/pokemon.h"
#include "../../header/Pokemon/attack.h"
#include <algorithm>
#include <random> 

vector<moves> fireTypeMoves = {moves::FireSpin, moves::Flamethrower, moves::FireBlast, moves::Ember, moves::FirePunch};
vector<moves> waterTypeMoves = {moves::Clamp, moves::Crabhammer, moves::HydroPump, moves::Surf, moves::WaterGun, moves::Waterfall, moves::Withdraw};
vector<moves> grassTypeMoves = {moves::Absorb, moves::LeechSeed, moves::MegaDrain, moves::PetalDance, moves::RazorLeaf, moves::SleepPowder, moves::SolarBeam, moves::Spore, moves::StunSpore, moves::VineWhip};
vector<moves> normalTypeMoves = {moves::Barrage, moves::Bide, moves::Bind, moves::BodySlam, moves::CometPunch, moves::Cut, moves::DefenseCurl, moves::DizzyPunch, moves::DoubleSlap, moves::DoubleEdge, moves::EggBomb, moves::Explosion, moves::FuryAttack, moves::FurySwipes, moves::Glare, moves::Growl, moves::Growth, moves::Guillotine, moves::Harden, moves::Headbutt, moves::HornAttack, moves::HornDrill, moves::HyperBeam, moves::HyperFang, moves::Leer, moves::LovelyKiss, moves::MegaKick, moves::MegaPunch, moves::Pound, moves::QuickAttack, moves::Rage, moves::RazorWind, moves::Recover, moves::Scratch, moves::Screech, moves::SelfDestruct, moves::Sharpen, moves::Sing, moves::SkullBash, moves::Slam, moves::Slash, moves::SoftBoiled, moves::SonicBoom, moves::SpikeCannon, moves::Splash, moves::Stomp, moves::Strength, moves::SuperFang, moves::Supersonic, moves::SwordsDance, moves::Tackle, moves::TailWhip, moves::TakeDown, moves::Thrash, moves::ViseGrip, moves::Wrap};

Pokemon::Pokemon() : species(PokemonSpecies::none), type(PokemonType::Normal), hp(100), attack(50), defense(30), move1(nullptr), move2(nullptr), move3(nullptr)
{
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
    //level = other.level;
    //exp = other.exp;
    hp = other.hp;
    attack = other.attack;
    defense = other.defense;

    // Deep copy of dynamically allocated memory
    move1 = other.move1 ? new Attack(*other.move1) : nullptr;
    move2 = other.move2 ? new Attack(*other.move2) : nullptr;
    move3 = other.move3 ? new Attack(*other.move3) : nullptr;

    return *this;
}

Pokemon::Pokemon(PokemonSpecies sp): species(sp){ // constructor for all pokemon
    level = 1;
    //exp = 0;
    initializeStats(sp);

    vector<moves> selectedMoves;
    if (type != PokemonType::Normal) {
        vector<moves> availableMoves;  // This will hold the type-specific moves

        // Populate availableMoves based on the Pokémon type
        if (type == PokemonType::Fire) {
            availableMoves = fireTypeMoves;
        } else if (type == PokemonType::Water) {
            availableMoves = waterTypeMoves;
        } else if (type == PokemonType::Grass) {
            availableMoves = grassTypeMoves;
        }

        // Shuffle the available moves for random selection
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(availableMoves.begin(), availableMoves.end(), g);

        // Select the first two random moves of the same type
        selectedMoves.push_back(availableMoves[0]);
        selectedMoves.push_back(availableMoves[1]);
    }

    // Add one random normal-type move
    selectedMoves.push_back(normalTypeMoves[rand() % normalTypeMoves.size()]);

    // Initialize moves
    move1 = new Attack(selectedMoves[0]); 
    move2 = new Attack(selectedMoves[1]); 
    move3 = new Attack(selectedMoves[2]); 
}

void Pokemon::displayInfo() {
    cout << "Species: " << speciesToString(species)
              << "\nType: " << typeToString(type)
              << "\nHP: " << gethp()
              << "\nBase Attack: " << getAttack()
              << "\nBase Defense: " << getDefense() 
              << "\n Move 1 name: " << move1->getName()
              << "\n Move 2 name: " << move2->getName()
              << "\n Move 3 name: " << move3->getName()<< "\n";
}

void Pokemon::initializeStats(PokemonSpecies sp){
    switch(sp){
    case PokemonSpecies::Bulbasaur:
        type = PokemonType::Grass;
        hp = 45;
        attack = 49;
        defense = 49;
        //exp = 64;
        
        break;
    case PokemonSpecies::Squirtle:
        type = PokemonType::Water;
        hp = 44;
        attack = 48;
        defense = 65;
        //exp = 63;
        
        break;
    case PokemonSpecies::Charmander:
        type = PokemonType::Fire;
        hp = 39;
        attack = 52;
        defense = 43;
        //exp = 62;
        
        break;
    case PokemonSpecies::Pidgey:
        type = PokemonType::Normal;
        hp = 40;
        attack = 45;
        defense = 40;
        //exp = 50;
        
        break;
    case PokemonSpecies::Ivysaur:
        type = PokemonType::Grass;
        hp = 60;
        attack = 62;
        defense = 63;
        //exp = 142;
        
        break;
    case PokemonSpecies::Horsea:
        type = PokemonType::Water;
        hp = 30;
        attack = 40;
        defense = 35;
        //exp = 61;
        
        break;
    case PokemonSpecies::Vulpix:
        type = PokemonType::Fire;
        hp = 38;
        attack = 41;
        defense = 40;
        //exp = 60;
        
        break;
    case PokemonSpecies::Rattata:
        type = PokemonType::Normal;
        hp = 30;
        attack = 56;
        defense = 35;
        //exp = 30;
        
        break;
    case PokemonSpecies::Venusaur:
        type = PokemonType::Grass;
        hp = 80;
        attack = 82;
        defense = 83;
        //exp = 236;
        
        break;
    case PokemonSpecies::Psyduck:
        type = PokemonType::Water;
        hp = 50;
        attack = 52;
        defense = 48;
        //exp = 64;
        
        break;
    case PokemonSpecies::Growlithe:
        type = PokemonType::Fire;
        hp = 55;
        attack = 70;
        defense = 45;
        //exp = 70;
        
        break;
    case PokemonSpecies::Spearow:
        type = PokemonType::Normal;
        hp = 40;
        attack = 60;
        defense = 30;
        //exp = 52;
        
        break;
    case PokemonSpecies::Oddish:
        type = PokemonType::Grass;
        hp = 45;
        attack = 50;
        defense = 55;
        //exp = 64;
        
        break;
    case PokemonSpecies::Tentacool:
        type = PokemonType::Water;
        hp = 40;
        attack = 40;
        defense = 35;
        //exp = 66;
        
        break;
    case PokemonSpecies::Ponyta:
        type = PokemonType::Fire;
        hp = 50;
        attack = 65;
        defense = 40;
        //exp = 67;
        
        break;
    case PokemonSpecies::Meowth:
        type = PokemonType::Normal;
        hp = 40;
        attack = 45;
        defense = 35;
        //exp = 58;
        
        break;
    case PokemonSpecies::Gloom:
        type = PokemonType::Grass;
        hp = 60;
        attack = 65;
        defense = 70;
        //exp = 119;
        
        break;
    case PokemonSpecies::Staryu:
        type = PokemonType::Water;
        hp = 30;
        attack = 45;
        defense = 50;
        //exp = 60;
        
        break;
    case PokemonSpecies::Charmeleon:
        type = PokemonType::Fire;
        hp = 58;
        attack = 64;
        defense = 50;
        //exp = 142;
        
        break;
    case PokemonSpecies::Jigglypuff:
        type = PokemonType::Normal;
        hp = 115;
        attack = 45;
        defense = 20;
        //exp = 95;
        
        break;
    case PokemonSpecies::Vileplume:
        type = PokemonType::Grass;
        hp = 75;
        attack = 70;
        defense = 65;
        //exp = 182;
        
        break;
    case PokemonSpecies::Slowpoke:
        type = PokemonType::Water;
        hp = 90;
        attack = 65;
        defense = 65;
        //exp = 63;
        
        break;
    case PokemonSpecies::Rapidash:
        type = PokemonType::Fire;
        hp = 65;
        attack = 80;
        defense = 50;
        //exp = 175;
        
        break;
    case PokemonSpecies::Farfetchd:
        type = PokemonType::Normal;
        hp = 52;
        attack = 65;
        defense = 55;
        //exp = 66;
        
        break;
    case PokemonSpecies::Paras:
        type = PokemonType::Grass;
        hp = 35;
        attack = 70;
        defense = 55;
        //exp = 60;
        
        break;
    case PokemonSpecies::Seel:
        type = PokemonType::Water;
        hp = 65;
        attack = 45;
        defense = 55;
        //exp = 65;
        
        break;
    case PokemonSpecies::Magmar:
        type = PokemonType::Fire;
        hp = 50;
        attack = 95;
        defense = 57;
        //exp = 64;
        
        break;
    case PokemonSpecies::Raticate:
        type = PokemonType::Normal;
        hp = 55;
        attack = 81;
        defense = 60;
        //exp = 128;
        
        break;
    case PokemonSpecies::Parasect:
        type = PokemonType::Grass;
        hp = 60;
        attack = 95;
        defense = 80;
        //exp = 142;
        
        break;
    case PokemonSpecies::Wartortle:
        type = PokemonType::Water;
        hp = 59;
        attack = 63;
        defense = 80;
        //exp = 142;
        
        break;
    case PokemonSpecies::Ninetales:
        type = PokemonType::Fire;
        hp = 73;
        attack = 76;
        defense = 75;
        //exp = 177;
        
        break;
    case PokemonSpecies::Fearow:
        type = PokemonType::Normal;
        hp = 65;
        attack = 90;
        defense = 60;
        //exp = 152;
        
        break;
    case PokemonSpecies::Bellsprout:
        type = PokemonType::Grass;
        hp = 50;
        attack = 75;
        defense = 35;
        //exp = 64;
        
        break;
    case PokemonSpecies::Dewgong:
        type = PokemonType::Water;
        hp = 90;
        attack = 70;
        defense = 65;
        //exp = 166;
        
        break;
    case PokemonSpecies::Flareon:
        type = PokemonType::Fire;
        hp = 65;
        attack = 130;
        defense = 60;
        //exp = 184;
        
        break;
    case PokemonSpecies::Wigglytuff:
        type = PokemonType::Normal;
        hp = 140;
        attack = 70;
        defense = 45;
        //exp = 260; // Base Experience for Wigglytuff
        
        break;
    case PokemonSpecies::Weepinbell:
        type = PokemonType::Grass;
        hp = 65;
        attack = 90;
        defense = 50;
        //exp = 210; // Base Experience for Weepinbell
        
        break;
    case PokemonSpecies::Blastoise:
        type = PokemonType::Water;
        hp = 79;
        attack = 83;
        defense = 100;
        //exp = 265; // Base Experience for Blastoise
        
        break;
    case PokemonSpecies::Arcanine:
        type = PokemonType::Fire;
        hp = 90;
        attack = 110;
        defense = 80;
        //exp = 235; // Base Experience for Arcanine
        
        break;
    case PokemonSpecies::Persian:
        type = PokemonType::Normal;
        hp = 65;
        attack = 70;
        defense = 60;
        //exp = 166; // Base Experience for Persian
        
        break;
    case PokemonSpecies::Victreebel:
        type = PokemonType::Grass;
        hp = 75;
        attack = 100;
        defense = 70;
        //exp = 220; // Base Experience for Victreebel
        
        break;
    case PokemonSpecies::Lapras:
        type = PokemonType::Water;
        hp = 130;
        attack = 85;
        defense = 80;
        //exp = 187; // Base Experience for Lapras
        
        break;
    case PokemonSpecies::Charizard:
        type = PokemonType::Fire;
        hp = 78;
        attack = 84;
        defense = 78;
        //exp = 240; // Base Experience for Charizard
        
        break;
    case PokemonSpecies::Kangaskhan:
        type = PokemonType::Normal;
        hp = 105;
        attack = 95;
        defense = 80;
        //exp = 173; // Base Experience for Kangaskhan
        
        break;
    case PokemonSpecies::Tangela:
        type = PokemonType::Grass;
        hp = 65;
        attack = 55;
        defense = 115;
        //exp = 87; // Base Experience for Tangela
        
        break;
    case PokemonSpecies::Gyarados:
        type = PokemonType::Water;
        hp = 95;
        attack = 125;
        defense = 79;
        //exp = 189; // Base Experience for Gyarados
        
        break;
    case PokemonSpecies::Moltres:
        type = PokemonType::Fire;
        hp = 90;
        attack = 100;
        defense = 90;
        //exp = 261; // Base Experience for Moltres
        
        break;
    case PokemonSpecies::Snorlax:
        type = PokemonType::Normal;
        hp = 160;
        attack = 110;
        defense = 65;
        //exp = 189; // Base Experience for Snorlax
        
        break;
    default:
        type = PokemonType::Normal;
        hp = 0;
        attack = 0;
        defense = 0;
        //exp = 0; // Default Base Experience
        
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

string Pokemon::typeToString(PokemonType type) {
    switch (type) {
        case PokemonType::Normal:   return "Normal";
        case PokemonType::Fire:     return "Fire";
        case PokemonType::Water:    return "Water";
        case PokemonType::Grass:    return "Grass";
        default: return "Unknown";
    }
}

int Pokemon::calculateDamage(Attack* move, Pokemon* attacker, Pokemon* defender) const {//this is the actual damage that will do to the opponent
    int damage = ( ( ( ( 2 * attacker->getLevel() / 5 ) + 2) * (move->getPower() * ( attacker->calculateAttack() / defender->calculateDefense()) ) ) / 50 ) + 2;
    if(attacker->isTypeEffective(defender)){
        damage *= 2;
    }
    else if(attacker->isTypeNotEffective(defender)){
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

bool Pokemon::isTypeEffective(Pokemon* defender) {
    // Super effective relationships
    if ((type == PokemonType::Fire && defender->type == PokemonType::Grass) ||
        (type == PokemonType::Water && defender->type == PokemonType::Fire) ||
        (type == PokemonType::Grass && defender->type == PokemonType::Water))
        return true;
    return false;
}
bool Pokemon::isTypeNotEffective(Pokemon* defender) {
    // Not very effective relationships
    if ((type == PokemonType::Fire && defender->type == PokemonType::Water) ||
        (type == PokemonType::Water && defender->type == PokemonType::Grass) ||
        (type == PokemonType::Grass && defender->type == PokemonType::Fire))
        return true;
    return false;
}

PokemonSpecies Pokemon::getSpecies() const {
    return species;
}
PokemonType Pokemon::getType() const {
    return type;
}
int Pokemon::gethp(){
    return hp;
}
int Pokemon::getAttack(){
    return attack;
}
int Pokemon::getDefense(){
    return defense;
}
int Pokemon::getLevel() const{
    return level;
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