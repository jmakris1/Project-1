/**
 * Jerry Makris
 * CS 2240
 * Section B
 * Project 1
 */

#ifndef FLIGHTS_H
#define FLIGHTS_H

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

/**
 * Class representing entries in a csv file list of all flights from 2023 to the beginning of 2024.
 * Data Source: https://www.kaggle.com/datasets/bhavikjikadara/us-airline-flight-routes-and-fares-1993-2024.
 *
 * Fields:
 *      RowID - A unique integer numbering each row starting at the first data point (not the header)
 *      Year - The year the flight took place
 *      Quarter - An integer representing the quarter of the year the flight took place (1-4)
 *      Origin City - A string representing the city the flight took off from.
 *      Destination City - A string representing the city the flight landed at.
 *      Origin Airport - A string representing the 3 letter airport code of the origin airport.
 *      Destination Airport - A string representing the 3 letter airport code of the destination airport.
 *      Distance - An integer representing the distance in miles of the flight path.
 *      Passengers - An integer representing the number of passengers on the flight.
 *      Fare - A double representing the average fare for the purchased tickets on the flight.
 */
class Flights {

private:
    std::string originCity, destinationCity, originAirport, destinationAirport;
    int rowID, year, quarter, distance, passengers;
    double fare;

public:
    // Constructors
    Flights() {
    // Set default values to the fields
        rowID = -1;
        year = -1;
        quarter = -1;
        originCity = "INVALID";
        destinationCity = "INVALID";
        originAirport = "INVALID";
        destinationAirport = "INVALID";
        distance = -1;
        passengers = -1;
        fare = -1.0;
    }

    Flights(int rowID, int year, int quarter,
            std::string originCity, std::string destinationCity,
            std::string originAirport, std::string destinationAirport,
            int distance, int passengers, double fare) {
        this->rowID = rowID;
        this->year = year;
        this->quarter = quarter;
        this->originCity = originCity;
        this->destinationCity = destinationCity;
        this->originAirport = originAirport;
        this->destinationAirport = destinationAirport;
        this->distance = distance;
        this->passengers = passengers;
        this->fare = fare;
    }

    // Getters
    int getRowID() const {
        return rowID;
    }
    int getYear() const {
        return year;
    }
    int getQuarter() const {
        return quarter;
    }
    std::string getOriginCity() const {
        return originCity;
    }
    std::string getDestinationCity() const {
        return destinationCity;
    }
    std::string getOriginAirport() const {
        return originAirport;
    }
    std::string getDestinationAirport() const {
        return destinationAirport;
    }
    int getDistance() const {
        return distance;
    }
    int getPassengers() const {
        return passengers;
    }
    double getFare() const {
        return fare;
    }

    // Setters
    void setRowID(int rowID) {
        this->rowID = rowID;
    }
    void setYear(int year) {
        this->year = year;
    }
    void setQuarter(int quarter) {
        this->quarter = quarter;
    }
    void setOriginCity(std::string originCity) {
        this->originCity = originCity;
    }
    void setDestinationCity(std::string destinationCity) {
        this->destinationCity = destinationCity;
    }
    void setOriginAirport(std::string originAirport) {
        this->originAirport = originAirport;
    }
    void setDestinationAirport(std::string destinationAirport) {
        this->destinationAirport = destinationAirport;
    }
    void setDistance(int distance) {
        this->distance = distance;
    }
    void setPassengers(int passengers) {
        this->passengers = passengers;
    }
    void setFare(double fare) {
        this->fare = fare;
    }

    /**
     * Overload stream insertion operator for nice printing
     */
    friend std::ostream& operator << (std::ostream& outs, const Flights& flightObject)
    {
        outs << std::right                                  // right align numbers
             << std::setw(6) << flightObject.getRowID()     // take up to 4 characters
             << std::setw(6) << flightObject.getYear()      // take up to 4 characters
             << std::setw(9) << flightObject.getQuarter()   // take up to 2 characters
             << std::left                                   // left align strings
             << "  "
             << std::setw(32) << flightObject.getOriginCity()
             << std::setw(32) << flightObject.getDestinationCity()
             << std::setw(16) << flightObject.getOriginAirport()
             << std::setw(21) << flightObject.getDestinationAirport()
             << std::right                                  // right align numbers
             << std::setw(8) << flightObject.getDistance()
             << std::setw(12) << flightObject.getPassengers()
             << std::fixed                                   // fix decimal in place
             << std::setprecision(2)                        // 2 digits after decimal
             << std::setw(8) << flightObject.getFare();

        return outs;
    }

};

