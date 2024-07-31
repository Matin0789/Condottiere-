#ifndef BATTLEMARKER_H
#define BATTLEMARKER_H

#include "marker.h"

class BattleMarker : public Marker {
private:
    /* data */
public:
    BattleMarker();
    virtual std::string getType() const;
};

#endif // BATTLEMARKER_H
