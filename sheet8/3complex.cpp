// Write a program to overload stream operators to read a complex number and display the complex number in a+ib format.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Complex{
    int real, imaginary;
    public:
        Complex(int r = 0, int i = 0){
            real = r;
            imaginary = i;
        }

        void print(){
            cout << real << " + i" << imaginary << endl;
        }

        friend ostream &operator<<(ostream &output, const Complex &c);
        friend istream &operator>>(istream &input, Complex &c);
};

ostream &operator<<(ostream &output, const Complex &c){
    output << c.real << " + i" << c.imaginary << endl;
    return output;
}

istream &operator>>(istream &input, Complex& c){
    input >> c.real >> c.imaginary;
    return input;
}

int main(){
    Complex c1(10, 5);

    c1.print();
    cout << c1;

    Complex c2;
    cout << "Enter a complex number: ";
    cin >> c2;
    cout << c2;
}