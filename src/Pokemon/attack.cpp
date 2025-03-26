#include "../../header/Pokemon/attack.h"
#include "../../header/Pokemon/moves.h"
#include <iostream>

Attack::Attack() : name(moves::None), type(PokemonType::Normal), power(0) {} // default constructor

Attack::Attack(moves name) : name(name) { //constructor for every moves
    switch (name) {
        case moves::FireSpin:
            type = PokemonType::Fire;
            power = 35;
            break;
        case moves::Flamethrower:
            type = PokemonType::Fire;
            power = 90;
            break;
        case moves::FireBlast:
            type = PokemonType::Fire;
            power = 110;
            break;
        case moves::Ember:
            type = PokemonType::Fire;
            power = 40;
            break;
        case moves::FirePunch:
            type = PokemonType::Fire;
            power = 75;
            break;
        case moves::Absorb:
            type = PokemonType::Grass;
            power = 20;
            break;
        case moves::LeechSeed:
            type = PokemonType::Grass;
            power = 0; // Non-damaging
            break;
        case moves::MegaDrain:
            type = PokemonType::Grass;
            power = 40;
            break;
        case moves::PetalDance:
            type = PokemonType::Grass;
            power = 120;
            break;
        case moves::RazorLeaf:
            type = PokemonType::Grass;
            power = 55;
            break;
        case moves::SleepPowder:
            type = PokemonType::Grass;
            power = 0; // Non-damaging
            break;
        case moves::SolarBeam:
            type = PokemonType::Grass;
            power = 120;
            break;
        case moves::Spore:
            type = PokemonType::Grass;
            power = 0; // Non-damaging
            break;
        case moves::StunSpore:
            type = PokemonType::Grass;
            power = 0; // Non-damaging
            break;
        case moves::VineWhip:
            type = PokemonType::Grass;
            power = 45;
            break;
        case moves::Clamp:
            type = PokemonType::Water;
            power = 35;
            break;
        case moves::Crabhammer:
            type = PokemonType::Water;
            power = 100;
            break;
        case moves::HydroPump:
            type = PokemonType::Water;
            power = 110;
            break;
        case moves::Surf:
            type = PokemonType::Water;
            power = 90;
            break;
        case moves::WaterGun:
            type = PokemonType::Water;
            power = 40;
            break;
        case moves::Waterfall:
            type = PokemonType::Water;
            power = 80;
            break;
        case moves::Withdraw:
            type = PokemonType::Water;
            power = 0; // Non-damaging
            break;
        case moves::Barrage:
            type = PokemonType::Normal;
            power = 15;
            break;
        case moves::Bide:
            type = PokemonType::Normal;
            power = 0; // Depends on damage received
            break;
        case moves::Bind:
            type = PokemonType::Normal;
            power = 15;
            break;
        case moves::BodySlam:
            type = PokemonType::Normal;
            power = 85;
            break;
        case moves::CometPunch:
            type = PokemonType::Normal;
            power = 18;
            break;
        case moves::Cut:
            type = PokemonType::Normal;
            power = 50;
            break;
        case moves::DefenseCurl:
            type = PokemonType::Normal;
            power = 0; // Non-damaging
            break;
        case moves::DizzyPunch:
            type = PokemonType::Normal;
            power = 70;
            break;
        case moves::DoubleSlap:
            type = PokemonType::Normal;
            power = 15;
            break;
        case moves::DoubleEdge:
            type = PokemonType::Normal;
            power = 120;
            break;
        case moves::EggBomb:
            type = PokemonType::Normal;
            power = 100;
            break;
        case moves::Explosion:
            type = PokemonType::Normal;
            power = 250;
            break;
        case moves::FuryAttack:
            type = PokemonType::Normal;
            power = 15;
            break;
        case moves::FurySwipes:
            type = PokemonType::Normal;
            power = 18;
            break;
        case moves::Glare:
            type = PokemonType::Normal;
            power = 0; // Non-damaging
            break;
        case moves::Growl:
            type = PokemonType::Normal;
            power = 0; // Non-damaging
            break;
        case moves::Growth:
            type = PokemonType::Normal;
            power = 0; // Non-damaging
            break;
        case moves::Guillotine:
            type = PokemonType::Normal;
            power = 0; // OHKO move
            break;
        case moves::Harden:
            type = PokemonType::Normal;
            power = 0; // Non-damaging
            break;
        case moves::Headbutt:
            type = PokemonType::Normal;
            power = 70;
            break;
        case moves::HornAttack:
            type = PokemonType::Normal;
            power = 65;
            break;
        case moves::HornDrill:
            type = PokemonType::Normal;
            power = 0; // OHKO move
            break;
        case moves::HyperBeam:
            type = PokemonType::Normal;
            power = 150;
            break;
        case moves::HyperFang:
            type = PokemonType::Normal;
            power = 80;
            break;
        case moves::Leer:
            type = PokemonType::Normal;
            power = 0; // Non-damaging
            break;
        case moves::LovelyKiss:
            type = PokemonType::Normal;
            power = 0; // Non-damaging
            break;
        case moves::MegaKick:
            type = PokemonType::Normal;
            power = 120;
            break;
        case moves::MegaPunch:
            type = PokemonType::Normal;
            power = 80;
            break;
        case moves::Pound:
            type = PokemonType::Normal;
            power = 40;
            break;
        case moves::QuickAttack:
            type = PokemonType::Normal;
            power = 40;
            break;
        case moves::Rage:
            type = PokemonType::Normal;
            power = 20;
            break;
        case moves::RazorWind:
            type = PokemonType::Normal;
            power = 80;
            break;
        case moves::Recover:
            type = PokemonType::Normal;
            power = 0; // Non-damaging
            break;
        case moves::Scratch:
            type = PokemonType::Normal;
            power = 40;
            break;
        case moves::Screech:
            type = PokemonType::Normal;
            power = 0; // Non-damaging
            break;
        case moves::SelfDestruct:
            type = PokemonType::Normal;
            power = 200;
            break;
        case moves::Sharpen:
            type = PokemonType::Normal;
            power = 0; // Non-damaging
            break;
        case moves::Sing:
            type = PokemonType::Normal;
            power = 0; // Non-damaging
            break;
        case moves::SkullBash:
            type = PokemonType::Normal;
            power = 130;
            break;
        case moves::Slam:
            type = PokemonType::Normal;
            power = 80;
            break;
        case moves::Slash:
            type = PokemonType::Normal;
            power = 70;
            break;
        case moves::SoftBoiled:
            type = PokemonType::Normal;
            power = 0; // Non-damaging
            break;
        case moves::SonicBoom:
            type = PokemonType::Normal;
            power = 0; // Fixed damage (20 HP)
            break;
        case moves::SpikeCannon:
            type = PokemonType::Normal;
            power = 20;
            break;
        case moves::Splash:
            type = PokemonType::Normal;
            power = 0; // Non-damaging
            break;
        case moves::Stomp:
            type = PokemonType::Normal;
            power = 65;
            break;
        case moves::Strength:
            type = PokemonType::Normal;
            power = 80;
            break;
        case moves::SuperFang:
            type = PokemonType::Normal;
            power = 0; // Reduces HP by half
            break;
        case moves::Supersonic:
            type = PokemonType::Normal;
            power = 0; // Non-damaging
            break;
        case moves::SwordsDance:
            type = PokemonType::Normal;
            power = 0; // Non-damaging
            break;
        case moves::Tackle:
            type = PokemonType::Normal;
            power = 40;
            break;
        case moves::TailWhip:
            type = PokemonType::Normal;
            power = 0; // Non-damaging
            break;
        case moves::TakeDown:
            type = PokemonType::Normal;
            power = 90;
            break;
        case moves::Thrash:
            type = PokemonType::Normal;
            power = 120;
            break;
        case moves::ViseGrip:
            type = PokemonType::Normal;
            power = 55;
            break;
        case moves::Wrap:
            type = PokemonType::Normal;
            power = 15;
            break;
        default:
            type = PokemonType::Normal; // Default case for undefined moves
            power = 0;
            break;
    }
}

