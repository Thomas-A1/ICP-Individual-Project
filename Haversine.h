//
// Created by THOMAS QUARSHIE on 11/28/2022.
//
#pragma once
#include <string>
#include <iostream>
using namespace std;
#ifndef C___PROJECT_HAVERSINE_H
#define C___PROJECT_HAVERSINE_H


class Haversine {
public:
    static double distance(double lat1, double long1, double lat2, double long2);
    static double RouteDistance(const string& SourceAirportcode, const string& DestinationAirportcode);

};


#endif //C___PROJECT_HAVERSINE_H
