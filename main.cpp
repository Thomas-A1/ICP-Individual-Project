
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
    //Readfile(myfilepath);
    RetrieveObj roj;
    roj.my_main();
    cout << "The Airport code for Accra Ghana is: ";
    cout << Objects::getAirportID("Accra", "Ghana") << endl;
    /**
      * Populating hashmap and reading input file to obtain the source city and Destination
      * to be passed into the Uniform cost search algorithm
      * Description: two test cases which has different root city and destination city
      */
    unordered_map<string, vector<vector<string>>> records = Routes::populateHashmap();
    string filelocation =  R"(ZanibaToAccraInputfile.csv)";
    vector<string> inputs = InputFile::readInput(filelocation);
    cout << "The shortest path from " << inputs[0] << " to " << inputs[1] << " is: " << endl;
    cout << UniformCostSearch(inputs[0], inputs[1], records);
    // cout << "The Distance Between DME and UUA is: " << Haversine::RouteDistance("DME", "UUA");
};
