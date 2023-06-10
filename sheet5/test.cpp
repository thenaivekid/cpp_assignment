#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Breadth; // Forward declaration of Breadth class

class Length {
private:
    int data;

public:
    Length(int l)
        : data(l) {}

    void print() {
        cout << "Length: " << data << endl;
    }

    friend int area(Length l, Breadth b);
};

class Breadth {
private:
    int data;

public:
    Breadth(int l)
        : data(l) {}

    void print() {
        cout << "Breadth: " << data << endl;
    }

    friend int area(Length l, Breadth b);
};

int area(Length l, Breadth b) {
    return l.data * b.data;
}

int main() {
    Length l(10);
    Breadth b(20);

    l.print();
    b.print();

    int calculatedArea = area(l, b);
    cout << "Calculated Area: " << calculatedArea << endl;

    return 0;
}
