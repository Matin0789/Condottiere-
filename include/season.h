#ifndef SEASON_H
#define SEASON_H

#include "purplecard.h"

class Season : public PurpleCard
{
public:
    Season(int,std::string,int,std::string);// (point,name,priority,help)
    bool is_season() const ;
private:

};

#endif