#include <iostream>
#include <string>

using namespace std;

    // version 1 - recursively
    long double factorial(unsigned int num){
        if(num==0){return 1;}
        return num * factorial(num-1);
    }

    // version 2 - loop
    long double factorial_loop(unsigned int num){
        unsigned int result = 1;
        for(unsigned int i = num; i > 0; i--){
            result = result * i;
        }
        return result;
    }
int main(){

    cout << factorial_loop(4) << endl;
    return 0;
}