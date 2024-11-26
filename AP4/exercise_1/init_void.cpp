#include <iostream>
#include "Date.h"
#include <ctime>

using namespace std;

void Date::init(void){
    time_t time(time_t *ptrSec);
    struct tm *localtime(const time_t *ptrSec);

}