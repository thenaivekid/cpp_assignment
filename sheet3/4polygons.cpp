// Write a program with classes to represent a circle, rectangle, and triangle. Each class should have data members to represent the actual objects and member functions to read and display objects, find perimeter and area of the objects, and other useful functions. Use the classes to create objects in your program.

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class Polygon{
protected:
    vector<float> dimensions;
public:
    vector<float> get_dimensions(){
        return dimensions;
    }

    void change_dimensions(vector<float> dims){
        dimensions = dims;
    }

    virtual float get_perimeter() = 0;
    virtual float get_area() = 0;
    virtual ~Polygon() {}
};


class Rectangle : public Polygon {
private:
    float length, breadth;

public:
    Rectangle(float l, float b) : length(l), breadth(b) {
        dimensions.push_back(length);
        dimensions.push_back(breadth);
    }

    float get_perimeter() override {
        return 2 * (length + breadth);
    }

    float get_area() override {
        return length * breadth;
    }
};


class Triangle : public Polygon{
private:
    float side_1, side_2, side_3;

public:
    Triangle(float s1, float s2, float s3) : side_1(s1), side_2(s2), side_3(s3) {
        dimensions.push_back(side_1);
        dimensions.push_back(side_2);
        dimensions.push_back(side_3);
    }

    float get_perimeter() override {
        return side_1 + side_2 + side_3;
    }

    float get_area() override {
        float s = get_perimeter() / 2;
        return sqrt(s * (s - side_1) * (s - side_2) * (s - side_3));
    }
};


class Circle : public Polygon{
private:
    float radius;

public:
    Circle(float r) : radius(r) {
        dimensions.push_back(radius);
    }

    float get_perimeter() override {
        return 2 * M_PI * radius;
    }

    float get_area() override {
        return M_PI * radius * radius;
    }
};


void print_dimensions(vector<float> dims){
    cout << "Polygon Dimensions: ";
    for(int i : dims){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    Rectangle r(5, 10);
    Circle c(5);
    Triangle t(5, 10, 15);
    cout << "Polygon Details" << endl;
    print_dimensions(c.get_dimensions());
    print_dimensions(r.get_dimensions());
    print_dimensions(t.get_dimensions());

    cout << "Rectangle Perimeter: " << r.get_perimeter() << endl;
    cout << "Rectangle Area: " << r.get_area() << endl; 
    cout << "Circle Perimeter: " << c.get_perimeter() << endl;
    cout << "Circle Area: " << c.get_area() << endl;
    cout << "Triangle Perimeter: " << t.get_perimeter() << endl;
    cout << "Triangle Area: " << t.get_area() << endl;

    cout << endl;

    cout << "Changing Dimensions" << endl;
    r.change_dimensions({10, 20});
    c.change_dimensions({10});
    t.change_dimensions({10, 20, 30});

    cout << "Polygon Details" << endl;
    print_dimensions(c.get_dimensions());
    print_dimensions(r.get_dimensions());
    print_dimensions(t.get_dimensions());

    cout << "Rectangle Perimeter: " << r.get_perimeter() << endl;
    cout << "Rectangle Area: " << r.get_area() << endl; 
    cout << "Circle Perimeter: " << c.get_perimeter() << endl;
    cout << "Circle Area: " << c.get_area() << endl;
    cout << "Triangle Perimeter: " << t.get_perimeter() << endl;
    cout << "Triangle Area: " << t.get_area() << endl;
}