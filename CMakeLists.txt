cmake_minimum_required(VERSION 3.23)
project(C___Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(C___Project main.cpp Airline.cpp Airline.h Airport.cpp Airport.h Routes.cpp Routes.h Readfiles.cpp Readfiles.h Objects.cpp RetrieveObj.cpp Objects.h RetrieveObj.h Haversine.cpp Haversine.h Search.cpp Search.h node.h InputFile.h node.cpp)
