#ifndef FAVORMARKER_H
#define FAVORMARKER_H



#include "marker.h"

class FavorMarker : public Marker {
private:
    /* data */
public:
    FavorMarker();
    virtual std::string getType() const;
};

#endif // FAVORMARKER_H
