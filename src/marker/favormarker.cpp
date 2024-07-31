#include "favormarker.h"

FavorMarker::FavorMarker() : Marker(white) {

}

std::string FavorMarker::getType() const
{
    return "FavorMarker";
}
