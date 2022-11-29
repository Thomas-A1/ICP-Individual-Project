//
// Created by THOMAS QUARSHIE on 11/27/2022.
//
#include "Airport.h"
#include "Airline.h"
#include "Objects.h"
#include "Routes.h"
#include "RetrieveObj.h"
#include <vector>
#include <string>
using namespace std;

Airport Objects :: Airportobject(vector<string> Airportlist){
    int Airport_id = 0;
    double Latitude = 0.0;
    double Longitude = 0.0;
    double Altitude = 0.0;
    double timezone = 0.0;
    string Airport_name = "";
    string City = "";
    string Country = "";
    string IATA_Code = "";
    string ICAO_Code = "";
    string Data_source = "";
    string Type = "";
    string DST = "";
    string TZ = "";

 /**
  * Tried catching NumberFormatExceptions and handled extreme cases such as column with extra comma's in their records
  * The values you see below (641, 657, 658,...) were obtained by using the getAirportByID method to return records that have their length greater than 14
  * I am commenting the println code out so it doesn't return NumberFormatExceptions in the final Solution (Not to make the work messy)
  */
    if (Airportlist[0]==("641") || Airportlist[0]==("657") ||
    Airportlist[0]==("658") || Airportlist[0]==("664") || Airportlist[0]==("3256")
    || Airportlist[0]==("3340") || Airportlist[0]==("4345") ||
    Airportlist[0]==("4351") || Airportlist[0]==("5582") ||
    Airportlist[0] == ("5583") || Airportlist[0] == ("5589") ||
    Airportlist[0] == ("6898") || Airportlist[0] == ("13714"))   {
        try{
            Latitude = stod(Airportlist[6]);
            Longitude = stod(Airportlist[7]);
        } catch(exception& e){
            //cout << "Number format exception thrown" << endl;
            //cout << e.what() << endl;
        }
        Airport_name = Airportlist[1] + Airportlist[2];
        City = Airportlist[3];
        Country = Airportlist[4];
        IATA_Code = Airportlist[5];
        ICAO_Code = Airportlist[6];
        DST = Airportlist[11];
        TZ = Airportlist[12];
        Type = Airportlist[13];
        Data_source = Airportlist[14];

    } else if (Airportlist[0] == "5562" || Airportlist[0] == "5674" ||
    Airportlist[0] == "5675" || Airportlist[0] == "5881"){
        try{
            Airport_id = std::stoi(Airportlist[0]);
            Latitude = std::stod(Airportlist[6]);
            Longitude = std::stod(Airportlist[7]);
            Altitude = std::stod(Airportlist[8]);
            timezone = std::stod(Airportlist[9]);
        }catch (exception& nfe){
            //cout << "Number Format Exception" << endl;
            //cout << nfe.what() << endl;
        }
        Airport_name = Airportlist[1];
        City = Airportlist[2] + Airportlist[3];
        Country = Airportlist[4];
        IATA_Code = Airportlist[5];
        ICAO_Code = Airportlist[6];
        DST = Airportlist[11];
        TZ = Airportlist[12];
        Type = Airportlist[13];
        Data_source = Airportlist[14];
    } else{
        try{
            Airport_id = std::stoi(Airportlist[0]);
            Latitude = std::stod(Airportlist[6]);
            Longitude = std::stod(Airportlist[7]);
            Altitude = std::stod(Airportlist[8]);
            timezone = std::stod(Airportlist[9]);
        } catch(exception& nfe){
            // Something here
        }
        Airport_name = Airportlist[1];
        City = Airportlist[2];
        Country = Airportlist[3];
        IATA_Code = Airportlist[4];
        ICAO_Code = Airportlist[5];
        DST = Airportlist[10];
        TZ = Airportlist[11];
        Type = Airportlist[12];
        Data_source = Airportlist[13];
    }
    return {Airport_id, Airport_name, City, Country, IATA_Code, ICAO_Code, Latitude,
            Longitude, Altitude, timezone, DST, TZ, Type, Data_source};
    }
    /**
     * Creating an Airline Object
     * @param Airlinelist: Takes a string array
     * @return Airline object
     */
    __attribute__((unused)) Airline Objects :: AirlineObjects(vector<string> Airlinelist){
         int AirlineID = 0;
         try{
             AirlineID = std::stoi(Airlinelist[1]);
         } catch(exception& nfe){
             //cout << "Number Format Exception" << nfe.what() << endl;
         }
         const string& Airlinename = Airlinelist[1];
         const string& Alias = Airlinelist[2];
         const string& IATAcode = Airlinelist[3];
         const string& ICAOcode = Airlinelist[4];
         const string& Call_sign = Airlinelist[5];
         const string& Country = Airlinelist[6];
         const string& Active_state = Airlinelist[7];

         return {AirlineID, Airlinename, Alias, IATAcode, ICAOcode, Call_sign,
                        Country, Active_state};
     }
    /**
     * Creating a Route Object
     * @param Routelist: Takes a string array
     * @return Routes object
     */
    __attribute__((unused)) Routes Objects ::  RouteObject(vector<string> Routelist){
         int Stops = 0;
         try{
             Stops = std::stoi(Routelist[7]);
         } catch(exception& nfe){
             //nfe.what();
         }
         string Airline_code = Routelist[0];
         string SourceAirportCode = Routelist[2];
         string DestinationAirportCode = Routelist[4];

         return {Airline_code, SourceAirportCode, DestinationAirportCode, Stops};
     }

string Objects::getAirportID(const string& City, const string& Country){
        string AirportCode;
        for (auto obj : RetrieveObj::Airport_objects){
            if (obj.getCity() == City && obj.getCountry() == Country){
                AirportCode = obj.getIATA_Code();
            }
        }
        return AirportCode;
    }
__attribute__((unused)) Airport Objects::getAirportByCode(const string& AirportCode) {
         Airport Airport_objects;
         for (Airport airport_obj : RetrieveObj::Airport_objects){
             if (airport_obj.getIATA_Code() == AirportCode){
                 Airport_objects = airport_obj;
             }
         }
         return Airport_objects;
     }



