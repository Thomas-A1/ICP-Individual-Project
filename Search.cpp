//
// Created by THOMAS QUARSHIE on 11/28/2022.
//
#include <iostream>
#include "Search.h"
#include "Routes.h"
#include <algorithm>
#include "node.h"
#include <unordered_set>
#include <deque>
#include <utility>
using namespace std;


//string Search :: SourceAirportcode;
//string Search :: DestinationAirportcode;

//Search :: Search(string SourceAirportcode, string DestinationAirportcode){
//    Search::SourceAirportcode = std::move(SourceAirportcode);
//    Search::DestinationAirportcode = std::move(DestinationAirportcode);
//}
//
//string Search :: toString() {
//    return "From Source to Destination: ";
//}
///**
// * A Goal test method that checks if a particular location reached
// * while searching through the Hashmap is the expected destination
// * @param location: A specific location reached
// */
// bool Search ::goal_test(const string& location) {
//     return false;
// }
//
///**
//* Actions method to return the sequence of actions taken to reach a goal
//* @return null (for now)
//*/

// OptimalDistance::OptimalDistance(const string& sourceAirportcode, const string& destinationAirportcode,
//                                 unordered_map<std::string, vector<vector<std::string>>> maps) {
//    OptimalDistance::SourceAirportcode = SourceAirportcode;
//    OptimalDistance::DestinationAirportcode = DestinationAirportcode;
//    OptimalDistance::mymap = maps;
// }

bool OptimalDistance::goal_test(const std::string &location, const std::string &Destination) {
    return location.compare(Destination) == 0;
}

/**
 * The actions method that will return a string array of the all possible
 * routes it took to get to the destination
 * @param Sourcecode: The Airport source code to be passed
 * @return Actions arraylist
 */
vector<vector<string>> OptimalDistance::actions(const string& Sourcecode, unordered_map<string, vector<vector<string>>>record){
    unordered_map<string, vector<vector<string>>> key_neighbours = record;
    vector<string> transition_costs;
    vector<string> successor_states;
    vector<string> Stops;
    vector<string> Airline_codes;
    vector<vector<string>> sequence;
    //auto rslt = find(key_neighbours.begin(), key_neighbours.end(), Sourcecode);
    if (key_neighbours.find(Sourcecode) != key_neighbours.end()){
        vector<vector<string>> values = key_neighbours[Sourcecode];
        for (vector<string> neighbour : values){
            // try{
                transition_costs.push_back(neighbour[0]); 
                successor_states.push_back(neighbour[1]);
                Stops.push_back(neighbour[2]);
                Airline_codes.push_back(neighbour[3]);
            // } catch(exception& ob){
            //     //Exception code goes here
            // }
        }
        sequence.push_back(transition_costs);
        sequence.push_back(successor_states);
        sequence.push_back(Stops);
        sequence.push_back(Airline_codes);
        return sequence;
    }
    return sequence;

}


/**
 * UniformCostSearch - Search algorithm to compute the optimal distance from one source location to its destination
 * @param startcity: The city were the journey or traversal started (root)
 * @param Destinationcity: The city were the journey or traversal ends
 * @return boolean
 */


