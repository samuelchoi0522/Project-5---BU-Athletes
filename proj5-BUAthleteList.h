#ifndef PROJ5_BUATHLETELIST_H
#define PROJ5_BUATHLETELIST_H
#include "proj5-BUAthlete.h"


class BUAthleteList{
    private:
        BUAthlete *list;
        int capacity;
        int size;
        void resizeArray();

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