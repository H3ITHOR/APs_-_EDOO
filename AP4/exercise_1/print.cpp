#include <iostream>
#include "Date.h"

using namespace std;

void Date::print(void){
    cout << this->month << "/" << this->day << "/" << this->year << endl;
}