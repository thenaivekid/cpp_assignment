// Write a simple program that converts the temperature in Celsius scale to Fahrenheit scale and vice versa using the basic concept of class and object. Make separate classes for Celsius and Fahrenheit which will have the private members that hold the temperature value and make conversion functions in each class for conversion from one to another. For example, you need to have a function toFahrenheit() in class Celsius that converts to Fahrenheit scale and returns the value.
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Celsius{
    private:
        float temp;
    
    public:
        Celsius(float temp): temp(temp){
        }

        float to_fahrenheit(){
            return (temp * 9/5) + 32;
        }

        ~Celsius(){

        }
};

class Fahrenheit{
    private:
    float temp;

    public:
        Fahrenheit(float temp): temp(temp){
        }

        float to_celsius(){
            return (temp - 32) * 5/9;
        }

        ~Fahrenheit(){
        }
};

int main(){
    Celsius c(37);
    Fahrenheit f(100);
    cout << c.to_fahrenheit() << endl;
    cout << f.to_celsius() << endl;
    Celsius *c1 = new Celsius(100);
    cout << c1->to_fahrenheit() << endl;
    delete c1;
}