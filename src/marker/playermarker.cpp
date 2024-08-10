#include "playermarker.h"

PlayerMarker::PlayerMarker(Color inputColor) : Marker(inputColor){

}

std::string PlayerMarker::getType() const
{
    return "PlayerMarker";
}

void PlayerMarker::setColor(Color color)
{
    this->color = color;
}
