// Write a program to compare two objects of a class that contains an integer value as its data member. Make overloading functions to overload equality(==), less than(<), greater than(>), not equal (!=), greater than or equal to (>=), and less than or equal to(<=) operators using member operator functions.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Integer{
private:
    int x;

public:
    Integer(int x_)
    : x(x_){}

    void print() const {
        cout << x << endl;
    }

    bool operator==(const Integer& other) const{
        return x == other.x;
    }

    bool operator<(const Integer& other) const{
        return x < other.x;
    }

    bool operator>(const Integer& other) const{
        return x > other.x;
    }

    bool operator!=(const Integer& other) const{
        return x != other.x;
    }

    bool operator<=(const Integer& other) const{
        return x <= other.x;
    }

    bool operator>=(const Integer& other) const{
        return x >= other.x;
    }

    ~Integer(){}
};

int main(){
    Integer a(1), b(2), c(1);
    vector <string> truth = {"false", "true"};
    a.print();
    b.print();
    c.print();
    cout << "a == b: " << truth[(a == b)] << endl;
    cout << "a == c: " << truth[(a == c)] << endl;
    cout << "a < b: " << truth[(a < b)] << endl;
    cout << "a > b: " << truth[(a > b)] << endl;
    cout << "a != b: " << truth[(a != b)] << endl;
    cout << "a <= b: " << truth[(a <= b)] << endl;
    cout << "a >= b: " << truth[(a >= b)] << endl;
    cout << "a != c: " << truth[(a != c)] << endl;
}