#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Complex{
    int real, imaginary;

public:
    Complex(int r, int i)
    : real(r), imaginary(i){}

    void print(){
        cout << real << " + " << imaginary << "i" << endl;
    }

    int get_real(){
        return real;
    }

    int get_imaginary(){
        return imaginary;
    }
};

Complex operator+(Complex c1, Complex c2){
    return Complex(c1.get_real() + c2.get_real(), c1.get_imaginary() + c2.get_imaginary());
}

int main(){
    cout << 3 + 2 << endl;
    Complex c1(3, 2), c2(2, 3);
    Complex c3 = c1 + c2;
    c3.print();   
    cout << 3.4 + 3.6 << endl;
}