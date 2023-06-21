#include <cassert>
#include <iostream>

int divide(int numerator, int denominator) {
    assert(denominator != 0 && "Division by zero is not allowed");
    return numerator / denominator;
}

int main() {
    int result = divide(10, 2);
    // Valid division, no assertion failure

    result = divide(20, 0);
    // This will trigger an assertion failure since division by zero is not allowed

    std::cout << "Result: " << result << std::endl;
    return 0;
}
