// Assume that you want to check whether the number is prime or not. Write a program that asks for numbers repeatedly. When it finishes checking a number the program asks if the user wants to do another calculation. The response can be 'y' or 'n'. Don't forget to use the object-oriented concept.
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class CheckPrimeNumber {
private:
    int number;

public:
    CheckPrimeNumber(int number): number(number) {
    }

private:
    bool is_prime() {
        if (number <= 1) {
            return false;
        }

        for (int i = 2; i <= sqrt(number); i++) {
            if (number % i == 0) {
                return false;
            }
        }

        return true;
    }

public:
    void print_prime_or_not() {
        if (is_prime()) {
            cout << number<< " is a prime number." << endl;
        }
        else {
            cout << number << " is not a prime number." << endl;
        }
    }
};
    

int main() {
    char choice;

    do {
        int num;
        cout << "Enter a number: ";
        cin >> num;

        CheckPrimeNumber checker(num);
        checker.print_prime_or_not();
        cout << "Do you want to perform another calculation? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

            return 0;
}

