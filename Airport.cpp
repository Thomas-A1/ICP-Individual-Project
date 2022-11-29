/**
 * @author Thomas Quarshie
 * Implementing the Airport class and deriving an instance of it to access its attributes
 */
#include "Airport.h"

/**
 * @param Airport_id
 * @param Airport_name
 * @param City
 * @param Country
 * @param IATA_Code
 * @param ICAO_Code
 * @param Latitude
 * @param Longitude
 * @param Altitude
 * @param timezone
 * @param DST
 * @param TZ
 * @param Type
 * @param Data_source
 */

Airport::Airport(int Airport_id, std::string Airport_name, std::string City, std::string Country, std::string IATA_Code,
                 std::string ICAO_Code, double Latitude, double Longitude, double Altitude, double timezone,
                 std::string DST, std::string TZ, std::string Type, std::string Data_source) {
    this->Airport_id = Airport_id;
    this->Airport_name = std::move(Airport_name);
    this->City = std::move(City);
    this->Country = std::move(Country);
    this->IATA_Code = std::move(IATA_Code);
    this->ICAO_Code = std::move(ICAO_Code);
    this->Latitude = Latitude;
    this->Longitude = Longitude;
    this->Altitude = Altitude;
    this->timezone = timezone;
    this->DST = std::move(DST);
    this->TZ = std::move(TZ);
    this->Type = std::move(Type);
    this->Data_source = std::move(Data_source);
}


Airport::Airport() {
    this->Airport_id = 0;
    this->Airport_name = "";
    this->City = "";
    this->Country = "";
    this->IATA_Code = "";
    this->ICAO_Code = "";
    this->Latitude = 0.0;
    this->Longitude = 1777.0;
    this->Altitude = 1.0;
    this->timezone = 1.0;
    this->DST = "";
    this->TZ = "";
    this->Type = "";
    this->Data_source = "";

}

__attribute__((unused)) int Airport::getAirportId() const{
    return Airport_id;
}

__attribute__((unused)) string &Airport::getAirport_name(){
    return this->Airport_name;
}

string &Airport::getCity(){
    return this->City;
}

string &Airport::getCountry(){
    return this->Country;
}

string &Airport::getIATA_Code(){
    return this->IATA_Code;
}


__attribute__((unused)) double Airport::getLatitude() const{
    return this->Latitude;
}

__attribute__((unused)) double Airport::getLongitude() const{
    return this->Longitude;
}

__attribute__((unused)) double Airport::getAltitude() const{
    return this->Altitude;
}

__attribute__((unused)) double Airport::getTimezone() const{
    return this->timezone;
}

__attribute__((unused)) string & Airport::getDST(){
    return this->DST;
}

__attribute__((unused)) string &Airport::getTZ(){
    return this->TZ;
}

__attribute__((unused)) string &Airport::getType(){
    return this->Type;
}

__attribute__((unused)) string &Airport::getData_source(){
    return this->Data_source;
}
