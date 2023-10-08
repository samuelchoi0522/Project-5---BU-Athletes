#include "proj5-BUAthleteList.h"
#include <sstream>

void BUAthleteList::addNCAAAthlete(int ID, string name, string LOI, string school) {
    if (sizel >= capacityl) {
        resizeArray();
    }

    athletes[sizel].setID(ID);
    athletes[sizel].setName(name);
    athletes[sizel].setLOI(LOI);
    athletes[sizel].setSchool(school);

    sizel++;
}

void BUAthleteList::setBUInfo (int index, Position pos, int eval){
    athletes[index].setPosition(pos);
    athletes[index].setEvaluation(eval);
}

int BUAthleteList::findByld(int id) {
    int left = 0;
    int right = sizel - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int athleteID = athletes[mid].getID();
        if (athleteID == id) {
            return mid;
        } else if (athleteID < id) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // Athlete not found
}

/////////////////////////////////////////////////////////////
//quicksort by id
int partitionByID(BUAthlete* arr, int low, int high) {
    int pivotID = arr[high].getID();
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].getID() <= pivotID) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quicksortByID(BUAthlete* arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partitionByID(arr, low, high);
        quicksortByID(arr, low, pivotIndex - 1);
        quicksortByID(arr, pivotIndex + 1, high);
    }
}

void BUAthleteList::sortByID() {
    quicksortByID(athletes, 0, sizel - 1);
}

/////////////////////////////////////////////////////////////

void BUAthleteList::sortByPosition() {
    for(int i = 0 ; i < sizel - 1; i++){
        for(int j = 0; j < sizel - i - 1; j++){
            if(athletes[j].getPosition() < athletes[j + 1].getPosition()){
                swap(athletes[j], athletes[j + 1]);
            }
        }
    }
}

/////////////////////////////////////////////////////////////
//quicksort by evaluation
int partitionByEvaluation(BUAthlete arr[], int low, int high) {
    int pivot = arr[high].getEvaluation();
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].getEvaluation() >= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quicksortByEvaluation(BUAthlete arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partitionByEvaluation(arr, low, high);

        quicksortByEvaluation(arr, low, pivotIndex - 1);
        quicksortByEvaluation(arr, pivotIndex + 1, high);
    }
}

void BUAthleteList::sortByEvaluation() {
    quicksortByEvaluation(athletes, 0, sizel - 1);
}

/////////////////////////////////////////////////////////////

//index of enum to string
string intToPosString(int bestFit){
    string pos = "unknown";

    if(bestFit == 0){pos = "OL";}
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
    return pos;
}

//output
string BUAthleteList::toString(){
    string result;
    for(int j = 0; j <= 10; j++){
        result += intToPosString(j) + ":\n";
        int count = 0;
        for(int i = 0; i < sizel; i++){
            if(athletes[i].getPosition() == j && count != 2){
                int temp = athletes[i].getPosition();
                result += "[ " + to_string(count) + " ]" + "\n";
                result += "ID: " + to_string(athletes[i].getID()) + "\n";
                result += "Name: " + athletes[i].getName() + "\n";
                result += "School: " + athletes[i].getSchool() + "\n";
                result += "Evaluation: " + to_string(athletes[i].getEvaluation()) + "\n";
                result += "Position: " + intToPosString(temp) + "\n";
                count++;
            }
        }
        result += "\n";
    }
    return result;
}

BUAthlete& BUAthleteList::operator[](int ndx){
    return athletes[ndx];
}