/**
 * Jerry Makris
 * CS 2240
 * Section B
 * Project 1
 */

#include <iostream>
#include <vector>
#include "Flights.h"

/**
 * Main
 */
int main() {
    // Create a vector of Flights objects
    std::vector<Flights> flights;
    std:: string fileName = "../US Airline Flight Routes and Fares 2023-2024.csv";

    if (loadFromFile(fileName, flights)) {
        std::cout << flights.size()
                  << " records read from file." << std::endl;

        int firstID = flights.front().getRowID();
        std::cout << "The first row ID read was " << firstID << std::endl;

        int lastID = flights.back().getRowID();
        std::cout << "The last row ID read was " << lastID << std::endl;
    } else {
        std::cout << "Something went wrong reading from file." << std::endl;
    }

    // Run tests to verify everything is working
    flightsTest();

    // Check for bad data or incorrectly set fields
    verifyAllFieldsSet(flights);

    // Perform calculations to show flight distance and passengers stats
    showFlightStats(flights);

    // Print out a few objects to test overload of <<
    std::cout << std::endl;

    std::cout << std::right
            << std::setw(6) << "RowID"
            << std::setw(6) << "Year"
            << std::setw(9) << "Quarter"
            << std::left
            << "  "
            << std::setw(32) << "Origin City"
            << std::setw(32) << "Destination City"
            << std::setw(16) << "Origin Airport"
            << std::setw(21) << "Destination Airport"
            << std::right
            << std::setw(8) << "Distance"
            << std::setw(12) << "Passengers"
            << std::setw(8) << "Fare"
            << std::endl;
    std::cout << std::string(152, '-') << std::endl;

    for (int i = 0; i < 5; i++) {
        std::cout << flights.at(i) << std::endl;
    }
    std::cout << "  ...." << std::endl;
    for (int i = 9688; i <= 9692; i++) {
        std::cout << flights.at(i) << std::endl;
    }

    return 0;
}