// add your code

/*
Author: Fatima Asif
Course: CSCI-135
Instructor: M. Zamansky
Assignment: reservoir.cpp, lab-03
*/

/* TASK A
Write a program east-storage.cpp that asks the user to input a string representing the date (in MM/DD/YYYY format), 
and prints out the East basin storage on that day.
*/

#include <iostream>
#include "reservoir.h"
#include <fstream>
#include <cstdlib>
#include <climits>

    // creating a function to read the data from the Current_Reservoir_Levels.tsv file
    // the function takes in five arrays as parameters
void read_data(double east_storage[], double east_elevation[], double west_storage[], double west_elevation[], std::string dates[]) {
    std::ifstream fin("Current_Reservoir_Levels.tsv");  // opening the file for reading
    if (fin.fail()) {   // if file cannot be opened then an error message will be outputted to the cerr
        std::cerr << "File cannot be opened for reading." << std::endl; // cerr is the standard error stream
        exit(1); // exit if failed to open the file
    }
    
    std::string junk;
    std::getline(fin, junk); // read and ignore the header line
    
    int i = 0;
        // using a while loop to read data from the file line by line
        // it will continue when lines still need to be read and the arrays have not been filled up to the maximum number of days (NUM_DAYS)
        // each line is read because of the input operator >> to extract values for the date and then stored into corressponding arrays
    while (i < NUM_DAYS && fin >> dates[i] >> east_storage[i] >> east_elevation[i] >> west_storage[i] >> west_elevation[i]) {
        fin.ignore(INT_MAX, '\n'); //skip to the end of line, ignoring the remaining columns
        i++;    // loop counter is incremented at the end of each iteration
    }
    
    fin.close();    // once the loop has finished reading the data and filling the arrays, then the input file stream is closed
}

    // the get_east_storage function should accept a std::string specifying a date and should return the East Basin storage for that day.
    // the function will take in two arrays "east_storage" and "dates"
double get_east_storage(std::string date, double east_storage[], std::string dates[]) {
        // the for loop iterates through each element of the "dates" array
        // if the element of the "dates" array matches the given date, then the function will return the corresponding element of the east_storage array
    for (int i = 0; i < NUM_DAYS; i++) {
        if (dates[i] == date) {     // checking to see if the given dat matches the element in the dates array
            return east_storage[i]; // if a match is found then the function will return the corressponding element
        }
    }
    return -1; // returns -1 if date is not found


}

/* TASK B
Add the following two functions to reservoir.cpp/h
double get_min_east() - this function should return the minimum storage in the East basin in the 2018.
double get_max_east() - this function should return the maximum storage in the East basin in the 2018.
Test these by calling them from main and printing out results. As with task A, there should be no keyboard input.
*/

#include <limits> // for numeric_limits
#include <fstream>
#include <string>

// const int NUM_DAYS = 365;

double get_min_east(double east_storage[]) {
    double minEastSt = std::numeric_limits<double>::max();
    for (int i = 0; i < NUM_DAYS; i++) {
        if (east_storage[i] < minEastSt) {
            minEastSt = east_storage[i];
        }
    }
    return minEastSt;
}

// double get_min_east(double east_storage[], std::string dates[]) {
//     double minEastSt = std::numeric_limits<double>::max();
//     for (int i = 0; i < NUM_DAYS; i++) {
//         if (dates[i].substr(0, 4) == "2018" && east_storage[i] < minEastSt) {
//             minEastSt = east_storage[i];
//         }
//     }
//     return minEastSt;
// }

double get_max_east(double east_storage[]) {
    double maxEastSt = std::numeric_limits<double>::lowest();
    for (int i = 0; i < NUM_DAYS; i++) {
        if (east_storage[i] > maxEastSt) {
            maxEastSt = east_storage[i];
        }
    }
    return maxEastSt;
}


/* TASK B
Add the following two functions to reservoir.cpp/h
double get_min_east() - this function should return the minimum storage in the East basin in the 2018.
double get_max_east() - this function should return the maximum storage in the East basin in the 2018.
Test these by calling them from main and printing out results. As with task A, there should be no keyboard input.
*/

// #include "reservoir.h"
// #include <fstream>
// #include <sstream>
// #include <string>

// #include <limits>


// void read_data(Reading* readings, int count) {
//     std::ifstream data("Current_Reservoir_Levels.tsv");
//     if (data.fail()) {
//         std::cerr << "Unable to open file\n";
//         exit(1);
//     }

//     std::string header;
//     getline(data, header);

//     std::string line;
//     for (int i = 0; i < count; i++) {
//         getline(data, line);
//         std::stringstream lineStream(line);

//         std::string date;
//         getline(lineStream, date, '\t');

//         lineStream >> readings[i].eastSt >> readings[i].eastEl
//                    >> readings[i].westSt >> readings[i].westEl;

//         std::string temp;
//         getline(lineStream, temp);

//         readings[i].day = i + 1;
//     }

//     data.close();
// }

// double get_east_storage(std::string date, Reading* readings, int count) {
//     double eastSt = -1;
//     for (int i = 0; i < count; i++) {
//         if (date == "01/" + std::to_string(readings[i].day) + "/2018") {
//             eastSt = readings[i].eastSt;
//             break;
//         }
//     }
//     return eastSt;
// }


// double get_min_east(Reading* readings, int count) {
//     double minEastSt = std::numeric_limits<double>::max();
//     for (int i = 0; i < count; i++) {
//         if (readings[i].eastSt < minEastSt) {
//             minEastSt = readings[i].eastSt;
//         }
//     }
//     return minEastSt;
// }


// double get_max_east(Reading* readings, int count) {
//     double maxEastSt = readings[0].eastSt;
//     for (int i = 0; i < count; i++) {
//         if (readings[i].eastSt > maxEastSt) {
//             maxEastSt = readings[i].eastSt;
//         }
//     }
//     return maxEastSt;
// }