// Global functions

/**
 * Read data into a vector from the downloaded CSV file.
 * Returns true if everything goes well; false otherwise.
 */
bool loadFromFile(std::string fileName, std::vector<Flights>& objs) // Populate vector 'objs'
{                                                                   // with Flight objects
    // Open file
    std::ifstream fileIn;  // Declare object named fileIn of type ifstream(used to handle file input)
    fileIn.open(fileName); // Opens the file for reading. Once opened, fileIn can be used to read from it
    // If opening failed, return false
    if (!fileIn)
    {
        // Bad file, could not open
        return false;
    }
    // Opened file OK

    // Get rid of header line - Read it in and throw it away
    std::string header = "";
    getline(fileIn, header);

    // Initialize/Declare variables to be used inside while loop
    int rowID, year, quarter, distance, passengers;
    std::string originCity, destinationCity, originAirport, destinationAirport;
    double fare;
    char comma; // Will come in handy

    // Reads in data while file still has entries left and we haven't
    // reached the end of the file (EOF)
    int counter = 1;
    while(fileIn && fileIn.peek() != EOF) {
        // We initialize variables to sentinel values --
        // values we *know* will not appear in our data.
        // If any object fields have one of these values, we
        // *know* it was incorrectly set.
        rowID = -1;
        year = -1;
        quarter = -1;
        originCity = "INVALID";
        destinationCity = "INVALID";
        originAirport = "INVALID";
        destinationAirport = "INVALID";
        distance = -1;
        passengers = -1;
        fare = -1.0;
        comma = ',';

        // Using the >> (extraction) operator
        fileIn >> rowID; // fileIn expects an int, reads an int
        if (rowID != counter) {
            std::cout << "Row Id" << rowID << "!=" << counter << std::endl;
            return false;
        }
        fileIn >> comma; // Manually read in commas between int values
        fileIn >> year;
        fileIn >> comma;
        fileIn >> quarter;
        fileIn >> comma;

        // getline reads a string, comma is delimiter and is discarded
        getline(fileIn, originCity, ',');
        getline(fileIn, destinationCity, ',');
        getline(fileIn, originAirport, ',');
        getline(fileIn, destinationAirport, ',');
        fileIn >> distance;
        fileIn >> comma;
        fileIn >> passengers;
        fileIn >> comma;
        fileIn >> fare; // expects a float, reads a float

        // Create an instance of a 'Flights' object called 'flight' using data
        // we just read in from the csv file
        Flights flight(rowID, year, quarter, originCity, destinationCity,
                       originAirport, destinationAirport, distance,
                       passengers, fare);
        // Use push_back to append a new element to end of vector 'objs'
        // " vector_name.push_back(element); "
        objs.push_back(flight);
        counter += 1;
    }

    fileIn.close(); // close file
    return true;    // return true for loop to continue until the end of data entries
}

/**
 * Given a vector of Flight objects, calculate average distance
 * and average number of passengers for each year available.
 */
void showFlightStats(std::vector<Flights>& objs) {
    int totalDistance23 = 0;
    int averageDistance23 = 0;
    int totalPassengers23 = 0;
    int averagePassengers23 = 0;

    int totalDistance24 = 0;
    int averageDistance24 = 0;
    int totalPassengers24 = 0;
    int averagePassengers24 = 0;

    int count23 = 0;
    int count24 = 0;

    for(Flights& flights : objs) {
        int year = flights.getYear();
        int distance = flights.getDistance();
        int passengers = flights.getPassengers();

        if (year == 2023) {
            totalDistance23 += distance;
            totalPassengers23 += passengers;
            count23 += 1;
        } else if (year == 2024) {
            totalDistance24 += distance;
            totalPassengers24 += passengers;
            count24 += 1;
        }
    }
    averageDistance23 = totalDistance23 / count23;
    averagePassengers23 = totalPassengers23 / count23;
    averageDistance24 = totalDistance24 / count24;
    averagePassengers24 = totalPassengers24 / count24;

    std::cout << std::endl;
    std::cout << "Flight Distance and Passenger Statistics:" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "2023 Data:" << std::endl;
    std::cout << "Average Distance per flight   : " << std::right << std::setw(3)
              <<averageDistance23 << " Miles" << std::endl;
    std::cout << "Average Passengers per flight : " << std::right << std::setw(3)
              << averagePassengers23 << " Passengers" << std::endl;
    std::cout << std::endl;
    std::cout << "2024 Data:" << std::endl;
    std::cout << "Average Distance per flight   : " << std::right << std::setw(3)
              <<averageDistance24 << " Miles" << std::endl;
    std::cout << "Average Passengers per flight : " << std::right << std::setw(3)
              << averagePassengers24 << " Passengers" << std::endl;
}
/**
 * This verifies that all fields that should be set are set with
 * good values. If any string fields have empty values, we just set it
 * to an empty string. If any integer or double fields are empty,
 * these will be set to a sentinel value of -1 or -1.0. If we ever do
 * calculations on these fields we know then to exclude any values of
 * -1 from our calculations.
 */
