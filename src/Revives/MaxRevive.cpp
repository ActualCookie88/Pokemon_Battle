#include "../../header/Revives/MaxRevive.h"

MaxRevive::MaxRevive(string desc, int reviveCost)
 : Revive("Max Revive", desc, reviveCost, ReviveType::MAX) {}