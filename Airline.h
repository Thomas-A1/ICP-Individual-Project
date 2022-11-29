//
// Created by THOMAS QUARSHIE on 11/25/2022.
//
#pragma once
#ifndef C___PROJECT_AIRLINE_H
#define C___PROJECT_AIRLINE_H
#include <iostream>
#include <string>
using namespace std;


/**
 * @author Thomas Quarshie
 * Creating a class for the Airlines and deriving an instance of it to access its attributes
 */
class Airline{
    /**
     * Instance Variables
     */
private:
    int Airline_id;
    string Airline_name;
    string alias;
    string IATA_code;
    string ICAO_code;
    string Call_sign;
    string Country;
    string Active_state;

    /**
 * @param Airline_id: Uniquely identifies an Airline
 * @param alias: The alias of an Airline
 * @param IATA_code: Uniquely identifies the Airport
 * @param ICAO_code: Identifies the region and country the airline is located
 * @param Call_sign: The message transmission for an airline
 * @param Country: The country where the Airline is located
 * @param Active_state: Whether the Airline is active or not
 */
public:
    Airline(int Airline_id, string Airline_name, string alias, string IATA_code,
            string ICAO_code, string Call_sign, string Country, string Active_state);

//    inline std::ostream & operator<<(std::ostream & Str, Airline const & v);
//    operator std::string();

    /**
  * Declaring Getter methods for the fields in the Airline class
  * Since the fields are const, there's no need for a mutator method
  */
    const int &getAirlineId() const;
    string &getAirlineName();
    string &getAlias();
    string &getIATACode();
    string &getICA0_code();
    string &getCall_sign();
    string &getCountry();
    string &getActive_State();


};


#endif //C___PROJECT_AIRLINE_H
