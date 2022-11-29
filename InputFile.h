//
// Created by THOMAS QUARSHIE on 11/29/2022.
//
#pragma once
#include <iostream>
#include <vector>
#include "Readfiles.h"
#include "Objects.h"
using namespace std;
#ifndef C___PROJECT_INPUTFILE_H
#define C___PROJECT_INPUTFILE_H



class InputFile {
public:
    static vector<string> readInput(const string& filename){
        vector<string> result;
        vector<vector<string>> cityCountryArray;
        /**
         * Description: Try catch method already fulfilled in the Readfile class
         */
         cityCountryArray = Readfile(filename);
         /** Looping through the cityCountryArray to get the sourceairportcode based on the specific city*/
         for (int i =0; i < cityCountryArray.size(); i++){
             string code = Objects::getAirportID(cityCountryArray[i][0], cityCountryArray[i][1]);
             result.push_back(code);
         }
         return result;
    }
};


#endif //C___PROJECT_INPUTFILE_H
