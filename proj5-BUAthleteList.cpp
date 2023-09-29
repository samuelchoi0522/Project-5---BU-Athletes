#include "proj5-BUAthleteList.h"
#include <sstream>

void BUAthleteList::addNCAAAthlete(int ID, string name, string LOI, string school){
    athletes->setID(ID);
    athletes->setName(name);
    athletes->setLOI(LOI);
    athletes->setSchool(school);
}
void BUAthleteList::setBUInfo (int index, Position pos, int eval){

}
int BUAthleteList::findByld (int id){
    return 0;
}
void BUAthleteList::sortByID(){

}
void BUAthleteList::sortByPosition(){

}
void BUAthleteList::sortByEvaluation(){

}
string BUAthleteList::toString(){
    return 0;
}

// BUAthlete& BUAthleteList::operator[](int ndx){
//     return null;
// }