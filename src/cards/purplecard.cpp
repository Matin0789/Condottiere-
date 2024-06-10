#include "purplecard.h"

PurpleCard::PurpleCard(int inputPoint,std::string inputName,int inputPriority,std::string inputHelp) : Card(inputPoint,inputPriority), name(inputName), help(inputHelp) {

}
