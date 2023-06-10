#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Coordinate{
    int x, y;

public:
    Coordinate(int x_, int y_)
    : x(x_), y(y_){}

    int get_x(){
        return x;
    }

    int get_y(){
        return y;
    }

    void print(){
        cout << "(" << x << ", " << y << ")" << endl;
    }

    Coordinate add(Coordinate c){
        return Coordinate(x + c.x, y + c.y);
    }
};

int main(){
    Coordinate c1(1, 2), c2(3, 4);
    c1.print();
    c2.print();
    c1.add(c2).print();    
}