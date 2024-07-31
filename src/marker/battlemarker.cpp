#include "battlemarker.h"

BattleMarker::BattleMarker() : Marker(black) {
    
}

std::string BattleMarker::getType() const
{
    return "BattleMarker";
}
