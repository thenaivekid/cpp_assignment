// Write a program that displays the current monthly salary of chief executive officer, information officer, and system analyst, programmer that has been increased by 9, 10, 12, and 12 percentages respectively in year 2010. Let us assume that the salaries in year 2009 are

// Chief executive officer Rs. 35000/m

// Information officer Rs. 25000/m

// System analyst Rs. 24000/m

// Programmer Rs. 18000/m

// Make a function that takes two arguments; one salary and the other increment. Use proper default argument.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

float salary_increment(float salary, float increment = 0.0){
    return salary + salary * increment / 100;
}

int main(){
    int chief_executive_officer = 35000;
    int information_officer = 25000;
    int system_analyst = 24000;
    int programmer = 18000;
    cout << "Salary in year 2010: " << endl;
    cout << "Chief executive officer: " << salary_increment(chief_executive_officer, 9) << endl;
    cout << "Information officer: " << salary_increment(information_officer, 10) << endl;
    cout << "System analyst: " << salary_increment(system_analyst, 12) << endl;
    cout << "Programmer: " << salary_increment(programmer, 12) << endl;
}