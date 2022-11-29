//
// Created by THOMAS QUARSHIE on 11/27/2022.
//
#pragma once
#ifndef C___PROJECT_OBJECTS_H
#define C___PROJECT_OBJECTS_H

#include "Routes.h"
#include "Airport.h"
#include "Airline.h"



class Objects{
    /**
     * Creating an Airport object
     * @return Airport_object
     */
public:
    static Airport Airportobject(vector<string> Airportlist);

    __attribute__((unused)) static Airline AirlineObjects(vector<string> Airlinelist);

    __attribute__((unused)) static Routes RouteObject(vector<string> Routelist);

    static string getAirportID(const string& City, const string& Country);

    __attribute__((unused)) static Airport getAirportByCode (const string& AirportCode);
};
#endif //C___PROJECT_OBJECTS_H
