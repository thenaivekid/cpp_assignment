// Write a program to set a structure to hold a date (mm,dd and yy), assign values to the members of the structure and print out the values in the format 11/28/2004 by function. Pass the structure to the function

#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct{
    int year, month, day;
}date;

void show_date(date d){
    cout << d.day << "/" << d.month << "/" << d.year << endl;
}

int main(){
    date d = {2020, 12, 31};
    show_date(d);
}