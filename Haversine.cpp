//
// Created by THOMAS QUARSHIE on 11/28/2022.
//

#include "Haversine.h"
#include "Airport.h"
#include "Objects.h"
#include <iostream>
#include <cmath>
using namespace std;

double Haversine ::distance(double lat1, double long1, double lat2, double long2) {
    double dLatitude = (lat2 - lat1) * M_PI / 180.0;
    double dLongitude = (long2 - long1) * M_PI / 180.0;

    // Converting to Radians
    lat1 = (lat1) * M_PI / 180.0;
    lat2 = (lat2) * M_PI / 180.0;
    // Formula
    double a = pow(sin(dLatitude / 2), 2) + pow(sin(dLongitude / 2), 2) *
            cos(lat1) * cos(lat2);
    double radians = 6371;
    double circumference = 2 * asin(sqrt(a));

    return radians * circumference; // <----Distance
}

/**
 * @author: Thomas Kojo Quarshie (ME)
 * @param SourceAirportcode: The starting Airport code
 * @param DestinationAirportcode: The destination Airport code
 * Description: The RouteDistance method that returns the total distance in Kilometres in moving from the SourceAirportcode
 * to the DestinationAirportcode
 * @return double
 */
double Haversine ::RouteDistance(const std::string& SourceAirportcode, const std::string& DestinationAirportcode) {
    Airport root = Objects ::getAirportByCode(SourceAirportcode);
    Airport Destination = Objects ::getAirportByCode(DestinationAirportcode);
    double result = distance(root.getLatitude(), root.getLongitude(), Destination.getLatitude(), Destination.getLongitude());
    return result;
}
