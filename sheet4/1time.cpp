// Write a program that has a class to represent time. The class should have constructors to initialize data members hour, minute, and second to 0 and to initialize them to values passed as arguments. The class should have a member function to add time objects and return the result as a time object. There should be functions to display time in 12-hour and 24-hour format.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Time{
private:
    int hour, minute, second;

public:
    Time(int hr = 0, int min = 0, int sec = 0)
    : hour(hr), minute(min), second(sec){}

    static Time add_time(Time t1, Time t2){
        t1.hour += t2.hour;
        t1.minute += t2.minute;
        t1.second += t2.second;
        return t1;
    }
    
    void display_12_hr() const {
        if (hour > 12){
            cout << (hour - 12) << ":" << minute << ":" << second << " PM";
        }
        else{
            cout << hour << ":" << minute << ":" << second << " AM";
        }
    }

    void display_24_hr() const {
        cout << hour << ":" << minute << ":" << second;
    }
};


int main(){
    Time t1(12, 30, 30);
    Time t2(12, 30, 30);
    Time t3 = Time::add_time(t1, t2);
    t1.display_12_hr();
    cout << endl;
    t1.display_24_hr();
    cout << endl;
    t2.display_12_hr();
    cout << endl;
    t3.display_12_hr();
    return 0;
}