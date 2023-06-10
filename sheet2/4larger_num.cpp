// Write a function that passes two temperatures by reference and sets the larger of the two numbers to a value entered by user by using return by reference.
#include <iostream>
using namespace std;

double& set_larger_tempr(double& temp1, double& temp2) {
    return (temp1 > temp2) ? temp1 : temp2;
}

int main() {
    double temperature1, temperature2;
    
    cout << "Enter the first temperature: ";
    cin >> temperature1;
    
    cout << "Enter the second temperature: ";
    cin >> temperature2;
    
    cout << "initial values " << temperature1 << " and " << temperature2 << endl;
    
    double larger_value;
    cout << "Enter the larger value: ";
    cin >> larger_value;

    set_larger_tempr(temperature1, temperature2) = larger_value;
    cout << "final values " << temperature1 << " and " << temperature2 << endl;
    return 0;
}
