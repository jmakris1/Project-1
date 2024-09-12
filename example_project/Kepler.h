/**
 * Clayton Cafiero
 * Edited by Lisa Dion
 * CS 2240
 * Section Z
 */

#ifndef KEPLER_H
#define KEPLER_H

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

/**
 * Class representing entries in the NASA Exoplanet Archive's list of
 * exoplanets. See: https://exoplanetarchive.ipac.caltech.edu/ for additional
 * details.
 *
 * Fields (naming follows abbreviations used in CSV file):
 *     rowId: a unique integer serial number indicating row in source data
 *     kepId: the target identification number in the Kepler Input Catalog (KIC)
 *     kepoiName: Kepler object of interest (KOI) name; a string consisting of
 *        a number prefixed by the letter "K"; the integer part of the number
 *        designates the target star, and the two-digit decimal part designates 
 *        the unique transiting object of interest; example "K00747.01"
 *     keplerName: a string in the form "Kepler-N n" where n designates the
 *        planet in question; example "Kepler-661 b". If assigned, the assigned
 *        value is unique, but it may be empty.
 *     koiDisposition: KOI disposition; a string; one of "CANDIDATE",
 *        "CONFIRMED", "FALSE POSITIVE" or "NOT DISPOSITIONED" indicating the
 *        status of the Kepler object of interest
 *     koiScore: KOI score; a float between 0 and 1 indicating the confidence
 *        in the KOI disposition; may be empty in which case it will be
 *        assigned a sentinel value of -1
 *     ra: a float representing KIC right ascension (degrees)
 *     dec: a float representing KIC declination (degrees)
 *     koiKepmag: KOI Kepler magnitude; a float representing the estimated
 *        magnitude in the Kepler band; may be empty in which case it will be
 *        assigned a sentinel value of -1
 */
class Kepler {

private:
    std::string kepoiName, keplerName, koiDisposition;
    int rowId, kepId;
    double koiScore, ra, dec, koiKepmag;

public:
    // Constructors
    Kepler() {
        // Set default values to the fields
        rowId = -1;
        kepId = -1;
        kepoiName = "INVALID";
        keplerName = "INVALID";
        koiDisposition = "INVALID";
        koiScore = -1.0;
        ra = -1.0;
        dec = -1.0;
        koiKepmag = -1.0;
    }

    Kepler(int rowId,
           int kepId,
           std::string kepoiName,
           std::string keplerName,
           std::string koiDisposition,
           double koiScore,
           double ra,
           double dec,
           double koiKepmag) {
        this->rowId = rowId;
        this->kepId = kepId;
        this->kepoiName = kepoiName;
        this->keplerName = keplerName;
        this->koiDisposition = koiDisposition;
        this->koiScore = koiScore;
        this->ra = ra;
        this->dec = dec;
        this->koiKepmag = koiKepmag;
    }

    // Getters
    int getRowId() const {
        return rowId;
    }

    int getKepId() const {
        return kepId;
    }

    std::string getKepoiName() const {
        return kepoiName;
    }

    std::string getKeplerName() const {
        return keplerName;
    }

    std::string getKoiDisposition() const {
        return koiDisposition;
    }

    double getKoiScore() const {
        return koiScore;
    }

    double getRa() const {
        return ra;
    }

    double getDec() const {
        return dec;
    }

    double getKoiKepmag() const {
        return koiKepmag;
    }

    // Setters
    void setRowId(int rowId) {
        this->rowId = rowId;
    }

    void setKepId(int kepId) {
        this->kepId = kepId;
    }

    void setKepoiName(std::string kepoiName) {
        this->kepoiName = kepoiName;
    }

    void setKeplerName(std::string keplerName) {
        this->keplerName = keplerName;
    }

    void setKoiDisposition(std::string koiDisposition) {
        this->koiDisposition = koiDisposition;
    }

    void setKoiScore(double koiScore) {
        this->koiScore = koiScore;
    }

    void setRa(double ra) {
        this->ra = ra;
    }

    void setDec(double dec) {
        this->dec = dec;
    }

    void setKoiKepmag(double koiKepmag) {
        this->koiKepmag = koiKepmag;
    }

    /**
     * Overload stream insertion operator for pretty printing
     */
    friend std::ostream& operator << (std::ostream& outs, const Kepler& kObj) {
        outs << std::right                      // right align numbers
             << std::fixed                      // fix decimal in place
             << std::setprecision(4)            // four digits after decimal
             << std::setw(6) << kObj.getRowId() // take up six characters
             << std::setw(10) << kObj.getKepId()
             << std::left                       // left align strings
             << "  "
             << std::setw(12) << kObj.getKepoiName()
             << std::setw(14) << kObj.getKeplerName()
             << std::setw(16) << kObj.getKoiDisposition()
             << std::right
             << std::setw(7) << kObj.getKoiScore()
             << std::setw(10) << kObj.getRa()
             << std::setw(10) << kObj.getDec()
             << std::setw(10) << kObj.getKoiKepmag();
        return outs;
    }

    // We don't need these right away, but we will for future projects
    // Compare objects using the unique identifying field (for Kepler, rowId)

