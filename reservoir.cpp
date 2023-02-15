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


// WORKING CODE

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



// WORKING CODE FOR PART B
#include "reservoir.h"
#include <fstream>
#include <sstream>
#include <string>

void read_data(Reading* readings, int count) {
    std::ifstream data("Current_Reservoir_Levels.tsv");
    if (data.fail()) {
        std::cerr << "Unable to open file\n";
        exit(1);
    }

    std::string header;
    getline(data, header);

    std::string line;
    for (int i = 0; i < count; i++) {
        getline(data, line);
        std::stringstream lineStream(line);

        std::string date;
        getline(lineStream, date, '\t');

        lineStream >> readings[i].eastSt >> readings[i].eastEl
                   >> readings[i].westSt >> readings[i].westEl;

        std::string temp;
        getline(lineStream, temp);

        readings[i].day = i + 1;
    }

    data.close();
}

double get_east_storage(std::string date, Reading* readings, int count) {
    double eastSt = -1;
    for (int i = 0; i < count; i++) {
        if (date == "01/" + std::to_string(readings[i].day) + "/2018") {
            eastSt = readings[i].eastSt;
            break;
        }
    }
    return eastSt;
}

// double get_min_east(Reading* readings, int count) {
//     double minEastSt = readings[0].eastSt;
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

double get_min_east(Reading* readings, int count) {
    double minEastSt = readings[0].eastSt;
    for (int i = 0; i < count; i++) {
        if (readings[i].eastSt < minEastSt) {
            minEastSt = readings[i].eastSt;
        }
    }
    return minEastSt;
}

double get_max_east(Reading* readings, int count) {
    double maxEastSt = readings[0].eastSt;
    for (int i = 0; i < count; i++) {
        if (readings[i].eastSt > maxEastSt) {
            maxEastSt = readings[i].eastSt;
        }
    }
    return maxEastSt;
}







/*
#include <iostream>
#include <fstream>
#include <string>
#include "reservoir.h"

// const int ARRAY_SIZE = 365;
// double eastStorages[ARRAY_SIZE];

    // creating the get_east_storage function to filter through
double get_east_storage(std::string date) {
    double eastStorages[ARRAY_SIZE];
    std::ifstream inFile("Current_Reservoir_Levels.tsv");
    if (inFile.fail()) {
        std::cerr << "Error opening file" << std::endl;
        exit(1);
    }

    std::string junk;
    getline(inFile, junk);

    std::string day;
    double eastSt, eastEl, westSt, westEl;
    int i = 0;
    while (inFile >> day >> eastSt >> eastEl >> westSt >> westEl) {
        inFile.ignore(500, '\n');
        if (day == date) {
            eastStorages[i] = eastSt;
            inFile.close();
            return eastSt;
        }
        i++;
    }

    inFile.close();
    return -1;
}


double get_min_east() {

    double eastStorages[ARRAY_SIZE];

    std::ifstream inFile("Current_Reservoir_Levels.tsv");
    if (inFile.fail()) {
        std::cerr << "Error opening file" << std::endl;
        exit(1);
    }

    std::string junk;
    getline(inFile, junk);


    double min_storage = eastStorages[0];
    for (int i = 0; i < ARRAY_SIZE; i++) {     
        if (eastStorages[i] < min_storage) {
            min_storage = eastStorages[i];
        }
    }
    return min_storage;
}

double get_max_east() {
    double eastStorages[ARRAY_SIZE];

    std::ifstream inFile("Current_Reservoir_Levels.tsv");
    if (inFile.fail()) {
        std::cerr << "Error opening file" << std::endl;
        exit(1);
    }

    std::string junk;
    getline(inFile, junk);

    double max_storage = eastStorages[0];
    for (int i = 0; i < ARRAY_SIZE; i++) {    
        if (eastStorages[i] > max_storage) {
            max_storage = eastStorages[i];
        }
    }
    return max_storage;
}
*/

// CODE WORKS FOR PART A BUT NOT PART B