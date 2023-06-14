// Write a program that can convert the Distance (meter, centimeter) to meters measurement in float and vice versa. Make a class distance with two data members, meter and centimeter. You can add function members as per your requirement.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Distance{
private:
    int meter, centimeter;

public:
    Distance(int meter_, int centimeter_)
    : meter(meter_), centimeter(centimeter_){}

    void print() const {
        cout << meter << "meter " << centimeter << "centimeter " << endl;
    }

    operator float() const {
        return (meter + centimeter/100.0);
    }

    Distance (float meter_)
    : meter(int(meter_)), centimeter(float(meter_ - int(meter_))*100){}

    ~Distance(){}
};

int main(){
    Distance d(1, 2);
    d.print();
    cout << float(d) << endl;
    Distance d2(2.5);
    d2.print();
}