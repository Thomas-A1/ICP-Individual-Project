//
// Created by THOMAS QUARSHIE on 11/27/2022.
//
#pragma once
#ifndef C___PROJECT_RETRIEVEOBJ_H
#define C___PROJECT_RETRIEVEOBJ_H
#include <vector>
#include "Airport.h"

class RetrieveObj{
public:
    __attribute__((unused)) void my_main(); //static was here

    static vector<Airport> Airport_objects;
};

#endif //C___PROJECT_RETRIEVEOBJ_H
