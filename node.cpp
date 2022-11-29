//
// Created by THOMAS QUARSHIE on 11/29/2022.
//
#include "node.h"

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
void node::solution_path(){
    vector<node> result;
    node *final_node = this;
    while(final_node != nullptr){
        result.push_back(*final_node);
        final_node = final_node->parent;
    }
    //write_to_file(result);

}

bool node::operator==(const node &name) const {
    return this->Airportcode == name.Airportcode;
}
