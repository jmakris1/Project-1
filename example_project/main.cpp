/**
 * Clayton Cafiero
 * CS 124
 * Section Z
 */

#include <vector>
#include <iostream>
#include "Kepler.h"

/**
 * Main
 */
int main() {

    std::vector<Kepler> exoplanets;
    std::string fn = "../kepler_exoplanet.csv";

    if (loadFromFile(fn, exoplanets)) {
        std::cout << exoplanets.size()
            << " records read from file" << std::endl;
        int firstId = exoplanets.front().getRowId();
        std::cout << "The last row ID read was " << firstId << std::endl;
        int lastId = exoplanets.back().getRowId();
        std::cout << "The last row ID read was " << lastId << std::endl;
    } else {
        std::cout << "Something went wrong." << std::endl;
    }

    // Run tests to verify everything is working correctly.
    keplerTest();

    // Check for bad data or incorrectly set fields.
    verifyAllFieldsSet(exoplanets);

    // Perform our calculation and display disposition statistics.
    showDispositionStats(exoplanets);

    // Print a few object to test overload of <<
    std::cout << std::endl;

    std::cout << std::right
            << std::setw(6) << "Row ID"
            << std::setw(10) << "Kepler ID"
            << std::left
            << "  "
            << std::setw(12) << "KOI name"
            << std::setw(14) << "Kepler name"
            << std::setw(16) << "Disposition"
            << std::right
            << std::setw(7) << "Score"
            << std::setw(10) << "RA"
            << std::setw(10) << "Dec"
            << std::setw(10) << "Mag"
            << std::endl;
    std::cout << std::string(97, '-') << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << exoplanets.at(i) << std::endl;
    }

}
