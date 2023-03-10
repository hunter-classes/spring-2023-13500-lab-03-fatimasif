/*
Author: Fatima Asif
Course: CSCI-135
Instructor: M. Zamansky
Assignment: main.cpp, lab-03
*/

#include "reservoir.h"
#include <iostream>
#include "reverseorder.h"
#include <iostream>
#include "reverseorder.h"


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

        // task C
    std::string higher_basin = compare_basins(date);
    std::string compare_basins(std::string date);
    if (higher_basin == "East") {
        std::cout << "On " << date << ", the East basin was higher." << std::endl;
    } else if (higher_basin == "West") {
        std::cout << "On " << date << ", the West basin was higher." << std::endl;
    } else {
        std::cout << "On " << date << ", the storage levels were equal in both basins." << std::endl;
    }


        // task D
    std::cout << "The reverse order for the specified dates and their elevation in ft is: \n";
    reverse_order("07/01/2018", "07/07/2018");  

}
