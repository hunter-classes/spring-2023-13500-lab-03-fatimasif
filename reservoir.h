// add your code

#pragma once

/*
#ifndef RESERVOIR_H
#define RESERVOIR_H

#include <string>

double get_east_storage(std::string date);

#endif
*/

#ifndef RESERVOIR_H
#define RESERVOIR_H

#include <string>

const int NUM_DAYS = 365;

void read_data(double east_storage[], double east_elevation[], double west_storage[], double west_elevation[], std::string dates[]);

double get_east_storage(std::string date, double east_storage[], std::string dates[]);

#endif