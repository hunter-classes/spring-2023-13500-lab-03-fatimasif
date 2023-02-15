// add your code

#pragma once

/*
#ifndef RESERVOIR_H
#define RESERVOIR_H

#include <string>

double get_east_storage(std::string date);

#endif
*/


// WORKING CODE
#ifndef RESERVOIR_H
#define RESERVOIR_H

#include <string>

const int NUM_DAYS = 365;

void read_data(double east_storage[], double east_elevation[], double west_storage[], double west_elevation[], std::string dates[]);

double get_east_storage(std::string date, double east_storage[], std::string dates[]);


#endif


//WORKING CODE FOR PART B
#include <iostream>
#include <string>

const int NUM_MONTHS = 12;

struct Reading {
    int day;
    double eastSt;
    double eastEl;
    double westSt;
    double westEl;
};

void read_data(Reading* readings, int count);
double get_east_storage(std::string date, Reading* readings, int count);
double get_min_east(Reading* readings, int count);
double get_max_east(Reading* readings, int count);


/*
#ifndef RESERVOIR_H
#define RESERVOIR_H

#include <string>

const int ARRAY_SIZE = 365;

double get_east_storage(std::string date);
double get_min_east();
double get_max_east();

#endif
*/


