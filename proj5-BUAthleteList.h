#ifndef PROJ5_BUATHLETELIST_H
#define PROJ5_BUATHLETELIST_H
#include "proj5-BUAthlete.h"
#include <iostream>



class BUAthleteList : public BUAthlete{
    private:
        int capacity;
        int size;
        BUAthlete *athletes;

        void resizeArray(){
            if(capacity == size){
                capacity += 2;
            }
        }

    public:
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