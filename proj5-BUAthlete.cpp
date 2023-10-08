#include "proj5-BUAthlete.h"
#include <iostream>
#include <sstream>

//convert the string value to enum position
Position BUAthlete::stringToPosition(const string& positionStr){
    if (positionStr == "OL") return OL;
    else if (positionStr == "QB") return QB;
    else if (positionStr == "RB") return RB;
    else if (positionStr == "WR") return WR;
    else if (positionStr == "TE") return TE;
    else if (positionStr == "DL") return DL;
    else if (positionStr == "DE") return DE;
    else if (positionStr == "LB") return LB;
    else if (positionStr == "CB") return CB;
    else if (positionStr == "S") return S;
    else return K;
}

void BUAthlete::setEvaluation(int eval){
    evaluation = eval;
}
void BUAthlete::setPosition(Position pos){
    bestFit = pos;
}
int BUAthlete::getEvaluation(){
    return this->evaluation;
}
Position BUAthlete::getPosition(){
    return this->bestFit;
}


string BUAthlete::toString() {
    string pos = "unknown";

    if(bestFit == 0 && evaluation != 0){pos = "OL";}
    else if(bestFit == 1){pos = "QB";}
    else if(bestFit == 2){pos = "RB";}
    else if(bestFit == 3){pos = "WR";}
    else if(bestFit == 4){pos = "TE";}
    else if(bestFit == 5){pos = "DL";}
    else if(bestFit == 6){pos = "DE";}
    else if(bestFit == 7){pos = "LB";}
    else if(bestFit == 8){pos = "CB";}
    else if(bestFit == 9){pos = "S";}
    else if(bestFit == 10){pos = "K";}
    else{pos = "unknown";}
    
    string result = "ID: " + to_string(athleteID) + "\n";
    result += "Name: " + athleteName + "\n";
    result += "Evaluation: " + to_string(evaluation) + "\n";
    result += "Position: " + pos + "\n";

    if (athleteLOI) {result += "School: " + schoolChoice + "\n";} 
    else {result += "Available\n";}
    return result;
}

//convert charint into int
int stringToInt(char* cstr){
    int result = 0;

    for(int i = 0; i < 4; i++){
        result += (cstr[i] - '0') * pow(10, 3 - i);
    }


    return result;
}