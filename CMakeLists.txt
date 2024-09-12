cmake_minimum_required(VERSION 3.15)
project(Project1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Project1
        main.cpp
        Flights.h
        "US Airline Flight Routes and Fares 2023-2024.csv")
