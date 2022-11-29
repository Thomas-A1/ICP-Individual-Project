//
// Created by THOMAS QUARSHIE on 11/28/2022.
//
#pragma once
#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include <unordered_map>
#include "node.h"
#include <unordered_set>
#include <deque>
#include <algorithm>
#include "Search.h"


using namespace std;
#ifndef C___PROJECT_SEARCH_H
#define C___PROJECT_SEARCH_H


//class Search {
//    /**
//     * Instance Variables
//     * The SourceAirportcode as the starting point and the DestinationAirportcode as the destination
//     */
//private:
//    static string SourceAirportcode;
//    static string DestinationAirportcode;
//
//public:
//    /**
//     * Constructor for the search class
//     */
//    Search(string SourceAirportcode, string DestinationAirportcode);
//    /**
//     * A Goal test method that checks if a particular location reached
//     * while searching through the Hashmap is the expected destination
//     * @param location: A specific location reached
//     */
//     static bool goal_test(const string& location);
//     /**
//      * toString() method
//      */
//     string toString();
//};
 //Child class extending Search class

class OptimalDistance {
private:
    static unordered_map<string, vector<vector<string>>> mymap;
    static string SourceAirportcode;
    static string DestinationAirportcode;
    /**
     * Constructor for the OptimalDistance class
     * @param SourceAirportcode: The root or starting Airport code
     * @param DestinationAirportcode: The destination Airport code reached
     * @param mymap: The Hashmap to keep track of the key, value pairs
     */
public:
    OptimalDistance(const string& sourceAirportcode, const string& destinationAirportcode,
                    unordered_map<std::string, vector<vector<std::string>>> maps);
    /**
     * Goal test method to check if a particular destination is the same as the expected destination
     * @param location: The particular point reached in the search tree
     * @param Destination: The goal expected
     * @return boolean
     */
     static bool goal_test(const string& location, const string& Destination);

    /**
     * The actions method that will return a string array of the all possible
     * routes it took to get to the destination
     * @param Sourcecode: The Airport source code to be passed
     * @return Actions arraylist
     */
     static vector<vector<string>> actions(const string& Sourcecode, unordered_map<string, vector<vector<string>>>record);
};
/**
 * Node class which implements the Comparable interface to have access to the compareTo method
 * for comparing two objects if they're the same
 */

    /**
     * UniformCostSearch - Search algorithm to compute the optimal distance from one source location to its destination
     * @param startcity: The city were the journey or traversal started (root)
     * @param Destinationcity: The city were the journey or traversal ends
     * @return boolean
     */
     static bool UniformCostSearch(const string& startcity, const string& Destinationcity, unordered_map<string, vector<vector<string>>>record){
        cout << "Performing Uniform Cost Search from " + startcity + " to " + Destinationcity << endl;
        node* root = new node(startcity);
        //Frontier as a PriorityQueue
        deque<node> frontier;
        frontier.push_back(*root);
        unordered_set<string> explored;
        explored.insert(root->Airportcode);
        while(!(frontier.empty())){
            node *popped_node = new node(frontier.front().Airportcode, frontier.front().parent, frontier.front().path_cost, frontier.front().Stops, frontier.front().Airline_code);
            cout << "Checking....Currently at the Airport code: " + popped_node->Airportcode << endl;
            frontier.pop_front();
            if (OptimalDistance::goal_test(popped_node->Airportcode, Destinationcity)){
                cout << "Yayy!! Found a Solution: " + popped_node->Airportcode << endl;
                popped_node->solution_path();
                return true;
            }
            // Adding popped node to the explored set
            explored.insert(popped_node->Airportcode);

            //explored.begin(), explored.end(), *popped_node;
            vector<vector<string>> actionRes = OptimalDistance::actions(popped_node->Airportcode, record);
            cout << popped_node->Airportcode << endl;
            vector<string> costs;
            vector<string> successor;
            vector<string> stops;
            vector<string> airline;
            /**
             * Description: Checking for extreme cases where the destination to get to is nill
             */
            // try{
                costs = actionRes[0];
                successor = actionRes[1];
                stops = actionRes[2];
                airline = actionRes[3];
            // } catch(exception& nfe){
            //     cout << "No path found to the destination" << endl;
            //     // Write code here
            // }
            for (int i = 0; i < costs.size(); i++){
                double old_pathcost = std::stod(costs[i]) + popped_node->path_cost;
                int stops_increment = std::stoi(stops[i]) + std::stoi(popped_node->Stops);
                node *child = new node(successor[i], popped_node, std::stod(costs[i]) + popped_node->path_cost, to_string(stops_increment), airline[i]);
                /**
                 * Description: If the child node is not in the frontier and explored set, then we add it to the frontier (i.e., to avoid redundancies)
                 */
                auto it = find(frontier.begin(), frontier.end(), *child);
                if((explored.find(successor[i]) == explored.end() || it == frontier.end())){
                    frontier.push_back(*child);
                }// } else{
                //     if (child->path_cost < old_pathcost){
                //         child->parent = popped_node->parent;
                //         explored.erase(child->Airportcode);
                //         //std::remove(explored.begin(), explored.end(),(child->Airportcode));
                //         frontier.push_back(*child);
                //     }
                // }
            }

        }
        return false;



    }


#endif //C___PROJECT_SEARCH_H