string Attack::getName() const {//use this function to get the name of the moves
    switch (name) {
        case moves::FireSpin: return "Fire Spin";
        case moves::Flamethrower: return "Flamethrower";
        case moves::FireBlast: return "Fire Blast";
        case moves::Ember: return "Ember";
        case moves::FirePunch: return "Fire Punch";
        case moves::Absorb: return "Absorb";
        case moves::LeechSeed: return "Leech Seed";
        case moves::MegaDrain: return "Mega Drain";
        case moves::PetalDance: return "Petal Dance";
        case moves::RazorLeaf: return "Razor Leaf";
        case moves::SleepPowder: return "Sleep Powder";
        case moves::SolarBeam: return "Solar Beam";
        case moves::Spore: return "Spore";
        case moves::StunSpore: return "Stun Spore";
        case moves::VineWhip: return "Vine Whip";
        case moves::Clamp: return "Clamp";
        case moves::Crabhammer: return "Crabhammer";
        case moves::HydroPump: return "Hydro Pump";
        case moves::Surf: return "Surf";
        case moves::WaterGun: return "Water Gun";
        case moves::Waterfall: return "Waterfall";
        case moves::Withdraw: return "Withdraw";
        case moves::Barrage: return "Barrage";
        case moves::Bide: return "Bide";
        case moves::Bind: return "Bind";
        case moves::BodySlam: return "Body Slam";
        case moves::CometPunch: return "Comet Punch";
        case moves::Cut: return "Cut";
        case moves::DefenseCurl: return "Defense Curl";
        case moves::DizzyPunch: return "Dizzy Punch";
        case moves::DoubleSlap: return "Double Slap";
        case moves::DoubleEdge: return "Double-Edge";
        case moves::EggBomb: return "Egg Bomb";
        case moves::Explosion: return "Explosion";
        case moves::FuryAttack: return "Fury Attack";
        case moves::FurySwipes: return "Fury Swipes";
        case moves::Glare: return "Glare";
        case moves::Growl: return "Growl";
        case moves::Growth: return "Growth";
        case moves::Guillotine: return "Guillotine";
        case moves::Harden: return "Harden";
        case moves::Headbutt: return "Headbutt";
        case moves::HornAttack: return "Horn Attack";
        case moves::HornDrill: return "Horn Drill";
        case moves::HyperBeam: return "Hyper Beam";
        case moves::HyperFang: return "Hyper Fang";
        case moves::Leer: return "Leer";
        case moves::LovelyKiss: return "Lovely Kiss";
        case moves::MegaKick: return "Mega Kick";
        case moves::MegaPunch: return "Mega Punch";
        case moves::Pound: return "Pound";
        case moves::QuickAttack: return "Quick Attack";
        case moves::Rage: return "Rage";
        case moves::RazorWind: return "Razor Wind";
        case moves::Recover: return "Recover";
        case moves::Scratch: return "Scratch";
        case moves::Screech: return "Screech";
        case moves::SelfDestruct: return "Self-Destruct";
        case moves::Sharpen: return "Sharpen";
        case moves::Sing: return "Sing";
        case moves::SkullBash: return "Skull Bash";
        case moves::Slam: return "Slam";
        case moves::Slash: return "Slash";
        case moves::SoftBoiled: return "Soft-Boiled";
        case moves::SonicBoom: return "Sonic Boom";
        case moves::SpikeCannon: return "Spike Cannon";
        case moves::Splash: return "Splash";
        case moves::Stomp: return "Stomp";
        case moves::Strength: return "Strength";
        case moves::SuperFang: return "Super Fang";
        case moves::Supersonic: return "Supersonic";
        case moves::SwordsDance: return "Swords Dance";
        case moves::Tackle: return "Tackle";
        case moves::TailWhip: return "Tail Whip";
        case moves::TakeDown: return "Take Down";
        case moves::Thrash: return "Thrash";
        case moves::ViseGrip: return "Vise Grip";
        case moves::Wrap: return "Wrap";
        default: return "Unknown Move";
    }
}

Attack& Attack::operator=(const Attack& other) {
    if (this != &other) {
        name = other.name;
        type = other.type;
        power = other.power;
    }
    return *this;
}
int Attack::getpower() const {
    return power;
}
/*
int Attack::calculateDamage(Pokemon attacker, Pokemon defender) const{//this is the actual damage that will do to the opponent
    int damage = ((2*attacker.getLevel()/5+2)*(power*attacker.calculateAttack()/defender.calculateDefense())/50+2);
    if(attacker.isTypeEffective(defender)){
        damage*=2;
    }
    else if(attacker.isTypeNotEffective(defender)){
        damage*=0.5;
    }
    srand(time(0));
    if(rand()%10000<=625){
        damage*=1.5;
    }
    return damage*(85+rand()%30)/100;
}*/