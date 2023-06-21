// Write a program to create a user-defined manipulator that will format the output by setting the width, precision, and fill character at the same time by passing arguments.

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

ostream& custom_format(ostream& os, int width, int precision, char fill_char) {
    os << setw(width) << setfill(fill_char) << setprecision(precision);
    return os;
}

class Format{   
private:
    int width;
    int precision;
    char fill_char;

public:
    Format(int width_, int precision_, char fill_char_) : width(width_), precision(precision_), fill_char(fill_char_) {}

    friend ostream& operator<<(ostream& os, const Format& format);
};


ostream& operator<<(ostream& os, const Format& format) {
    return custom_format(os, format.width, format.precision, format.fill_char);
}


int main(){
    double pi = 3.14159265358979323846;
    cout << Format(10, 3, '*') << pi << endl;
}