#include <iostream>

void process_input(int num) {
    try {
        if (num == 0)
            throw "Number cannot be zero";

        if (num < 0)
            throw std::string("Number cannot be negative");

        std::cout << "Result: " << 100 / num << std::endl;
    } catch (const char* ex) {
        std::cout << "Caught exception: " << ex << std::endl;
    } catch (const std::string& ex) {
        std::cout << "Caught exception: " << ex << std::endl;
    } catch (...) {
        std::cout << "Caught unknown exception" << std::endl;
    }
}

int main() {
    process_input(5);
    process_input(0);
    process_input(-10);
    process_input(2);
    return 0;
}