    /**
     * Overload < operator for object comparison
     */
    friend bool operator < (const Kepler& lhs, const Kepler& rhs) {
        return lhs.getRowId() < rhs.getRowId();
    }

    /**
     * Overload > operator for object comparison
     */
    friend bool operator > (const Kepler& lhs, const Kepler& rhs) {
        return lhs.getRowId() > rhs.getRowId();
    }

    /**
     * Overload <= operator for object comparison
     */
    friend bool operator <= (const Kepler& lhs, const Kepler& rhs) {
        return lhs.getRowId() <= rhs.getRowId();
    }

    /**
     * Overload >= operator for object comparison
     */
    friend bool operator >= (const Kepler& lhs, const Kepler& rhs) {
        return lhs.getRowId() >= rhs.getRowId();
    }

    /**
     * Overload == operator for object comparison
     */
    friend bool operator == (const Kepler& lhs, const Kepler& rhs) {
        return lhs.getRowId() == rhs.getRowId();
    }

    /**
     * Overload != operator for object comparison
     */
    friend bool operator != (const Kepler& lhs, const Kepler& rhs) {
        return lhs.getRowId() != rhs.getRowId();
    }

};

// Global functions

/**
 * Read data into a vector from the downloaded CSV file.
 * Returns true if everything goes well; false otherwise.
 */
bool loadFromFile(std::string fn, std::vector<Kepler>& objs) {
    std::ifstream fin;
    fin.open(fn);

    if (!fin) {
        // Bad file / could not open
        return false;
    }

    // Opened file OK

    // Get rid of the header line: read it and throw it away
    std::string header = "";
    getline(fin, header);

    // Declare variables to be used inside the while loop
    int rowId, kepId;
    std::string kepoiName, keplerName, koiDisposition;
    double koiScore, ra, dec, koiKepmag;
    char comma; // This will come in handy.

    // Read in data while the file is still good
    // and we haven't yet reached the end of file (EOF).
    int counter = 1;
    while (fin && fin.peek() != EOF) {
        // We initialize variables to sentinel values --
        // values we *know* will not appear in our data.
        // If any object fields have one of these values, we
        // *know* it was incorrectly set.
        rowId = -1;
        kepId = -1;
        kepoiName = "INVALID";
        keplerName = "INVALID";
        koiDisposition = "INVALID";
        koiScore = -1.0;
        ra = -1.0;
        dec = -1.0;
        koiKepmag = -1.0;
        comma = ',';  

        // Your input data file will be different. You will have different
        // fields, different values, etc. What follows below may be helpful
        // but you'll need to modify to suit your data.

        // Using the >> (extraction) operator ...
        fin >> rowId;  // Expects an int; reads an int.
        if (rowId != counter) {
            std::cout << rowId << " != " << counter << std::endl;
            return false;
        }
        fin >> comma; // Manually read in the comma between int values
        fin >> kepId;
        fin >> comma;
        // These read a string; comma is delimiter and is discarded.
        getline(fin, kepoiName, ',');
        getline(fin, keplerName, ',');
        getline(fin, koiDisposition, ',');
        fin >> koiScore;
        if (!fin) {  // koiScore might be empty!
            koiScore = -1;
            fin.clear();
        }
        fin >> comma;
        fin >> ra;  // Expects a float; reads a float.
        fin >> comma;
        fin >> dec;
        fin >> comma;
        // We can't use the technique we used above. Here we check
        // to make sure that the next character isn't a newline or
        // carriage return. This will happen if koi_kepmag is missing
        // in the source data file (there's one annoying record).
        if (fin.peek() != '\r' && fin.peek() != '\n') {
            fin >> koiKepmag;
        }
        Kepler exoplanet(rowId, kepId, kepoiName, keplerName,
                         koiDisposition, koiScore, ra, dec,
                         koiKepmag);
        objs.push_back(exoplanet);
        counter += 1;
    }
    fin.close();
    return true;
}

/**
 * Given a vector of exoplanet objects, calculate
 * subtotals by disposition.
 */
void showDispositionStats(std::vector<Kepler>& objs) {
    int candidates = 0;
    int confirmed = 0;
    int falsePositives = 0;
    int notDispositioned = 0;
    int other = 0;
    int total;

    for (Kepler& kep : objs) {
        std::string disposition = kep.getKoiDisposition();
        if (disposition.compare("CANDIDATE") == 0) {
            candidates += 1;
        } else if (disposition.compare("CONFIRMED") == 0) {
            confirmed += 1;
        } else if (disposition.compare("FALSE POSITIVE") == 0) {
            falsePositives += 1;
        } else if (disposition.compare("NOT DISPOSITIONED") == 0) {
            notDispositioned += 1;
        } else {
            // This should never happen! If this is anything other than
            // 0 we know something unexpected has occurred, e.g., some
            // value for KOI disposition not included in the above.
            other += 1;
        }
    }

    total = candidates + confirmed + falsePositives + notDispositioned + other;

    std::cout << std::endl;
    std::cout << "Disposition statistics" << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << "Candidates" << std::right << std::setw(15)
              << candidates << std::endl;
    std::cout << "Confirmed" << std::right << std::setw(16)
              << confirmed << std::endl;
    std::cout << "False positives" << std::right << std::setw(10)
              << falsePositives << std::endl;
    std::cout << "Not dispositioned" << std::right << std::setw(8)
              << notDispositioned << std::endl;
    std::cout << "Other" << std::right << std::setw(20)
              << other << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << "Total" << std::right << std::setw(20)
              << total << std::endl;
    std::cout << "==========================" << std::endl;
}

