// Write a class to store x, y, and z coordinates of a point in three-dimensional space. Overload addition and subtraction operators for addition and subtraction of two coordinate objects. Implement the operator functions as non-member functions (friend operator functions).

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Point{
private:
    int x, y, z;

public:
    Point(int x_, int y_, int z_): x(x_), y(y_), z(z_){}

    void print() const {
        cout << "(" << x << ", " << y << ", " << z << ")" << endl;
    }

    friend Point operator+(const Point& p1, const Point& p2);
    friend Point operator-(const Point& p1, const Point& p2);
    
    ~Point(){}
};

Point operator+(const Point& p1, const Point& p2){
    Point p(p1.x + p2.x, p1.y + p2.y, p1.z + p2.z);
    return p;
}

Point operator-(const Point& p1, const Point& p2){
    Point p(p1.x - p2.x, p1.y - p2.y, p1.z - p2.z);
    return p;
}

int main(){
    Point p1(1, 2, 3), p2(4, 5, 6);
    p1.print();
    p2.print();
    (p1 + p2).print();
    (p1 - p2).print();
}