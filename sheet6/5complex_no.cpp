// Write a base class that asks the user to enter a complex number and make a derived class that adds the complex number of its own with the base. Finally, make a third class that is a friend of derived and calculate the difference of the base complex number and its own complex number.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class ComplexNumber{
    protected: 
        int real, imaginary;

        void set_real(){
            int r;
            cout << "Enter real part: ";
            cin >> r;
            real = r;
        }

        void set_imaginary(){
            int i;
            cout << "Enter imaginary part: ";
            cin >> i;
            imaginary = i;
        }

    public:
        ComplexNumber(int real_ = 0, int imaginary_ = 0)
        : real(real_), imaginary(imaginary_){}

        void print(){
            cout << real << " + " << imaginary << "i" << endl;
        }

        int get_real() const {
            return real;
        }

        int get_imaginary() const {
            return imaginary;
        }
        
        ~ComplexNumber(){
            cout << "objected deleted: " ;
            print();
        }
};

class SubtractComplexNumber;

class AddComplexNumber: public ComplexNumber{
    public:
        AddComplexNumber(){
            set_real();
            set_imaginary();
        }

        ComplexNumber add(ComplexNumber c){
            real += c.get_real();
            imaginary += c.get_imaginary();
            return *this;
        }

        friend class SubtractComplexNumber;
};

class SubtractComplexNumnber{
    public:
        ComplexNumber subtract(ComplexNumber c, AddComplexNumber a){
            return ComplexNumber(c.get_real() - a.get_real(), c.get_imaginary() - a.get_imaginary());
        }
};


int main(){
    ComplexNumber c1(1, 2);
    c1.print();
    AddComplexNumber c2;
    c2.print();
    c2.add(c1).print();

    SubtractComplexNumnber s;
    s.subtract(c1, c2).print();
}