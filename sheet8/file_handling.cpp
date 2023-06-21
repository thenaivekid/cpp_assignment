#include <iostream>
#include <string>
#include <fstream>

int main() {
    // Writing to a file using ofstream
    std::ofstream outfile("test.txt");
    if (outfile.is_open()) {
        outfile << "C++ lab class" << std::endl;
        outfile.close();
        std::cout << "File write successful." << std::endl;
    } else {
        std::cout << "Unable to open file for writing." << std::endl;
    }

    // Reading from a file using ifstream
    std::ifstream infile("test.txt");
    if (infile.is_open()) {
        std::string line;
        while (std::getline(infile, line)) {
            std::cout << "Contents of file: " << line << std::endl;
        }
        infile.close();
    } else {
        std::cout << "Unable to open file for reading." << std::endl;
    }

    // Appending to a file using fstream
    std::fstream file("test.txt", std::ios::app);
    if (file.is_open()) {
        file << "Appending additional content." << std::endl;
        file.close();
        std::cout << "File append successful." << std::endl;
    } else {
        std::cout << "Unable to open file for appending." << std::endl;
    }

    // Reading from the file again to see the appended content
    std::ifstream infile2("test.txt");
    if (infile2.is_open()) {
        std::string line;
        while (std::getline(infile2, line)) {
            std::cout << "Contents of file after append: " << line << std::endl;
        }
        infile2.close();
    } else {
        std::cout << "Unable to open file for reading." << std::endl;
    }

    return 0;
}
