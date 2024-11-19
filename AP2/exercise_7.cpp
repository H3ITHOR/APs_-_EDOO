#include <iostream>
#include <iomanip>
using namespace std;

#define ABS(number) (number < 0) ? number : -number
#define MAX(x, y) ((x) > (y)? (x) : (y))
#define MIN(x, y) ((x) < (y)? (x) : (y))

int main(){
    int num = -1;

    int x = 10;
    int y = 1000;
    
    cout << ABS(num);
    cout << "\n";
    cout << MAX(y, x);
    cout << "\n";
    cout << MIN(x, y);
    return 0;
}