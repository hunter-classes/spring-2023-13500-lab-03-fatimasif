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
#include <string>

    // both functions take in the array east_storage which contains the storage levels for the East basin and looks for the minimum and maximum

double get_min_east(double east_storage[]) {
    double minEastSt = std::numeric_limits<double>::max();  // initialize minEast variable to the maximum possible value
        // iterate through the east_storage using a for loop and checks the values against minEastSt
        // if an element is found with a lower value then minEastSt is updated to that value
    for (int i = 0; i < NUM_DAYS; i++) {
        if (east_storage[i] < minEastSt) {
            minEastSt = east_storage[i];
        }
    }
    return minEastSt;
}

double get_max_east(double east_storage[]) {   
    double maxEastSt = std::numeric_limits<double>::lowest();   // initializes maxEastSt to the lowest possible value 
        // iterates through east_storage by using a for loop and checking the value of each element against maxEastSt
        // if an element is found with a greater valye then maxEastSt is updated to that value
    for (int i = 0; i < NUM_DAYS; i++) {
        if (east_storage[i] > maxEastSt) {
            maxEastSt = east_storage[i];
        }
    }
    return maxEastSt;
}


/* TASK C
Add a function std::string compare_basins(std::string date) that will return East if the East basin was higher on the 
specified dateand West if the West was higher. It should return Equal if the values were the same.

As with the other tasks, this function should read in the file and there should be no keyboard input. 
Remember to test sufficiently from main
*/

    // the function takes in a string argument and date. It returns a string that indicates if the East or West basin has a higher storage level on a specified date
std::string compare_basins(std::string date) {
    double east_storage, west_storage;
    std::string curr_date;
    std::ifstream fin("Current_Reservoir_Levels.tsv");  // opens the file
    if (fin.fail()) {
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1); // exit if failed to open the file
    }
    std::string junk;
    std::getline(fin, junk); // read and ignore the header line
    
        // looping through the file and only reading the current date, east storage, and west storage columns
    while (fin >> curr_date >> east_storage >> junk >> west_storage >> junk) {
        if (curr_date == date) {    // if the current date matches the specified date 
            if (east_storage > west_storage) {  // the function will check if east storage is greater than west storage
                return "East";
            } else if (east_storage < west_storage) {   // otherwise it will check if the west is greater
                return "West";
            } else {
                return "Equal"; // returns if both valyes are equal
            }
        }
    }
    return "Date not found";    // if the date is not listed in the data then this will be returned
}
