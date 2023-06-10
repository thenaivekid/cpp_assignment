// Write a program using the function overloading that converts feet to inches. Use function with no argument, one argument and two arguments. Decide yourself the types of arguments. Use pass by reference in any one of the function above.
#include <iostream>
#include <string>
#include <vector>
using namespace std;

float feet_to_inches(){
    int feet;
    std::cout << "Enter the number of feet: ";
    std::cin >> feet;

    int inches = feet * 12;
    return inches;
}

float feet_to_inches(int feet){
    return feet * 12; 
}

float feet_to_inches(int &feet, int &inches){ 
    return feet * 12 + inches;
}

int main(){
    cout << "Function with no argument" << feet_to_inches() << endl;
    cout << "Function with one argument" << endl;
    cout << feet_to_inches(2) << endl;
    int feet = 2;
    int inch = 2;
    cout << "function with two arguments passed by reference" << feet_to_inches(feet, inch) << endl;
}