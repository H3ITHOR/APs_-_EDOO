#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int i = -2;
    float x = -4 * i++ - 6 % 4;
    cout << i << endl;
    cout << x << endl;

    cout << -6 % 4 << endl;

    return 0;
}


// 