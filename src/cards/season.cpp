#include "season.h"

Season::Season(int inputPoint,std::string inputName,int inputPriority,std::string inputHelp) : PurpleCard(inputPoint,inputName,inputPriority){

}

bool Season::is_season() const{
    return true;
}