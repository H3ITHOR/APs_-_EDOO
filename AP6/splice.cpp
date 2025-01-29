#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Array{
    int size;
    int* arr;

    public: 
    Array(int size = 0) : size(size), arr(new int[size]){}

    ~Array(){
        delete[] arr;
    }

    Array(const Array& other) : size(other.size), arr(new int[other.size]){
        for (int i = 0; i < size; i ++){
            arr[i] = other.arr[i];
        }
    }

    int getSize(){
        return size;
    }

    void setValues(){
        cout << "Enter the values of the array: \n";
        for(int i = 0; i < size; i++){
            cin >> arr[i];
        }
    }

    void splice(const Array& arr1, const Array& arr2, int pos){

        if(pos < 0) pos = 0;
        else if(pos > arr1.size){pos = arr1.size;}

        delete[] arr;

        size = arr1.size + arr2.size;
        arr = new int[size];

        for (int i = 0; i < pos; i++){
            arr[i] = arr1.arr[i];
        }

        for (int i = 0; i < arr2.size; i++){
            arr[pos + i] = arr2.arr[i];
        }

        for(int i = 0; i < arr1.size - pos; i++){
            arr[pos + arr2.size + i] = arr1.arr[pos + i];
        }
    }

    void print() const{
        for (int i = 0; i < size; i ++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    
    Array arr1(5);
    Array arr2(4);
    Array result;

    arr1.setValues();
    arr2.setValues();

    result.splice(arr1, arr2, 2);
    result.print();
    return 0;
}