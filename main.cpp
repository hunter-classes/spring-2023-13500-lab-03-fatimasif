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
    
    std::string date = "07/07/2018";
    double east_storage_on_date = get_east_storage(date, east_storage, dates);
    
    if (east_storage_on_date == -1) {
        std::cout << "Data for " << date << " is not available." << std::endl;
    } else {
        std::cout << "East basin storage on " << date << ": " << east_storage_on_date << " billion gallons" << std::endl;
    }

        // task b

    double minEastSt = get_min_east(east_storage);
    double maxEastSt = get_max_east(east_storage);
    std::cout << "Minimum storage in the East basin in 2018: " << minEastSt << std::endl;
    std::cout << "Maximum storage in the East basin in 2018: " << maxEastSt << std::endl;



    // double minEast = get_min_east(east_storage, dates);

    // std::cout << "Minimum storage in East basin: " << minEast << std::endl;

  
    // double minEast = get_min_east(east_storage, NUM_DAYS);
    
    // std::cout << "The minimum storage in the East basin is: " << minEast << std::endl;
    



    // Reading readings[NUM_READINGS];
    // read_data(readings, NUM_READINGS);

    // // double min_east = get_min_east(readings, count);
    // // double max_east = get_max_east(readings, count);

    // std::cout << "Minimum East Basin storage in 2018: " << get_min_east(readings, NUM_READINGS) << " billion gallons\n";
    // std::cout << "Maximum East Basin storage in 2018: " << get_max_east(readings, NUM_READINGS) << " billion gallons\n";


    return 0;

}
