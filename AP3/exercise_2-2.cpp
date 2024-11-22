#include <iostream>
#include <string>

using namespace std;

class Palyndrome{
    public:

    string word;

    bool verify(string word){
        int head = 0;
        int tail = word.length() - 1;
        while(head <= tail){
            if(word[head] != word[tail]){
                return false;
            }
            head++;
            tail--;
        }
        return true;
    }
};

int main(){

    Palyndrome test;
    cin >> test.word;

    if(test.verify(test.word) == 1){
        cout <<"Esta palavra e um palindromo!";
    } else {
        cout << "Esta palavra nao e um palindromo!";
    }

    return 0;
}