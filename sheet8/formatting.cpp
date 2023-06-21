#include <iostream>
#include <iomanip> // Include the <iomanip> header for formatting manipulators

int main() {
    int num = 1234;
    double pi = 3.14159;

    // Using width() and fill() to set field width and fill character
    std::cout << std::setw(10) << std::setfill('*') << num << std::endl;

    // Using precision() to set the number of decimal places for a floating-point number
    std::cout << std::setprecision(5) << pi << std::endl;

    // Using setf() and unsetf() to set and unset formatting flags
    std::cout.setf(std::ios::showpos); // Display the positive sign for positive numbers
    std::cout << num << std::endl;
    std::cout.unsetf(std::ios::showpos); // Unset the showpos flag

    // Using flags() to set multiple formatting flags at once
    std::cout.flags(std::ios::hex | std::ios::showbase); // Display number in hexadecimal with the base prefix
    std::cout << num << std::endl;

    return 0;
}
