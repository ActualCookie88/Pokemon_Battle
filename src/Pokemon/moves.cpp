#include "../../header/Pokemon/moves.h"

Type getMoveType(Moves move) {
    switch (move) {
        // Fire-type moves
        case Moves::FireSpin:
        case Moves::Flamethrower:
        case Moves::FireBlast:
        case Moves::Ember:
        case Moves::FirePunch:
            return Type::Fire;

        // Grass-type moves
        case Moves::Absorb:
        case Moves::LeechSeed:
        case Moves::MegaDrain:
        case Moves::PetalDance:
        case Moves::RazorLeaf:
        case Moves::SleepPowder:
        case Moves::SolarBeam:
        case Moves::Spore:
        case Moves::StunSpore:
        case Moves::VineWhip:
            return Type::Grass;

        // Water-type moves
        case Moves::Clamp:
        case Moves::Crabhammer:
        case Moves::HydroPump:
        case Moves::Surf:
        case Moves::WaterGun:
        case Moves::Waterfall:
        case Moves::Withdraw:
            return Type::Water;

        // Default all other moves to Normal-type
        default:
            return Type::Normal;
    }
}