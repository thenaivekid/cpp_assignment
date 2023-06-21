#include <iostream>
#include <string>

int main() {
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;
    std::cout << "You entered: " << num << std::endl;

    double pi = 3.14159;
    std::cout << "The value of pi is: " << pi << std::endl;

    std::cout << "Enter your name: ";
    std::string name;
    getline(std::cin, name);
    std::cout << "Hello, " << name << "! Nice to meet you." << std::endl;

    return 0;
}
