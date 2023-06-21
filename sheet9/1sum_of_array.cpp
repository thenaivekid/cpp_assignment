// Create a function called sum() that returns the sum of the elements of an array. Make this function into a template so it will work with any numerical type. Write a program that applies this function to data of various types.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
T sum_(const vector<T> &v){
    T sum = 0;
    for (auto i: v){
        sum += i;
    }
    return sum;
}

int main(){
    vector <int> v1 = {1, 2, 3, 4, 5};
    vector <double> v2 = {1.1, 2.2, 3.3, 4.4, 5.5};
    vector <long> v3 = {1, 2, 3, 4, 5};
    vector <string> v4 = {"1", "2", "3", "4", "5"};
    vector <char> v5 = {'1', '2', '3', '4', '5'};
    cout << sum_(v1) << endl;
    cout << sum_(v2) << endl;
    cout << sum_(v3) << endl;
    // cout << sum_(v4) << endl;
    // cout << sum_(v5) << endl;
    return 0;
}