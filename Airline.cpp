/**
 * @author Thomas Quarshie
 * Implementing the member functions in Airline.h
 */
#include "Airline.h"
#include <iostream>
#include <utility>
using namespace std;

Airline::Airline(int Airline_id, string Airline_name, string alias, string IATA_code,
                 string ICAO_code, string Call_sign, string Country, string Active_state){
    this->Airline_id = Airline_id;
    this->Airline_name = std::move(Airline_name);
    this-> alias = std::move(alias);
    this->IATA_code = std::move(IATA_code);
    this->ICAO_code = std::move(ICAO_code);
    this->Call_sign = std::move(Call_sign);
    this->Country = std::move(Country);
    this->Active_state = std::move(Active_state);


}
/**
 * Getter method to return the Airline_name
 * @return Airline_name
 */
const int & Airline::getAirlineId() const{
     return Airline_id;
 }

/**
 * Getter method to return the Airline_name
 * @return Airline_name
 */
string &Airline::getAirlineName(){
    return Airline_name;
}

/**
 * Getter method to return the Alias
 * @return alias
 */
string &Airline::getAlias(){
    return alias;
}

/**
 * Getter method to return the ICAO code
 * @return ICAO_code
 */
string &Airline::getIATACode(){
    return IATA_code;
}

/**
 * Getter method to return the ICAO code
 * @return ICAO_code
 */

string &Airline::getICA0_code(){
    return ICAO_code;
}

/**
 * Getter method to return the Call_sign
 * @return Call sign
 */
string &Airline::getCall_sign(){
    return Call_sign;
}

/**
 * Getter method to return the Country
 * @return Country
 */
string &Airline::getCountry(){
    return Country;
}

/**
 * Getter method to return the Active_state
 * @return Active_state
 */
string &Airline::getActive_State(){
    return Active_state;
}


