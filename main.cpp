// // add your code as appropriate 
// #include <iostream>
// #include <fstream>
// #include <cstdlib>
// #include <climits>
// #include "reservoir.cpp"

// int main()
// {
//   // test trial part A
//   std::string date = "05/20/2018";
//   double eastSt = get_east_storage(date);
//   if (eastSt == -1){
//     std::cout << "No data available." << std::endl;
//   } else{
//     std::cout << "East basin storage on " << date << ": " << eastSt << "billion gallons." << std::endl;
//   }

  
//   return 0;
// }

// #include <fstream>
// #include <cstdlib>
// #include <climits>


/*
#include <iostream>
// #include "reservoir.cpp"
#include "reservoir.h"
#include <string>

int main() {
    std::string date = "07/07/2018";
    double eastSt = get_east_storage(date);
    if (eastSt == -1) {
        std::cout << "No data available for the specified date." << std::endl;
    } else {
        std::cout << "East basin storage on " << date << ": " << eastSt << " billion gallons." << std::endl;
    }
    return 0;
}
*/

// // WORKING CODE FOR PART A

// #include "reservoir.h"
// #include <iostream>

// int main() {
//     double east_storage[NUM_DAYS];
//     double east_elevation[NUM_DAYS];
//     double west_storage[NUM_DAYS];
//     double west_elevation[NUM_DAYS];
//     std::string dates[NUM_DAYS];

//     read_data(east_storage, east_elevation, west_storage, west_elevation, dates);
    
//     std::string date = "07/07/2018";
//     double east_storage_on_date = get_east_storage(date, east_storage, dates);
    
//     if (east_storage_on_date == -1) {
//         std::cout << "Data for " << date << " is not available." << std::endl;
//     } else {
//         std::cout << "East basin storage on " << date << ": " << east_storage_on_date << " billion gallons" << std::endl;
//     }

//     return 0;
// }



// // //WORKING CODE FOR PART B
// // #include <iostream>
// // #include "reservoir.h"

// const int NUM_READINGS = 365;

// int main() {
//     Reading readings[NUM_READINGS];
//     read_data(readings, NUM_READINGS);

//     // std::cout << "Minimum East Basin storage in 2018: " << get_min_east(readings, NUM_READINGS) << " billion gallons\n";
//     std::cout << "Maximum East Basin storage in 2018: " << get_max_east(readings, NUM_READINGS) << " billion gallons\n";

//     return 0;
// }



// WORKING CODE FOR PART A

#include "reservoir.h"
#include <iostream>

const int NUM_READINGS = 365;

int main() {
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

    Reading readings[NUM_READINGS];
    read_data(readings, NUM_READINGS);

    // double min_east = get_min_east(readings, count);
    // double max_east = get_max_east(readings, count);

    std::cout << "Minimum East Basin storage in 2018: " << get_min_east(readings, NUM_READINGS) << " billion gallons\n";
    std::cout << "Maximum East Basin storage in 2018: " << get_max_east(readings, NUM_READINGS) << " billion gallons\n";


    


    return 0;

}



















/*
#include <iostream>
#include "reservoir.h"

int main() {
    // Get the storage for a specific date
    double storage = get_east_storage("07/07/2018");
    if (storage != -1) {
        std::cout << "East basin storage on 07/07/2018: " << storage << " billion gallons" << std::endl;
    } else {
        std::cout << "Date not found" << std::endl;
    }



    // TRIAL 1
    // // Get the minimum and maximum storage for the year 2018
    // double minStorage = get_min_east();
    // std::cout << "Minimum East basin storage in 2018: " << minStorage << " billion gallons" << std::endl;

    // double maxStorage = get_max_east();
    // std::cout << "Maximum East basin storage in 2018: " << maxStorage << " billion gallons" << std::endl;



// TRIAL 2
// deleted accidentally


    double min_east = get_min_east();
    double max_east = get_max_east();

    std::cout << "Minimum storage in East Basin in 2018: " << min_east << std::endl;
    std::cout << "Maximum storage in East Basin in 2018: " << max_east << std::endl;


    return 0;
}

*/















