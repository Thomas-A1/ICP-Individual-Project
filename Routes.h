//
// Created by THOMAS QUARSHIE on 11/25/2022.
//
#pragma once
#ifndef C___PROJECT_ROUTES_H
#define C___PROJECT_ROUTES_H
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;


class Routes {
    /**
     * Instance Variables
     */
private:
    string Airline_code;
    string SourceAirportCode;
    string DestinationAirportCode;
    int stops;

    /**
     * Constructor for the Routes class
     * @param airline_code: The unique code for each airline
     * @param sourceAirportCode: The source airport code that identifies the starting point of the airport taken
     * @param destinationAirportCode: The destination Airport code that uniquely identifies the destination airport reached
     */
public:
    Routes(string airline_code, string sourceAirportCode, string destinationAirportCode, int Stops);

    // Overriding tostring() method
    //inline std::ostream &operator<<(ostream &Str);

    /**
     * Getter method to return the Airline code
     * @return Airline_code
     */
    string &getAirlineCode();

    /**
     * Getter method to return the Source Airport code
     * @return SourceAirportcode
     */
    string getSourceAirportCode();

    /**
     * Getter method to return the Destination Airport code
     * @return DestinationAirportCode
     */
     string getDestinationAirportCode();

    /**
     * Getter method to return the number of Stops to get to a destination
     */
    int getStops() const;

    /**
     * A method that populates the Hashmap with the keys (SourceAirportCode) and its corresponding values (path costs and DestinationAirportcode)
     * @return Hashmap
     */
    //
    static unordered_map<string, vector<vector<string>>> populateHashmap();

// A static Hashmap that will be populated with Key(SourceAirportcode), value(DestinationAirportcode and pathcost)
static std::unordered_map<std::string, vector<vector<string>>> Routemap;
};


#endif //C___PROJECT_ROUTES_H
