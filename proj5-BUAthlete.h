#ifndef PROJ5_BUATHLETE_H
#define PROJ5_BUATHLETE_H
#include "proj5-NCAAAthlete.h"

enum Position {OL, QB, RB, WR, TE, DL, DE, LB, CB, S, K}; 


class BUAthlete {
    protected:
        int evaluation;
        Position bestFit;
    public:
        void setEvaluation(int);
        void setPosition(Position);
        int getEvaluation();
        Position getPosition();
        string toString();
};


#endif