#ifndef PLAYERMARKER_H
#define PLAYERMARKER_H



#include "marker.h"

class PlayerMarker : public Marker {
private:

public:
    PlayerMarker(Color);
    virtual std::string getType() const;
};

#endif // PLAYERMARKER_H
