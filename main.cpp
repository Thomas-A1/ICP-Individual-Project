
#include <iostream>
#include <string>
#include "Objects.h"
#include "RetrieveObj.h"
#include "node.h"
#include "Haversine.h"
#include "Search.h"
#include "InputFile.h"
using namespace std;

int main() {
    string myfilepath = R"(airlines.csv)";
    RetrieveObj roj;
    roj.my_main();
    cout << "Reading Routes file (67664) rows. This process might take a while, please be patient...................." << endl;
    /**
      * Populating hashmap and reading input file to obtain the source city and Destination
      * to be passed into the Uniform cost search algorithm. 
      */
    unordered_map<string, vector<vector<string>>> records = Routes::populateHashmap();
    //Passing in the input file to be read
    string filelocation =  R"(ZanibaToAccraInputfile.csv)";
    vector<string> inputs = InputFile::readInput(filelocation);
    cout << "***READING FROM A FILE TO COMPUTE THE SHORTEST PATH FROM A SOURCE TO A DESTINATION***" << endl;
    cout << UniformCostSearch(inputs[0], inputs[1], records);
};

