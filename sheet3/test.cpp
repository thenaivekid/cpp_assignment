#include <iostream>
#include <vector>
#include <cmath>

class Polygon {
protected:
    std::vector<double> dimensions;

public:
    virtual double get_perimeter() = 0;
    virtual double get_area() = 0;
    virtual void get_dimensions() {
        std::cout << "Dimensions: ";
        for (double dimension : dimensions) {
            std::cout << dimension << " ";
        }
        std::cout << std::endl;
    }
    virtual ~Polygon() {}
};

class Triangle : public Polygon {
public:
    Triangle(double s1, double s2, double s3) {
        dimensions.push_back(s1);
        dimensions.push_back(s2);
        dimensions.push_back(s3);
    }

    double get_perimeter() override {
        double perimeter = 0.0;
        for (double dimension : dimensions) {
            perimeter += dimension;
        }
        return perimeter;
    }

    double get_area() override {
        double s = get_perimeter() / 2;
        double area = sqrt(s * (s - dimensions[0]) * (s - dimensions[1]) * (s - dimensions[2]));
        return area;
    }
};

class Rectangle : public Polygon {
public:
    Rectangle(double l, double w) {
        dimensions.push_back(l);
        dimensions.push_back(w);
    }

    double get_perimeter() override {
        return 2 * (dimensions[0] + dimensions[1]);
    }

    double get_area() override {
        return dimensions[0] * dimensions[1];
    }
};

int main() {
    Polygon* triangle = new Triangle(3, 4, 5);
    std::cout << "Triangle Perimeter: " << triangle->get_perimeter() << std::endl;
    std::cout << "Triangle Area: " << triangle->get_area() << std::endl;
    triangle->get_dimensions();

    Polygon* rectangle = new Rectangle(4, 6);
    std::cout << "Rectangle Perimeter: " << rectangle->get_perimeter() << std::endl;
    std::cout << "Rectangle Area: " << rectangle->get_area() << std::endl;
    rectangle->get_dimensions();

    delete triangle;
    delete rectangle;

    return 0;
}
