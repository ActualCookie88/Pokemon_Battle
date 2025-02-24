#include "../../header/Revives/StandardRevive.h"

StandardRevive::StandardRevive(string desc, int reviveCost)
 : Revive("Standard Revive", desc, reviveCost, ReviveType::STANDARD) {}