void verifyAllFieldsSet(std::vector<Flights>& objs) {
    int i = 0;
    for(Flights& flights : objs) {
        // Row ID should always = i + 1
        if (flights.getRowID() != i + 1) {
            std::cout << "Bad value for row ID at record "
                      << i << std::endl;
        }
        if (flights.getYear() == -1) {
            std::cout << "Bad value for year at record "
                      << i << std::endl;
        }
        if (flights.getQuarter() == -1) {
            std::cout << "Bad value for quarter at record "
                      << i << std::endl;
        }
        std::string originCity = flights.getOriginCity();
        if (originCity.compare("INVALID") == 0) {
            std::cout << "Bad value for origin city at record "
                      << i << std::endl;
        }
        std::string destinationCity = flights.getDestinationCity();
        if (destinationCity.compare("INVALID") == 0) {
            std::cout << "Bad value for destination city at record "
                      << i << std::endl;
        }
        std::string originAirport = flights.getOriginAirport();
        if (originAirport.compare("INVALID") == 0) {
            std::cout << "Bad value for origin airport at record "
                      << i << std::endl;
        }
        std::string destinationAirport = flights.getDestinationAirport();
        if (destinationAirport.compare("INVALID") == 0) {
            std::cout << "Bad value for destination airport at record "
                      << i << std::endl;
        }
        if (flights.getDistance() == -1) {
            std::cout << "Bad value for distance at record "
                      << i << std::endl;
        }
        if (flights.getPassengers() == -1) {
            std::cout << "Bad value for passengers at record "
                      << i << std::endl;
        }
        double fare = flights.getFare();
        if (fare == -1.0) {
            std::cout << "Bad value for fare at record "
                      << i << std::endl;
        }

        i += 1;
    }
}

/**
 * Flights object tests.
 * To ensure constructors, getters, and setters all work correctly.
 */
bool flightsTest() {
    bool passed = true;

    Flights testObject = Flights();

    // Test setters and getters
    testObject.setRowID(1);
    if (testObject.getRowID() != 1) {
        std::cout << "FAILED rowID test" << std::endl;
        passed = false;
    }
    testObject.setYear(1);
    if (testObject.getYear() != 1) {
        std::cout << "FAILED year test" << std::endl;
        passed = false;
    }
    testObject.setQuarter(1);
    if (testObject.getQuarter() != 1) {
        std::cout << "FAILED quarter test" << std::endl;
        passed = false;
    }
    testObject.setOriginCity("Timbuktu");
    if (testObject.getOriginCity() != "Timbuktu") {
        std::cout << "FAILED origin city test" << std::endl;
        passed = false;
    }
    testObject.setDestinationCity("Timbuktu");
    if (testObject.getDestinationCity() != "Timbuktu") {
        std::cout << "FAILED destination city test" << std::endl;
        passed = false;
    }
    testObject.setOriginAirport("TBK");
    if (testObject.getOriginAirport() != "TBK") {
        std::cout << "FAILED origin airport test" << std::endl;
        passed = false;
    }
    testObject.setDestinationAirport("TBK");
    if (testObject.getDestinationAirport() != "TBK") {
        std::cout << "FAILED destination airport test" << std::endl;
        passed = false;
    }
    testObject.setDistance(1);
    if (testObject.getDistance() != 1) {
        std::cout << "FAILED distance test" << std::endl;
        passed = false;
    }
    testObject.setPassengers(1);
    if (testObject.getPassengers() != 1) {
        std::cout << "FAILED passengers test" << std::endl;
        passed = false;
    }
    testObject.setFare(1.0);
    if (testObject.getFare() != 1.0) {
        std::cout << "FAILED fare test" << std::endl;
        passed = false;
    }

    return passed;
}

#endif //FLIGHTS_H
