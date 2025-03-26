#include "../../header/Pokemon/pokemon.h"
#include "../../header/Pokemon/attack.h"
#include <algorithm>
#include <random> 
vector<moves> fireTypeMoves= {moves::FireSpin, moves::Flamethrower, moves::FireBlast, moves::Ember, moves::FirePunch};
vector<moves> waterTypeMoves = {moves::Clamp, moves::Crabhammer, moves::HydroPump, moves::Surf, moves::WaterGun, moves::Waterfall, moves::Withdraw};
vector<moves> grassTypeMoves = {moves::Absorb, moves::LeechSeed, moves::MegaDrain, moves::PetalDance, moves::RazorLeaf, moves::SleepPowder, moves::SolarBeam, moves::Spore, moves::StunSpore, moves::VineWhip};
vector<moves> normalTypeMoves = {moves::Barrage, moves::Bide, moves::Bind, moves::BodySlam, moves::CometPunch, moves::Cut, moves::DefenseCurl, moves::DizzyPunch, moves::DoubleSlap, moves::DoubleEdge, moves::EggBomb, moves::Explosion, moves::FuryAttack, moves::FurySwipes, moves::Glare, moves::Growl, moves::Growth, moves::Guillotine, moves::Harden, moves::Headbutt, moves::HornAttack, moves::HornDrill, moves::HyperBeam, moves::HyperFang, moves::Leer, moves::LovelyKiss, moves::MegaKick, moves::MegaPunch, moves::Pound, moves::QuickAttack, moves::Rage, moves::RazorWind, moves::Recover, moves::Scratch, moves::Screech, moves::SelfDestruct, moves::Sharpen, moves::Sing, moves::SkullBash, moves::Slam, moves::Slash, moves::SoftBoiled, moves::SonicBoom, moves::SpikeCannon, moves::Splash, moves::Stomp, moves::Strength, moves::SuperFang, moves::Supersonic, moves::SwordsDance, moves::Tackle, moves::TailWhip, moves::TakeDown, moves::Thrash, moves::ViseGrip, moves::Wrap};
Pokemon::Pokemon(PokemonSpecies sp): species(sp){//constructor for all pokemon
    level=1;
    exp=0;
    initializeStats(sp);
    IV=rand()%31;
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
Pokemon::Pokemon(PokemonSpecies sp, int lvl, int EXP, int iv, moves m1, moves m2, moves m3){//constructor for all pokemon
    species=sp;
    level=lvl;
    exp=EXP;
    initializeStats(sp);
    IV=iv;
    move1 = new Attack(m1); 
    move2 = new Attack(m2); 
    move3 = new Attack(m3); 

}

void Pokemon::initializeStats(PokemonSpecies sp){
    switch(sp){
    case PokemonSpecies::Bulbasaur:
        type = PokemonType::Grass;
        baseHP = 45;
        baseAttack = 49;
        baseDefense = 49;
        baseEXP = 64;
        GR = GrowthRate::Medium;
        break;
    case PokemonSpecies::Squirtle:
        type = PokemonType::Water;
        baseHP = 44;
        baseAttack = 48;
        baseDefense = 65;
        baseEXP = 63;
        GR = GrowthRate::Fast;
        break;
    case PokemonSpecies::Charmander:
        type = PokemonType::Fire;
        baseHP = 39;
        baseAttack = 52;
        baseDefense = 43;
        baseEXP = 62;
        GR = GrowthRate::Fast;
        break;
    case PokemonSpecies::Pidgey:
        type = PokemonType::Normal;
        baseHP = 40;
        baseAttack = 45;
        baseDefense = 40;
        baseEXP = 50;
        GR = GrowthRate::Fast;
        break;
    case PokemonSpecies::Ivysaur:
        type = PokemonType::Grass;
        baseHP = 60;
        baseAttack = 62;
        baseDefense = 63;
        baseEXP = 142;
        GR = GrowthRate::Medium;
        break;
    case PokemonSpecies::Horsea:
        type = PokemonType::Water;
        baseHP = 30;
        baseAttack = 40;
        baseDefense = 35;
        baseEXP = 61;
        GR = GrowthRate::Fast;
        break;
    case PokemonSpecies::Vulpix:
        type = PokemonType::Fire;
        baseHP = 38;
        baseAttack = 41;
        baseDefense = 40;
        baseEXP = 60;
        GR = GrowthRate::Fast;
        break;
    case PokemonSpecies::Rattata:
        type = PokemonType::Normal;
        baseHP = 30;
        baseAttack = 56;
        baseDefense = 35;
        baseEXP = 30;
        GR = GrowthRate::Fast;
        break;
    case PokemonSpecies::Venusaur:
        type = PokemonType::Grass;
        baseHP = 80;
        baseAttack = 82;
        baseDefense = 83;
        baseEXP = 236;
        GR = GrowthRate::Medium;
        break;
    case PokemonSpecies::Psyduck:
        type = PokemonType::Water;
        baseHP = 50;
        baseAttack = 52;
        baseDefense = 48;
        baseEXP = 64;
        GR = GrowthRate::Fast;
        break;
    case PokemonSpecies::Growlithe:
        type = PokemonType::Fire;
        baseHP = 55;
        baseAttack = 70;
        baseDefense = 45;
        baseEXP = 70;
        GR = GrowthRate::Fast;
        break;
    case PokemonSpecies::Spearow:
        type = PokemonType::Normal;
        baseHP = 40;
        baseAttack = 60;
        baseDefense = 30;
        baseEXP = 52;
        GR = GrowthRate::Fast;
        break;
    case PokemonSpecies::Oddish:
        type = PokemonType::Grass;
        baseHP = 45;
        baseAttack = 50;
        baseDefense = 55;
        baseEXP = 64;
        GR = GrowthRate::Medium;
        break;
    case PokemonSpecies::Tentacool:
        type = PokemonType::Water;
        baseHP = 40;
        baseAttack = 40;
        baseDefense = 35;
        baseEXP = 66;
        GR = GrowthRate::Fast;
        break;
    case PokemonSpecies::Ponyta:
        type = PokemonType::Fire;
        baseHP = 50;
        baseAttack = 65;
        baseDefense = 40;
        baseEXP = 67;
        GR = GrowthRate::Fast;
        break;
    case PokemonSpecies::Meowth:
        type = PokemonType::Normal;
        baseHP = 40;
        baseAttack = 45;
        baseDefense = 35;
        baseEXP = 58;
        GR = GrowthRate::Fast;
        break;
    case PokemonSpecies::Gloom:
        type = PokemonType::Grass;
        baseHP = 60;
        baseAttack = 65;
        baseDefense = 70;
        baseEXP = 119;
        GR = GrowthRate::Medium;
        break;
    case PokemonSpecies::Staryu:
        type = PokemonType::Water;
        baseHP = 30;
        baseAttack = 45;
        baseDefense = 50;
        baseEXP = 60;
        GR = GrowthRate::Fast;
        break;
    case PokemonSpecies::Charmeleon:
        type = PokemonType::Fire;
        baseHP = 58;
        baseAttack = 64;
        baseDefense = 50;
        baseEXP = 142;
        GR = GrowthRate::Fast;
        break;
    case PokemonSpecies::Jigglypuff:
        type = PokemonType::Normal;
        baseHP = 115;
        baseAttack = 45;
        baseDefense = 20;
        baseEXP = 95;
        GR = GrowthRate::Medium;
        break;
    case PokemonSpecies::Vileplume:
        type = PokemonType::Grass;
        baseHP = 75;
        baseAttack = 70;
        baseDefense = 65;
        baseEXP = 182;
        GR = GrowthRate::Medium;
        break;
    case PokemonSpecies::Slowpoke:
        type = PokemonType::Water;
        baseHP = 90;
        baseAttack = 65;
        baseDefense = 65;
        baseEXP = 63;
        GR = GrowthRate::Slow;
        break;
    case PokemonSpecies::Rapidash:
        type = PokemonType::Fire;
        baseHP = 65;
        baseAttack = 80;
        baseDefense = 50;
        baseEXP = 175;
        GR = GrowthRate::Fast;
        break;
    case PokemonSpecies::Farfetchd:
        type = PokemonType::Normal;
        baseHP = 52;
        baseAttack = 65;
        baseDefense = 55;
        baseEXP = 66;
        GR = GrowthRate::Fast;
        break;
    case PokemonSpecies::Paras:
        type = PokemonType::Grass;
        baseHP = 35;
        baseAttack = 70;
        baseDefense = 55;
        baseEXP = 60;
        GR = GrowthRate::Medium;
        break;
    case PokemonSpecies::Seel:
        type = PokemonType::Water;
        baseHP = 65;
        baseAttack = 45;
        baseDefense = 55;
        baseEXP = 65;
        GR = GrowthRate::Fast;
        break;
    case PokemonSpecies::Magmar:
        type = PokemonType::Fire;
        baseHP = 50;
        baseAttack = 95;
        baseDefense = 57;
        baseEXP = 64;
        GR = GrowthRate::Fast;
        break;
    case PokemonSpecies::Raticate:
        type = PokemonType::Normal;
        baseHP = 55;
        baseAttack = 81;
        baseDefense = 60;
        baseEXP = 128;
        GR = GrowthRate::Fast;
        break;
    case PokemonSpecies::Parasect:
        type = PokemonType::Grass;
        baseHP = 60;
        baseAttack = 95;
        baseDefense = 80;
        baseEXP = 142;
        GR = GrowthRate::Medium;
        break;
    case PokemonSpecies::Wartortle:
        type = PokemonType::Water;
        baseHP = 59;
        baseAttack = 63;
        baseDefense = 80;
        baseEXP = 142;
        GR = GrowthRate::Fast;
        break;
    case PokemonSpecies::Ninetales:
        type = PokemonType::Fire;
        baseHP = 73;
        baseAttack = 76;
        baseDefense = 75;
        baseEXP = 177;
        GR = GrowthRate::Fast;
        break;
    case PokemonSpecies::Fearow:
        type = PokemonType::Normal;
        baseHP = 65;
        baseAttack = 90;
        baseDefense = 60;
        baseEXP = 152;
        GR = GrowthRate::Fast;
        break;
    case PokemonSpecies::Bellsprout:
        type = PokemonType::Grass;
        baseHP = 50;
        baseAttack = 75;
        baseDefense = 35;
        baseEXP = 64;
        GR = GrowthRate::Medium;
        break;
    case PokemonSpecies::Dewgong:
        type = PokemonType::Water;
        baseHP = 90;
        baseAttack = 70;
        baseDefense = 65;
        baseEXP = 166;
        GR = GrowthRate::Fast;
        break;
    case PokemonSpecies::Flareon:
        type = PokemonType::Fire;
        baseHP = 65;
        baseAttack = 130;
        baseDefense = 60;
        baseEXP = 184;
        GR = GrowthRate::Fast;
        break;
    case PokemonSpecies::Wigglytuff:
        type = PokemonType::Normal;
        baseHP = 140;
        baseAttack = 70;
        baseDefense = 45;
        baseEXP = 260; // Base Experience for Wigglytuff
        GR = GrowthRate::Fast;
        break;
    case PokemonSpecies::Weepinbell:
        type = PokemonType::Grass;
        baseHP = 65;
        baseAttack = 90;
        baseDefense = 50;
        baseEXP = 210; // Base Experience for Weepinbell
        GR = GrowthRate::Medium;
        break;
    case PokemonSpecies::Blastoise:
        type = PokemonType::Water;
        baseHP = 79;
        baseAttack = 83;
        baseDefense = 100;
        baseEXP = 265; // Base Experience for Blastoise
        GR = GrowthRate::Fast;
        break;
    case PokemonSpecies::Arcanine:
        type = PokemonType::Fire;
        baseHP = 90;
        baseAttack = 110;
        baseDefense = 80;
        baseEXP = 235; // Base Experience for Arcanine
        GR = GrowthRate::Fast;
        break;
    case PokemonSpecies::Persian:
        type = PokemonType::Normal;
        baseHP = 65;
        baseAttack = 70;
        baseDefense = 60;
        baseEXP = 166; // Base Experience for Persian
        GR = GrowthRate::Fast;
        break;
    case PokemonSpecies::Victreebel:
        type = PokemonType::Grass;
        baseHP = 75;
        baseAttack = 100;
        baseDefense = 70;
        baseEXP = 220; // Base Experience for Victreebel
        GR = GrowthRate::Medium;
        break;
    case PokemonSpecies::Lapras:
        type = PokemonType::Water;
        baseHP = 130;
        baseAttack = 85;
        baseDefense = 80;
        baseEXP = 187; // Base Experience for Lapras
        GR = GrowthRate::Slow;
        break;
    case PokemonSpecies::Charizard:
        type = PokemonType::Fire;
        baseHP = 78;
        baseAttack = 84;
        baseDefense = 78;
        baseEXP = 240; // Base Experience for Charizard
        GR = GrowthRate::Fast;
        break;
    case PokemonSpecies::Kangaskhan:
        type = PokemonType::Normal;
        baseHP = 105;
        baseAttack = 95;
        baseDefense = 80;
        baseEXP = 173; // Base Experience for Kangaskhan
        GR = GrowthRate::Fast;
        break;
    case PokemonSpecies::Tangela:
        type = PokemonType::Grass;
        baseHP = 65;
        baseAttack = 55;
        baseDefense = 115;
        baseEXP = 87; // Base Experience for Tangela
        GR = GrowthRate::Medium;
        break;
    case PokemonSpecies::Gyarados:
        type = PokemonType::Water;
        baseHP = 95;
        baseAttack = 125;
        baseDefense = 79;
        baseEXP = 189; // Base Experience for Gyarados
        GR = GrowthRate::Slow;
        break;
    case PokemonSpecies::Moltres:
        type = PokemonType::Fire;
        baseHP = 90;
        baseAttack = 100;
        baseDefense = 90;
        baseEXP = 261; // Base Experience for Moltres
        GR = GrowthRate::Fast;
        break;
    case PokemonSpecies::Snorlax:
        type = PokemonType::Normal;
        baseHP = 160;
        baseAttack = 110;
        baseDefense = 65;
        baseEXP = 189; // Base Experience for Snorlax
        GR = GrowthRate::Slow;
        break;
    default:
        type = PokemonType::Normal;
        baseHP = 0;
        baseAttack = 0;
        baseDefense = 0;
        baseEXP = 0; // Default Base Experience
        GR = GrowthRate::Fast;
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

int Pokemon::getLevel() const{
    return level;
}

void Pokemon::displayInfo() {
        cout << "Species: " << speciesToString(species)
                  << "\nType: " << typeToString(type)
                  << "\nHP: " << calculateHP()
                  << "\nBase Attack: " << baseAttack
                  << "\nBase Defense: " << baseDefense 
                  << "\n Move 1 name: " << move1->getName()
                  << "\n Move 2 name: " << move2->getName()
                  << "\n Move 3 name: " << move3->getName()<< "\n";
}

bool Pokemon::isTypeEffective(Pokemon defender) {
    // Super effective relationships
    if ((type == PokemonType::Fire && defender.type == PokemonType::Grass) ||
        (type == PokemonType::Water && defender.type == PokemonType::Fire) ||
        (type == PokemonType::Grass && defender.type == PokemonType::Water))
        return true;
    return false;
}
bool Pokemon::isTypeNotEffective(Pokemon defender) {
    // Not very effective relationships
    if ((type == PokemonType::Fire && defender.type == PokemonType::Water) ||
        (type == PokemonType::Water && defender.type == PokemonType::Grass) ||
        (type == PokemonType::Grass && defender.type == PokemonType::Fire))
        return true;
    return false;
}

int Pokemon::calculateHP() const{
    return (2*baseHP+IV)*level/100+level+10;
}
int Pokemon::calculateAttack() const{
    return (2*baseAttack+IV)*level/100+5;
}
int Pokemon::calculateDefense() const{
    return (2*baseDefense+IV)*level/100+5;
}

void Pokemon::addEXP(int val){
    if(level>=100){
        cout << speciesToString(species) << "is already lvl 100." << endl;
        return;
    }
    cout << speciesToString(species) << " gained " << val << " exp" << endl;
    exp+=val;
    if(GR==GrowthRate::Fast){
        if(exp==level*level*level){
            cout << "Level Up!   " << level;
            addLevel();
            cout << "  ->  " << level << endl;
        }
    }
    else if(GR==GrowthRate::Medium){
        if(exp== 1.2*level*level*level-15*level*level+100*level-140){
            cout << "Level Up!   " << level;
            addLevel();
            cout << "  ->  " << level << endl;
        }
    }
    else if(GR==GrowthRate::Slow){
        if(exp == 1.25*level*level*level){
            cout << "Level Up!   " << level;
            addLevel();
            cout << "  ->  " << level << endl;
        }
    }
}

void Pokemon::addLevel(){
    level++;
}

int Pokemon::calculateEXP(Pokemon defeatedPokemon) const{
    return baseEXP*defeatedPokemon.level/7;
}

void Pokemon::setBaseHP(int val){
    baseHP=val;
}
void Pokemon::setBaseAttack(int val){
    baseAttack=val;
}
void Pokemon::setBaseDefense(int val){
    baseDefense=val;
}

int Pokemon::getBaseHP(){
    return baseHP;
}
int Pokemon::getBaseAttack(){
    return baseAttack;
}
int Pokemon::getBaseDefense(){
    return baseDefense;
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