//
// Created by THOMAS QUARSHIE on 11/29/2022.
//
#pragma once
#include <iostream>
#include <vector>
#ifndef C___PROJECT_NODE_H
#define C___PROJECT_NODE_H
using namespace std;

class node {
    /**
     * Constructor for the Node class
     * @param airportcode: The Airport code
     * @param parent: The parent node
     * @param path_cost: The cost in moving from one city to another
     */
public:
        string Airportcode;
        node *parent;
        double path_cost{};
        string Stops;
        string Airline_code;

        node(string airportcode, node *parent, double path_cost, string Stops, string airline_code);


    /**
     * Overloading Constructor and setting the values of the other parameter to null depending on the datatype
     * @param airportcode: The unique code that identifies an airport
     */
    node(string airportcode);

    /**
     * Description: Method that writes output into a file
     * @param result: The output from one source or root to an expected destination
     */
    void write_to_file(string result, double dist, int flights);

    string toString();
    void solution_path();
    bool operator==(const node& name) const;
};

#endif //C___PROJECT_NODE_H

