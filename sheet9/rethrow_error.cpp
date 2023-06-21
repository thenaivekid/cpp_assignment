#include <iostream>

void processFile() {
    try {
        // Code that may throw an exception while processing a file
        throw std::runtime_error("Error while processing the file");
    } catch (const std::exception& ex) {
        std::cout << "Caught exception: " << ex.what() << std::endl;
        std::cout << "Re-throwing the exception..." << std::endl;
        throw;  // Re-throw the caught exception
    }
}

int main() {
    try {
        processFile();
    } catch (const std::exception& ex) {
        std::cout << "Caught exception in the main function: " << ex.what() << std::endl;
    }

    return 0;
}
