// Assume that employee will have to pay 10 percent income tax to the government. Ask user to enter the employee salary. Use inline function to display the net payment to the employee by the company.
#include <iostream>
#include <string>
#include <vector>
using namespace std;

inline float tax(float salary){
    return salary*0.1;
}

int main(){
    int salary;
    cout<<"Enter salary: ";
    cin>>salary;
    cout<<"Net salary: "<<salary + tax(salary);
}