/**
 * This verifies that all fields that should be set are set with
 * good values. Some fields may have missing values, e.g. keplerName,
 * koiScore and koiKepmag. In the case of keplerName, we just set it
 * to empty string. koiScore and koiKepmag are doubles so if a value
 * is missing in the source data, these will be set to a sentinel
 * value of -1. If we ever do calculations on these fields we know
 * then to exclude any values of -1 from our calculations.
 */
void verifyAllFieldsSet(std::vector<Kepler>& objs) {
    int i = 0;
    for (Kepler& kep : objs) {
        // Row ID should always = i + 1
        if (kep.getRowId() != i + 1) {
            std::cout << "Bad value for row ID at record "
                      << i << std::endl;
        }
        if (kep.getKepId() == -1) {
            std::cout << "Bad value for Kepler ID at record "
                      << i << std::endl;
        }
        std::string kepoiName = kep.getKepoiName();
        if (kepoiName.compare("INVALID") == 0) {
            std::cout << "Bad value for KOI name at record "
                      << i << std::endl;
        }
        std::string keplerName = kep.getKeplerName();
        if (keplerName.compare("INVALID") == 0) {
            std::cout << "Bad value for Kepler name at record "
                      << i << std::endl;
        }
        std::string koiDisposition = kep.getKoiDisposition();
        if (koiDisposition.compare("INVALID") == 0) {
            std::cout << "Bad value for disposition at record "
                      << i << std::endl;
        }
        // KOI score may be empty in source, hence "missing" if = -1
        // We'll let these pass silently
        double ra = kep.getRa();
        if (ra == -1) {
            std::cout << "Bad value for right ascension at record "
                      << i << std::endl;
        }
        double dec = kep.getDec();
        if (dec == -1) {
            std::cout << "Bad value for declination at record "
                      << i << std::endl;
        }
        // KOI Kepler magnitude may be empty in source, hence "missing" if = -1
        // We'll let these pass silently
        i += 1;
    }
}

/**
 * Kepler object tests.
 * To ensure constructors, getters, and setters all work properly.
 */
bool keplerTest() {
    bool passed = true;
    Kepler testObject = Kepler();
    // Test setters and getters
    testObject.setRowId(1);
    if (testObject.getRowId() != 1) {
        cout << "FAILED rowId test" << endl;
        passed = false;
    }
    testObject.setKepId(1);
    if (testObject.getKepId() != 1) {
        cout << "FAILED kepId test" << endl;
        passed = false;
    }
    testObject.setKepoiName("Fred");
    if (testObject.getKepoiName() != "Fred") {
        cout << "FAILED kepoiName test" << endl;
        passed = false;
    }
    testObject.setKeplerName("Ethel");
    if (testObject.getKeplerName() != "Ethel") {
        cout << "FAILED keplerName test" << endl;
        passed = false;
    }
    testObject.setKoiDisposition("Babaloo");
    if (testObject.getKoiDisposition() != "Babaloo") {
        cout << "FAILED koiDisposition test" << endl;
        passed = false;
    }
    testObject.setKoiScore(1.0);
    if (testObject.getKoiScore() != 1.0) {
        cout << "FAILED koiScore test" << endl;
        passed = false;
    }
    testObject.setRa(2.0);
    if (testObject.getRa() != 2.0) {
        cout << "FAILED ra test" << endl;
        passed = false;
    }
    testObject.setDec(3.0);
    if (testObject.getDec() != 3.0) {
        cout << "FAILED dec test" << endl;
        passed = false;
    }
    testObject.setKoiKepmag(4.0);
    if (testObject.getKoiKepmag() != 4.0) {
        cout << "FAILED koiKepmag test" << endl;
        passed = false;
    }
    // Test initialization (and getters)
    Kepler testObject2 = Kepler(5, 6, "Lucy",
                                "Ricky", "Copacabana",
                                1.1, 180.0, 45.0, 13.0);
    if (testObject2.getRowId() != 5 ||
        testObject2.getKepId() != 6 ||
        testObject2.getKepoiName() != "Lucy" ||
        testObject2.getKeplerName() != "Ricky" ||
        testObject2.getKoiDisposition() != "Copacabana" ||
        testObject2.getKoiScore() != 1.1 ||
        testObject2.getRa() != 180.0 ||
        testObject2.getDec() != 45.0 ||
        testObject2.getKoiKepmag() != 13.0) {
        cout << "FAILED non-default constructor test" << endl;
        passed = false;
    }
    return passed;
}

#endif // KEPLER_H
