#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;

/*
Write a C++ program to perform the following:

A - Left-justify the number 0.123456 in an output field with a width of 15.
B - Output the number 23.987 as a fixed point number rounded to two decimal places, right-justifying the output in a field with a width of 12.
C - Output the number –123.456 as an exponential and with four decimal spaces. How useful is a field width of 10?
*/

int main(){

// A -----
    float number_1;
    cin >> number_1;
    cout << setw(15) << fixed << left << setprecision(6) << number_1 << endl;

// B -----
    float number_2 {23.987};
    cout << setw(12) << fixed << right << setprecision(2) << number_2 << endl;


// C -----
    float number_3 {-123.456};
    cout << setw(10) << fixed << setprecision(4) << scientific << number_3 << endl;

// Answering the alternative C question: a 10-size field may be too small to work with big numbers, so it is unpractical.
    return 0;
}