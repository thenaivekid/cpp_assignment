#include <iostream>

class Base {
public:
    Base() {
        std::cout << "Base constructor" << std::endl;
        std::cout << this << std::endl;
    }

    virtual ~Base() {
        std::cout << "Base destructor" << std::endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        std::cout << "Derived constructor" << std::endl;
        std::cout << this << std::endl;
    }

    ~Derived() {
        std::cout << "Derived destructor" << std::endl;
    }
};

int main() {
    Derived derivedObj;
    return 0;
}
