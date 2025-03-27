#include "../../header/Pokemon/attack.h"
#include "../../header/Pokemon/moves.h"
#include <iostream>

Attack::Attack() : name(Moves::None), type(Type::Normal), power(0) {} // default constructor

Attack::Attack(Moves name) : name(name) { //constructor for every Moves
    switch (name) {
        case Moves::FireSpin:
            type = Type::Fire;
            power = 35;
            break;
        case Moves::Flamethrower:
            type = Type::Fire;
            power = 90;
            break;
        case Moves::FireBlast:
            type = Type::Fire;
            power = 110;
            break;
        case Moves::Ember:
            type = Type::Fire;
            power = 40;
            break;
        case Moves::FirePunch:
            type = Type::Fire;
            power = 75;
            break;
        case Moves::Absorb:
            type = Type::Grass;
            power = 20;
            break;
        case Moves::LeechSeed:
            type = Type::Grass;
            power = 0; // Non-damaging
            break;
        case Moves::MegaDrain:
            type = Type::Grass;
            power = 40;
            break;
        case Moves::PetalDance:
            type = Type::Grass;
            power = 120;
            break;
        case Moves::RazorLeaf:
            type = Type::Grass;
            power = 55;
            break;
        case Moves::SleepPowder:
            type = Type::Grass;
            power = 0; // Non-damaging
            break;
        case Moves::SolarBeam:
            type = Type::Grass;
            power = 120;
            break;
        case Moves::Spore:
            type = Type::Grass;
            power = 0; // Non-damaging
            break;
        case Moves::StunSpore:
            type = Type::Grass;
            power = 0; // Non-damaging
            break;
        case Moves::VineWhip:
            type = Type::Grass;
            power = 45;
            break;
        case Moves::Clamp:
            type = Type::Water;
            power = 35;
            break;
        case Moves::Crabhammer:
            type = Type::Water;
            power = 100;
            break;
        case Moves::HydroPump:
            type = Type::Water;
            power = 110;
            break;
        case Moves::Surf:
            type = Type::Water;
            power = 90;
            break;
        case Moves::WaterGun:
            type = Type::Water;
            power = 40;
            break;
        case Moves::Waterfall:
            type = Type::Water;
            power = 80;
            break;
        case Moves::Withdraw:
            type = Type::Water;
            power = 0; // Non-damaging
            break;
        case Moves::Barrage:
            type = Type::Normal;
            power = 15;
            break;
        case Moves::Bide:
            type = Type::Normal;
            power = 0; // Depends on damage received
            break;
        case Moves::Bind:
            type = Type::Normal;
            power = 15;
            break;
        case Moves::BodySlam:
            type = Type::Normal;
            power = 85;
            break;
        case Moves::CometPunch:
            type = Type::Normal;
            power = 18;
            break;
        case Moves::Cut:
            type = Type::Normal;
            power = 50;
            break;
        case Moves::DefenseCurl:
            type = Type::Normal;
            power = 0; // Non-damaging
            break;
        case Moves::DizzyPunch:
            type = Type::Normal;
            power = 70;
            break;
        case Moves::DoubleSlap:
            type = Type::Normal;
            power = 15;
            break;
        case Moves::DoubleEdge:
            type = Type::Normal;
            power = 120;
            break;
        case Moves::EggBomb:
            type = Type::Normal;
            power = 100;
            break;
        case Moves::Explosion:
            type = Type::Normal;
            power = 250;
            break;
        case Moves::FuryAttack:
            type = Type::Normal;
            power = 15;
            break;
        case Moves::FurySwipes:
            type = Type::Normal;
            power = 18;
            break;
        case Moves::Glare:
            type = Type::Normal;
            power = 0; // Non-damaging
            break;
        case Moves::Growl:
            type = Type::Normal;
            power = 0; // Non-damaging
            break;
        case Moves::Growth:
            type = Type::Normal;
            power = 0; // Non-damaging
            break;
        case Moves::Guillotine:
            type = Type::Normal;
            power = 0; // OHKO move
            break;
        case Moves::Harden:
            type = Type::Normal;
            power = 0; // Non-damaging
            break;
        case Moves::Headbutt:
            type = Type::Normal;
            power = 70;
            break;
        case Moves::HornAttack:
            type = Type::Normal;
            power = 65;
            break;
        case Moves::HornDrill:
            type = Type::Normal;
            power = 0; // OHKO move
            break;
        case Moves::HyperBeam:
            type = Type::Normal;
            power = 150;
            break;
        case Moves::HyperFang:
            type = Type::Normal;
            power = 80;
            break;
        case Moves::Leer:
            type = Type::Normal;
            power = 0; // Non-damaging
            break;
        case Moves::LovelyKiss:
            type = Type::Normal;
            power = 0; // Non-damaging
            break;
        case Moves::MegaKick:
            type = Type::Normal;
            power = 120;
            break;
        case Moves::MegaPunch:
            type = Type::Normal;
            power = 80;
            break;
        case Moves::Pound:
            type = Type::Normal;
            power = 40;
            break;
        case Moves::QuickAttack:
            type = Type::Normal;
            power = 40;
            break;
        case Moves::Rage:
            type = Type::Normal;
            power = 20;
            break;
        case Moves::RazorWind:
            type = Type::Normal;
            power = 80;
            break;
        case Moves::Recover:
            type = Type::Normal;
            power = 0; // Non-damaging
            break;
        case Moves::Scratch:
            type = Type::Normal;
            power = 40;
            break;
        case Moves::Screech:
            type = Type::Normal;
            power = 0; // Non-damaging
            break;
        case Moves::SelfDestruct:
            type = Type::Normal;
            power = 200;
            break;
        case Moves::Sharpen:
            type = Type::Normal;
            power = 0; // Non-damaging
            break;
        case Moves::Sing:
            type = Type::Normal;
            power = 0; // Non-damaging
            break;
        case Moves::SkullBash:
            type = Type::Normal;
            power = 130;
            break;
        case Moves::Slam:
            type = Type::Normal;
            power = 80;
            break;
        case Moves::Slash:
            type = Type::Normal;
            power = 70;
            break;
        case Moves::SoftBoiled:
            type = Type::Normal;
            power = 0; // Non-damaging
            break;
        case Moves::SonicBoom:
            type = Type::Normal;
            power = 0; // Fixed damage (20 HP)
            break;
        case Moves::SpikeCannon:
            type = Type::Normal;
            power = 20;
            break;
        case Moves::Splash:
            type = Type::Normal;
            power = 0; // Non-damaging
            break;
        case Moves::Stomp:
            type = Type::Normal;
            power = 65;
            break;
        case Moves::Strength:
            type = Type::Normal;
            power = 80;
            break;
        case Moves::SuperFang:
            type = Type::Normal;
            power = 0; // Reduces HP by half
            break;
        case Moves::Supersonic:
            type = Type::Normal;
            power = 0; // Non-damaging
            break;
        case Moves::SwordsDance:
            type = Type::Normal;
            power = 0; // Non-damaging
            break;
        case Moves::Tackle:
            type = Type::Normal;
            power = 40;
            break;
        case Moves::TailWhip:
            type = Type::Normal;
            power = 0; // Non-damaging
            break;
        case Moves::TakeDown:
            type = Type::Normal;
            power = 90;
            break;
        case Moves::Thrash:
            type = Type::Normal;
            power = 120;
            break;
        case Moves::ViseGrip:
            type = Type::Normal;
            power = 55;
            break;
        case Moves::Wrap:
            type = Type::Normal;
            power = 15;
            break;
        default:
            type = Type::Normal; // Default case for undefined Moves
            power = 0;
            break;
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

bool Attack::isSuperEffective(Type targetType) const {
    // Super effective relationships
    if ((type == Type::Fire && targetType == Type::Grass) ||
        (type == Type::Water && targetType == Type::Fire) ||
        (type == Type::Grass && targetType == Type::Water))
        return true;
    return false;
}

bool Attack::isNotVeryEffective(Type targetType) const{
    // Not very effective relationships
    if ((type == Type::Fire && targetType == Type::Water) ||
        (type == Type::Water && targetType == Type::Grass) ||
        (type == Type::Grass && targetType == Type::Fire))
        return true;
    return false;
}

string Attack::typeToString(Type type) {
    switch (type) {
        case Type::Normal:   return "Normal";
        case Type::Fire:     return "Fire";
        case Type::Water:    return "Water";
        case Type::Grass:    return "Grass";
        default: return "Unknown";
    }
}

string Attack::getName() const {//use this function to get the name of the Moves
    switch (name) {
        case Moves::FireSpin: return "Fire Spin";
        case Moves::Flamethrower: return "Flamethrower";
        case Moves::FireBlast: return "Fire Blast";
        case Moves::Ember: return "Ember";
        case Moves::FirePunch: return "Fire Punch";
        case Moves::Absorb: return "Absorb";
        case Moves::LeechSeed: return "Leech Seed";
        case Moves::MegaDrain: return "Mega Drain";
        case Moves::PetalDance: return "Petal Dance";
        case Moves::RazorLeaf: return "Razor Leaf";
        case Moves::SleepPowder: return "Sleep Powder";
        case Moves::SolarBeam: return "Solar Beam";
        case Moves::Spore: return "Spore";
        case Moves::StunSpore: return "Stun Spore";
        case Moves::VineWhip: return "Vine Whip";
        case Moves::Clamp: return "Clamp";
        case Moves::Crabhammer: return "Crabhammer";
        case Moves::HydroPump: return "Hydro Pump";
        case Moves::Surf: return "Surf";
        case Moves::WaterGun: return "Water Gun";
        case Moves::Waterfall: return "Waterfall";
        case Moves::Withdraw: return "Withdraw";
        case Moves::Barrage: return "Barrage";
        case Moves::Bide: return "Bide";
        case Moves::Bind: return "Bind";
        case Moves::BodySlam: return "Body Slam";
        case Moves::CometPunch: return "Comet Punch";
        case Moves::Cut: return "Cut";
        case Moves::DefenseCurl: return "Defense Curl";
        case Moves::DizzyPunch: return "Dizzy Punch";
        case Moves::DoubleSlap: return "Double Slap";
        case Moves::DoubleEdge: return "Double-Edge";
        case Moves::EggBomb: return "Egg Bomb";
        case Moves::Explosion: return "Explosion";
        case Moves::FuryAttack: return "Fury Attack";
        case Moves::FurySwipes: return "Fury Swipes";
        case Moves::Glare: return "Glare";
        case Moves::Growl: return "Growl";
        case Moves::Growth: return "Growth";
        case Moves::Guillotine: return "Guillotine";
        case Moves::Harden: return "Harden";
        case Moves::Headbutt: return "Headbutt";
        case Moves::HornAttack: return "Horn Attack";
        case Moves::HornDrill: return "Horn Drill";
        case Moves::HyperBeam: return "Hyper Beam";
        case Moves::HyperFang: return "Hyper Fang";
        case Moves::Leer: return "Leer";
        case Moves::LovelyKiss: return "Lovely Kiss";
        case Moves::MegaKick: return "Mega Kick";
        case Moves::MegaPunch: return "Mega Punch";
        case Moves::Pound: return "Pound";
        case Moves::QuickAttack: return "Quick Attack";
        case Moves::Rage: return "Rage";
        case Moves::RazorWind: return "Razor Wind";
        case Moves::Recover: return "Recover";
        case Moves::Scratch: return "Scratch";
        case Moves::Screech: return "Screech";
        case Moves::SelfDestruct: return "Self-Destruct";
        case Moves::Sharpen: return "Sharpen";
        case Moves::Sing: return "Sing";
        case Moves::SkullBash: return "Skull Bash";
        case Moves::Slam: return "Slam";
        case Moves::Slash: return "Slash";
        case Moves::SoftBoiled: return "Soft-Boiled";
        case Moves::SonicBoom: return "Sonic Boom";
        case Moves::SpikeCannon: return "Spike Cannon";
        case Moves::Splash: return "Splash";
        case Moves::Stomp: return "Stomp";
        case Moves::Strength: return "Strength";
        case Moves::SuperFang: return "Super Fang";
        case Moves::Supersonic: return "Supersonic";
        case Moves::SwordsDance: return "Swords Dance";
        case Moves::Tackle: return "Tackle";
        case Moves::TailWhip: return "Tail Whip";
        case Moves::TakeDown: return "Take Down";
        case Moves::Thrash: return "Thrash";
        case Moves::ViseGrip: return "Vise Grip";
        case Moves::Wrap: return "Wrap";
        case Moves::None: return "None";
        default: return "Unknown Move";
    }
}

Type Attack::getType() const {
    return type;
}

int Attack::getPower() const {
    return power;
}

