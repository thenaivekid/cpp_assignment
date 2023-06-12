#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string input;

    cout << "Enter a data(name, age, address) separated by a ',' ";
    getline(cin, input);
    cout << "You entered: " << input << endl;
    stringstream ss(input);
    string name, age, address;
    char delimiter = ',';
    getline(ss, name, delimiter);
    getline(ss, age, delimiter);
    getline(ss, address, delimiter);
    
    cout << name << age << address << endl;


    // char delimiter = ';';
    // cout << "before delimiter " << input << endl;
    // string substring = input.substr(input.find(delimiter) + 1);
    // cout << "Substring after the delimiter: " << substring << endl;
    return 0;
}
