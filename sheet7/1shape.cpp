// Write a program to create a class shape with functions to find the area of the shapes and display the names of the shapes and other essential components of the class. Create derived classes circle, rectangle, and trapezoid each having overriding functions area() and display(). Write a suitable program to illustrate virtual functions and virtual destructors.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Shape{
    public:
        virtual float area() = 0;
        virtual void display() = 0;
        virtual ~Shape(){
            cout << "Shape destructor called" << endl;
        }
};

class Circle: public Shape{
    private:
        float radius;

    public:
        Circle(float radius_)
        :radius(radius_){}

        float area(){
            return 3.14 * radius * radius;
        }

        void display(){
            cout << "Circle with radius " << radius << " has area " << area() << endl;
        }

        ~Circle(){
            cout << "Circle destructor called" << endl;
        }
};

class Rectangle: public Shape{
    private:
        float length, breadth;

    public:
        Rectangle(float length_, float breadth_)
        :length(length_), breadth(breadth_){}

        float area(){
            return length * breadth;
        }

        void display(){
            cout << "Rectangle with length " << length << " and breadth " << breadth << " has area " << area() << endl;
        }

        ~Rectangle(){
            cout << "Rectangle destructor called" << endl;
        }
};

class Trapezoid : public Shape{
    private:
        float a, b, h;

    public:
        Trapezoid(float a_, float b_, float h_)
        :a(a_), b(b_), h(h_){}

        float area(){
            return (a + b) * h / 2;
        }

        void display(){
            cout << "Trapezoid with a = " << a << ", b = " << b << " and h = " << h << " has area " << area() << endl;
        }

        ~Trapezoid(){
            cout << "Trapezoid destructor called" << endl;
        }
};

int main(){
    Rectangle r(2, 3);
    Circle c(4);
    Trapezoid t(2, 3, 4);
    r.display();
    c.display();
    t.display();
}