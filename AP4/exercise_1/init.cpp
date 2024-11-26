#include <iostream>
#include <string>
#include "Date.h"

using namespace std;

void Date::init(int month, int day, int year){
    this->month = month;
    this->day = day;
    this->year = year;
};