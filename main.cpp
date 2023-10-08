#include <iostream>
#include <fstream>
using namespace std;
#include "proj5-BUAthleteList.h"


int main(){
    ifstream NCAAFile, BUFile;
    int size = 0;
    int capacity = 2;

    BUAthleteList baylorathletes;
    char *buffer = new char[500];
    char temp;

    
    NCAAFile.open("proj5-NCAAAthlete.csv");

    while(!NCAAFile.eof()){
        char *chID = new char[4];
        string name, school, LOI;
        int ID, index = 0, x = 0;


        //buffer
        while(NCAAFile.get(temp) && temp != '\n'){
            buffer[x] = temp;
            x++;
        }

        //id
        for(int i = 0 ; i < 4; i++){
            chID[i] = buffer[index];
            index++;
        }index++;
        ID = stringToInt(chID);

        //name
        while(buffer[index] != ','){
            name += buffer[index];
            index++;
        }index++;

        //setLOI
        while(buffer[index] != ','){
            LOI += buffer[index];
            index++;
        }index++;

        //school
        while(buffer[index] != '\0'){
            school += buffer[index];
            index++;
        }

        baylorathletes.addNCAAAthlete(ID, name, LOI, school);
        

        delete []buffer;
        buffer = new char[500];
        size++;
    }
    baylorathletes.sortByID();


    //coach aranda file
    BUFile.open("proj5-BUAthlete.csv");
    while(!BUFile.eof()){
        char *chID = new char[4];
        string posi;
        char *cheval = new char[1];
        int sid, eval, index = 0;

        //buffer
        int x = 0;
        while(BUFile.get(temp) && temp != '\n'){
            buffer[x] = temp;
            x++;
        }

        //search id
        for(int i = 0; i < 4; i++){
            chID[i] = buffer[index];
            index++;
        }index++;
        sid = stringToInt(chID);

        //position
        while(buffer[index] != ','){
            posi += buffer[index];
            index++;
        }index++;

        //eval
        cheval[0] = buffer[index];
        eval = cheval[0] - '0';

        
        int indexfound = baylorathletes.findByld(sid);
        Position position = baylorathletes.stringToPosition(posi);
        
        baylorathletes.setBUInfo(indexfound, position, eval);
        
    }
    baylorathletes.sortByEvaluation();
    baylorathletes.sortByPosition();

    cout << baylorathletes.toString() << endl;  //prints out top two athletes


    delete []buffer;
    NCAAFile.close();
    BUFile.close();
    
    return 0;
}