/*
Author: Fatima Asif
Course: CSCI-135
Instructor: M. Zamansky
Assignment: reverseorder.cpp, lab-03
*/

/*
TASK D
For this task, add new files, reverseorder.cpp and reverseorder.h. You will have to modify the Makefile appropriately.

In these files create a function void reverse_oreder(std::string
date1, std::string date2). This function should print out the West basin elevation 
for all days in the interval in reverse chronological order.

The program should report the West basin elevation for all days in the interval 
in the reverse chronological order (from the later date to the earlier).
*/


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <iomanip>
#include <sstream>
#include "reverseorder.h"

    // this function will print out the West elevation data in reverse order from the specified date range
    // function takes in two parameters, date1 and date2 which specifiy the date range that needs to be printed in reverse order
void reverse_order(std::string date1, std::string date2){
        // copying the skeleton code
    std::ifstream fin("Current_Reservoir_Levels.tsv");      // opens the file
    if(fin.fail()){
        std::cerr << "File cannot be opened for reading. \n";
        exit(1);        // exit if failed to open the file
    }

    std::string junk;
    getline(fin, junk);

    int counter = 0;    // creating a counter variable that is initialized to 0, and it will keep track of the number of data points in the range
        // two strings to store the date and the west elevation values for the specified range
    std::string west_date;
    std::string west_el[365];   // 365 is the highest the range could be    
    double EastSt, WestSt, EastEl, WestEl; 
    double westElevation[365];

        // the while loop reads each line
        // values are read into the variables respectively
    while(fin >> west_date >> EastSt >> EastEl >> WestSt >> WestEl){
        fin.ignore(INT_MAX, '\n');  // skips to the end of the line
        if(west_date >= date1 && west_date <= date2){       // if the west_date is specified in the range then the counter is incremented 
            counter++;
                // the values are then stored into the corressponding arrays
            west_el[counter] = west_date; 
            westElevation[counter] = WestEl;
        }
    }
        // after the lines are read, the west elevation values for the specified date range are printed out in reverse order
        // loops through west_el which holds the date and westElevation with the elevation from the last index to the first index
    for(int i = counter; i > 0; i--){
        std::cout << west_el[i] << " " << westElevation[i] << std::endl; 

    }

    fin.close();
}
