#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CustomInt{
private:
    int value;

public:
    CustomInt(int value_)
    : value(value_){}

    operator int(){
        return value;
    }

    void print(){
        cout << "Value is " << value << endl;
    }
};

int main(){
    CustomInt c1(5);
    c1.print();
    cout << int(c1) << endl;
    
}