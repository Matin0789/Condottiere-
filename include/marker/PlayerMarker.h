#ifndef PLAYERMARKER_H
#define PLAYERMARKER_H



#include "Marker.h"

class PlayerMarker : public Marker {
private:

public:
    PlayerMarker(Color);
    ~PlayerMarker();
};

#endif // PLAYERMARKER_H