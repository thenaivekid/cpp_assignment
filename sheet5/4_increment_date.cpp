// Write a class Date that overloads prefix and postfix operators to increase the Date object by one day, while causing appropriate increments to the month and year (use the appropriate condition for leap year). The prefix and postfix operators in the Date class should behave exactly like the built-in increment operators.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Date{
private:
    int year, month, day;

public:
    Date(int year_, int month_, int day_): year(year_), month(month_), day(day_){}

    void print(){
        cout << year << "/" << month << "/" << day << endl;
    }

    Date operator++() { // Prefix increment operator
        increment();
        cout << "prefix" << endl;
        return *this;
    }

    Date operator++(int) { // Postfix increment operator
        Date temp(year, month, day);
        increment();
        cout << "postfix" << endl;
        return temp;
    }

    void increment(){
        if (month == 12 && day == days_in_months()){
            year++;
            month = 1;
            day = 1;
        }
        else if (day == days_in_months()){
            month++;
            day = 1;
        }
        else {
            day++;
        }
    }

    int days_in_months()const {
        static const int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int num_of_days = days[month];
        if (month == 2 && is_leap_year()){
            num_of_days++;
        }
        return num_of_days;
    }

    bool is_leap_year() const {
        return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
    }
};
    

int main(){
    Date d(2000, 12, 31);
    d.print();
    Date d1 = d++;
    d1.print();
    Date d2 = ++d;
    d2.print();
}