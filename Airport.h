/**
 * @author Thomas Quarshie
 * Creating an Airport class and deriving an instance of it to access its attributes
 */
#pragma once
#ifndef C___PROJECT_AIRPORT_H
#define C___PROJECT_AIRPORT_H
#include <iostream>
#include <string>
using namespace std;


class Airport {
private:
    /**
     * Instance Variables
     */
    int Airport_id;
    string Airport_name;
    string City;
    string Country;
    string IATA_Code;
    string ICAO_Code;
    double Latitude;
    double Longitude;
    double Altitude;
    double timezone;
    string DST;
    string TZ;
    string Type;
    string Data_source;
public:
    Airport(int Airport_id, string Airport_name, string City, string Country,
            string IATA_Code, string ICAO_Code, double Latitude, double Longitude,
            double Altitude, double timezone, string DST, string TZ, string Type,
            string Data_source);
    Airport();

    //Overriding toString() method
    //inline std::ostream & operator<<(std::ostream & Str, Airport const & v);

    __attribute__((unused)) int getAirportId() const;
    __attribute__((unused)) string &getAirport_name();
    string &getCity();
    string &getCountry();
    string &getIATA_Code();
    __attribute__((unused)) double getLatitude() const;

    __attribute__((unused)) double getLongitude() const;

    __attribute__((unused)) double getAltitude() const;

    __attribute__((unused)) double getTimezone() const;

    __attribute__((unused)) string &getDST() ;

    __attribute__((unused)) string &getTZ() ;

    __attribute__((unused)) string &getType() ;

    __attribute__((unused)) string &getData_source() ;
};


#endif //C___PROJECT_AIRPORT_H
