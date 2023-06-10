// Write a class for instantiating the objects that represent the two-dimensional Cartesian coordinate system.

// A. Make a particular member function of one class as a friend function of another class for addition.

// B. Make the other three functions to work as a bridge between the classes for multiplication, division, and subtraction.

// C. Also write a small program to demonstrate that all the member functions of one class are the friend functions of another class if the former class is made friend to the latter.

// Make least possible classes to demonstrate all the above in a single program without conflict.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Coordinate_{
    float x, y;

public:
    Coordinate_(float x_, float y_)
    : x(x_), y(y_){}

    void print(){
        cout << "(" << x << ", " << y << ")" << endl;
    }

    friend class Coordinate;
};


class Coordinate{
    float x, y;

public:
    Coordinate(float x_, float y_)
    : x(x_), y(y_){}

    float get_x(){
        return x;
    }

    float get_y(){
        return y;
    }

    void print(){
        cout << "(" << x << ", " << y << ")" << endl;
    }

    Coordinate add(Coordinate_ c){
        return Coordinate(x + c.x, y + c.y);
    }

    Coordinate subtract(Coordinate_ c){
        return Coordinate(x - c.x, y - c.y);
    }

    Coordinate multiplication(Coordinate_ c){
        return Coordinate(x * c.x, y * c.y);
    }

    Coordinate divide(Coordinate_ c){
        return Coordinate(x / c.x, y / c.y);
    }
};

int main(){
    Coordinate c1(1, 2);
    Coordinate_ c2(3, 4);
    c1.print();
    c2.print();
    c1.add(c2).print(); 
    c1.subtract(c2).print();
    c1.multiplication(c2).print();
    c1.divide(c2).print();
    return 0;   
}