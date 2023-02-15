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


#include "reservoir.h"
#include <iostream>

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
    
    return 0;
}







