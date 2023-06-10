#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct {
    int real, imaginary;
}complex;

void display_complex(complex num){
    cout << num.real << " + i" << num.imaginary << endl;
}

void add_complex(complex num1, complex num2){
    num1.real = num1.real + num2.real;
    num1.imaginary = num1.imaginary + num2.imaginary;
    display_complex(num1);
}



int main(){
    complex num1 = {1,2};
    complex num2 = {2,3};
    add_complex(num1, num2);
}