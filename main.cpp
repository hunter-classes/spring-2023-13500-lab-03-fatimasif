/*
Author: Fatima Asif
Course: CSCI-135
Instructor: M. Zamansky
Assignment: main.cpp, lab-03
*/

#include "reservoir.h"
#include <iostream>

const int NUM_READINGS = 365;

int main() {
        // task A
    double east_storage[NUM_DAYS];
    double east_elevation[NUM_DAYS];
    double west_storage[NUM_DAYS];
    double west_elevation[NUM_DAYS];
    std::string dates[NUM_DAYS];

    read_data(east_storage, east_elevation, west_storage, west_elevation, dates);
        // hard coding the date for the get_east_storage function to check
    std::string date = "07/07/2018";
    double east_storage_on_date = get_east_storage(date, east_storage, dates);
        // if statement to check if data for the date is available
    if (east_storage_on_date == -1) {
        std::cout << "Data for " << date << " is not available." << std::endl;
    } else {
        std::cout << "East basin storage on " << date << ": " << east_storage_on_date << " billion gallons" << std::endl;
    }


        // task B
    double minEastSt = get_min_east(east_storage);
    double maxEastSt = get_max_east(east_storage);
    std::cout << "Minimum storage in the East basin in 2018: " << minEastSt << std::endl;
    std::cout << "Maximum storage in the East basin in 2018: " << maxEastSt << std::endl;

    return 0;

}
