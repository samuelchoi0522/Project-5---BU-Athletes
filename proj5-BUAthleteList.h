#ifndef PROJ5_BUATHLETELIST_H
#define PROJ5_BUATHLETELIST_H
#include "proj5-BUAthlete.h"
#include <iostream>

using namespace std;

class BUAthleteList : public BUAthlete{
    protected:
        int capacityl;
        int sizel;
        BUAthlete *athletes;
        void resizeArray(){
            capacityl += 2;
            BUAthlete *btemp = new BUAthlete[capacityl];
            for(int i = 0 ; i < capacityl; i++){
                btemp[i] = athletes[i];
            }
            delete []athletes;
            athletes = new BUAthleteList[capacityl];

            for(int i = 0 ; i < capacityl; i++){
                athletes[i] = btemp[i];
            }
            delete []btemp;
        }

    public:
        BUAthleteList(){
            capacityl = 2;
            sizel = 0;
            athletes = new BUAthlete[capacityl];
        }

        void addNCAAAthlete(int ID, string name, string LOI, string school);
        void setBUInfo (int index, Position pos, int eval);
        int findByld (int id);
        void sortByID();
        void sortByPosition();
        void sortByEvaluation();
        string toString();

        BUAthlete& operator[](int ndx);

};

#endif