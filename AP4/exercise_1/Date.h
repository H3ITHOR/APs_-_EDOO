#include <iostream>
#include <string>

using namespace std;

class Date{
    private:
    int month;
    int day;
    int year;

    public:

    void init(int month, int day, int year);
    void init(void);
    void print(void);
};