//
// Created by THOMAS QUARSHIE on 11/27/2022.
//
#include "Airport.h"
#include "Readfiles.h"
#include "Objects.h"
#include "RetrieveObj.h"

vector<Airport> RetrieveObj :: Airport_objects;


__attribute__((unused)) void RetrieveObj ::  my_main(){
    RetrieveObj ob;
    string file_path = R"(airports.csv)";
    vector<vector<string>> Airport_contentArray = Readfile(file_path);
    for(const vector<string>& array : Airport_contentArray){
        Airport Airport_object = Objects::Airportobject(array);
        RetrieveObj::Airport_objects.push_back(Airport_object);
    }
}