//
// Created by THOMAS QUARSHIE on 11/29/2022.
//
#include "node.h"
#include <iostream>
#include <fstream>
#include <string>

node :: node(string airportcode, node *parent, double path_cost, string Stops, string airline_code){
this->Airportcode = airportcode;
this->parent = parent;
this->path_cost = path_cost;
this->Stops = Stops;
this->Airline_code = airline_code;

}
/**
 * Overloading Constructor and seeting the values of the other parameter to null depending on the datatype
 * @param airportcode: The unique code that identifies an airport
 */
node::node(string airportcode){
this->Airportcode = airportcode;
this->parent = nullptr;
this->path_cost = 0.0;
this->Stops = "0";
this->Airline_code = " ";
}
string node:: toString(){
    return ""+ Airportcode;
}
/**
 * Description: Method that writes output into a file
 * @param result: The output from one source or root to an expected destination
 */
void node::solution_path(){
    string answer = " ";
    string line = "";
    node *final_node = this;
    double dist = final_node->path_cost;
    int i = 1;
    while(final_node != nullptr && final_node->parent != nullptr){
        cout << final_node->Airportcode << " ";
        line =  (final_node->Airline_code + " from " + final_node->parent->Airportcode  + " to " + final_node->Airportcode  + " with " + final_node->Stops  + " stops \n");
        answer =  line + answer ;
        final_node = final_node->parent;
        cout << answer << endl;
        i++;
    }

    cout << "The total distance is: " << dist << " miles" << endl;
    write_to_file(answer, dist, i);
}
/**
 * Description: Method that writes output into a file
*/
void node:: write_to_file(string result, double dist, int flights){
    ofstream myfile;
    int i = 0;
    string write = "";
    myfile.open("output.txt");
    if(myfile.is_open()){
        myfile << "-----THIS IS THE SOLUTION PATH TRAVELLED-----" << endl;
        myfile << result;
        myfile << "\nTotal Distance: "; 
        myfile << dist; 
        myfile << " KM" << endl;
        myfile << "Total number of fights: " << flights << endl;
        myfile << "The optimality Criteria is the Number of flights" << endl;
        myfile.close();
    }
}

bool node::operator==(const node &name) const {
    return this->Airportcode == name.Airportcode;
}

