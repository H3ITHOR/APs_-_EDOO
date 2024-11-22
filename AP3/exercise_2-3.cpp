#include <iostream>
#include <string>

using namespace std;

    class rec_factorial{
        public:

        long double calculate(unsigned int number){
            if (number == 0){
                return 1;
            };
            return number * calculate(number-1);
        }
    };

    class loop_factorial{
        private:

        unsigned int num;
        int value = 1;

        public:

        loop_factorial(unsigned int n){num = n;}

        ~loop_factorial(){"the factorial was destroyed!";}

        long double calculate(){
            for(int i = num; i > 0; i--){
                value = value * i;
            }
            return value;
        }

    };

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

    // rec_factorial factorial;
    // cout << factorial.calculate(5) << endl;

    loop_factorial factorial(5);
    cout << factorial.calculate() << endl;

    return 0;
}