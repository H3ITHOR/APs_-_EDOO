#include <iostream>
#include <string>

using namespace std;

class Palyndrome{
    private:

        string word;
        int head = 0;
        int tail;

    public:

        Palyndrome(string chosen_word){
            word = chosen_word;
            tail = word.length() - 1;
        };

        ~Palyndrome(){cout << "Objeto Palyndrome destruído!";}

        bool verify(){
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
    string word;
    cin >> word;
    Palyndrome test(word);

    if(test.verify() == 1){
        cout <<"Esta palavra e um palindromo!";
    } else {
        cout << "Esta palavra nao e um palindromo!";
    }

    return 0;
}