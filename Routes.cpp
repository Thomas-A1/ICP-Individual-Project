//
// Created by THOMAS QUARSHIE on 11/25/2022.
//

#include "Routes.h"
#include "Readfiles.h"
#include "Objects.h"
#include "Haversine.h"
#include <iostream>
#include <string>
using namespace std;

std::unordered_map<std::string, vector<vector<string>>> Routes :: Routemap;
/**
 * Constructor for the Routes class
 * @param airline_code: The unique code for each airline
 * @param sourceAirportCode: The source airport code that identifies the starting point of the airport taken
 * @param destinationAirportCode: The destination Airport code that uniquely identifies the destination airport reached
 */
Routes::Routes(string airline_code, string sourceAirportCode, string destinationAirportCode, int Stops) {
    this->Airline_code = std::move(airline_code);
    this->SourceAirportCode = std::move(sourceAirportCode);
    this->DestinationAirportCode = std::move(destinationAirportCode);
    this->stops = Stops;
}

/**
 * Getter method to return the Airline code
 * @return Airline_code
 */
string &Routes::getAirlineCode(){
    return Airline_code;
}

/**
 * Getter method to return the Source Airport code
 * @return SourceAirportcode
 */
 string Routes::getSourceAirportCode() {
     return SourceAirportCode;
 }

/**
* Getter method to return the Destination Airport code
* @return DestinationAirportCode
*/
string Routes::getDestinationAirportCode() {
    return DestinationAirportCode;
}

/**
 * Getter method to return the number of Stops to get to a destination
 */
int Routes::getStops() const{
    return stops;
}

/**
 * A method that populates the Hashmap with the keys (SourceAirportCode) and its corresponding values (path costs and DestinationAirportcode)
 * @return Hashmap
 */
unordered_map<string, vector<vector<string>>> Routes ::  populateHashmap() {
    string myfilepath = R"(routes.csv)";
    vector<vector<string>> result = Readfile(myfilepath);
    int i = 0;
    for (const vector<string>& element : result){
        vector<vector<string>> values;
        Routes routeobjects = Objects :: RouteObject(element);
        string key = routeobjects.SourceAirportCode;
        vector<string> routecost;
        double cost = Haversine :: RouteDistance(key, routeobjects.getDestinationAirportCode());
        routecost.push_back(to_string(cost));
        routecost.push_back(routeobjects.getDestinationAirportCode());
        routecost.push_back(to_string(routeobjects.getStops()));
        routecost.push_back(routeobjects.getAirlineCode());
        /**If Key is not found in the Routemap**/
        if (Routemap.find(key) == Routemap.end()){
            values.push_back(routecost);
            Routemap[key] =  values;
        }
        else{
            auto it = Routemap.find(key);
            values = it->second;
            values.push_back(routecost);
            Routemap[key] = values;
        }
    }
    return Routemap;
}






