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
                transition_costs.push_back(neighbour[0]); 
                successor_states.push_back(neighbour[1]);
                Stops.push_back(neighbour[2]);
                Airline_codes.push_back(neighbour[3]);
        }
        sequence.push_back(transition_costs);
        sequence.push_back(successor_states);
        sequence.push_back(Stops);
        sequence.push_back(Airline_codes);
        return sequence;
    }
    return sequence;
}





