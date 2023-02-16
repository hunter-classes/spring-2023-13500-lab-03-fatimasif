// add your code

/*
Author: Fatima Asif
Course: CSCI-135
Instructor: M. Zamansky
Assignment: reservoir.h, lab-03
*/

#pragma once
#ifndef RESERVOIR_H
#define RESERVOIR_H

#include <string>

const int NUM_DAYS = 365;
    // task A
void read_data(double east_storage[], double east_elevation[], double west_storage[], double west_elevation[], std::string dates[]);
double get_east_storage(std::string date, double east_storage[], std::string dates[]);

    // task B
double get_min_east(double east_storage[]);
double get_max_east(double east_storage[]);

    // task C
std::string compare_basins(std::string date);



#endif







