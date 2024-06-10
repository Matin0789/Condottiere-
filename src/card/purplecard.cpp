#include "purplecard.h"

#include <string>

PurpleCard::PurpleCard(int inputPoint,std::string inputType,int inputPriority) : Card(inputPoint,inputPriority), type(inputType){

}

std::string PurpleCard::getType() const{
    return type;
}