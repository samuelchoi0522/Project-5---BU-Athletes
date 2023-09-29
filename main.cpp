#include <iostream>
#include <fstream>
using namespace std;
#include "proj5-BUAthleteList.h"


int main(){
    ifstream NCAAFile, BUFile;
    int size = 0;
    int capacity = 2;


    BUAthlete *baylorathletes = new BUAthlete[capacity];
    char *buffer = new char[500];
    char temp;
    
    NCAAFile.open("proj5-NCAAAthlete.csv");

    while(!NCAAFile.eof()){
        char *chID = new char[4];
        int ID;
        string name, school, LOI;

        int index = 0;

        if(capacity == size){
            capacity += 2;
        }

        int x = 0;
        //buffer
        while(NCAAFile.get(temp) && temp != '\n'){
            buffer[x] = temp;
            x++;
        }
        cout << "buffer: " << buffer << endl;

        //id
        for(int i = 0 ; i < 4; i++){
            chID[i] = buffer[index];
            index++;
        }
        cout << "ID: " << chID << endl;

        index++;

        //name
        while(buffer[index] != ','){
            name += buffer[index];
            index++;
        }
        cout << "Name: " << name << endl;

        index++;

        //setLOI
        while(buffer[index] != ','){
            LOI += buffer[index];
            index++;
        }
        cout << "LOI: " << LOI << endl;

        index++;

        while(buffer[index] != '\0'){
            school += buffer[index];
            index++;
        }
        cout << "School: " << school << endl;
        cout << endl;

        size++;

        delete []buffer;
        buffer = new char[500];
    }
    
    
    return 0;
}