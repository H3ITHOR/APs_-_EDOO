#include <iostream>
#include <array>

using namespace std;

int main(){
    //creating the static array
    int array[1000];

    //filling the array with values
    for(int i = 0; i < 1000; i++){
        array[i] = i;
    }

    //deleting the non-prime numbers
    for(int i = 2; i < 1000; i++){
        if(array[i] != 0){
            for(int j = i * 2; j < 1000; j += i){
                array[j] = 0; //setting the multiples of the prime number to 0
            }
        }
    }

    //printing the prime numbers:
    for(int i = 2; i < 1000; i++){
        if(array[i] != 0){
            cout << array[i] << " ";
        }
    }

    return 0;
}