#include "proj5-BUAthlete.h"
#include <sstream>

void BUAthlete::setEvaluation(int eval){
    this->evaluation = eval;
}
void BUAthlete::setPosition(Position pos){
    this->bestFit = pos;
}
int BUAthlete::getEvaluation(){
    return this->evaluation;
}
Position BUAthlete::getPosition(){
    return this->bestFit;
}
string BUAthlete::toString(){
    ostringstream out;

    out << "ID: " << this->athleteID << endl;
    out << "Name: " << this->athleteName << endl;

    if( this->athleteLOI ){
        out << "School: " << this->schoolChoice << endl;
    } else {
        out << "Available" << endl;
    }

    return out.str();
}