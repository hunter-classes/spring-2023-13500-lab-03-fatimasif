// // add your code

// #include <iostream>
// #include <fstream>
// #include <cstdlib>
// #include <climits>


// double get_east_storage(std::string date){
   
//     std::ifstream fin("Current_Reservoir_Levels.tsv");
//     if (fin.fail()) {
//         std::cerr << "File cannot be opened for reading." << std::endl;
//         exit(1); // exit if failed to open the file
// }

//     std::string junk, currentDate;        // new string variables
//     getline(fin, junk); // read one line from the file 

//     double eastSt;

// while(fin >> currentDate >> eastSt) { 
//     // this loop reads the file line-by-line
//     // extracting 5 values on each iteration 
    
//     fin.ignore(INT_MAX, '\n'); //skips to the end of line, 
//                           //ignorring the remaining columns 
//     if (currentDate == date) {
//         fin.close();
//         return eastSt;
//     }

//     // for example, to print the date and East basin storage:
//     // cout << date << " " << eastSt << endl;
// }

// fin.close();

// // Write a program east-storage.cpp that asks the user to input a string representing the date (in MM/DD/YYYY format), 
// // and prints out the East basin storage on that day.

// // std::vector 

// return -1; 
// }


/*
#include <iostream>
#include <cstdlib>
#include <climits>

#include <fstream>
#include <string>

#include "reservoir.h"

double get_east_storage(std::string date) {
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1);
    }

    std::string junk, currDate;
    double eastSt, eastEl, westSt, westEl;

    std::getline(fin, junk);

    while (fin >> currDate >> eastSt >> eastEl >> westSt >> westEl) {
        fin.ignore(INT_MAX, '\n');
        if (currDate == date) {
            fin.close();
            return eastSt;
        }
    }

    fin.close();
    return -1;
}
*/

#include <iostream>
#include "reservoir.h"
#include <fstream>
#include <cstdlib>
#include <climits>

void read_data(double east_storage[], double east_elevation[], double west_storage[], double west_elevation[], std::string dates[]) {
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1); // exit if failed to open the file
    }
    
    std::string junk;
    std::getline(fin, junk); // read and ignore the header line
    
    int i = 0;
    while (i < NUM_DAYS && fin >> dates[i] >> east_storage[i] >> east_elevation[i] >> west_storage[i] >> west_elevation[i]) {
        fin.ignore(INT_MAX, '\n'); //skip to the end of line, ignoring the remaining columns
        i++;
    }
    
    fin.close();
}

double get_east_storage(std::string date, double east_storage[], std::string dates[]) {
    for (int i = 0; i < NUM_DAYS; i++) {
        if (dates[i] == date) {
            return east_storage[i];
        }
    }
    return -1; // return -1 if date is not found
}
