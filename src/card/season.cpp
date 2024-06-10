#include "season.h"

Season::Season(int inputPoint,std::string inputType,int inputPriority) : PurpleCard(inputPoint,inputType,inputPriority){

}

bool Season::is_season() const{
    return true;
}