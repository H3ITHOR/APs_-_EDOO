#include <iostream>
#include <string>

using namespace std;

int main(){

    string s1 = "As time by ...";
    string s2 = "goes"; 

    // first exercise

    s1.insert(s1.length() - 4, " " + s2);
    cout << s1 << endl;

    // second exercise
    s1.erase(s1.length() - 4);
    cout << s1 << endl;


    // third exercise
    string bill = "Bill";

        for(int i = 0; i < 4 ; i++){s1[3 + i] = bill[i];}
        cout << s1 << endl;

    return 0;
}