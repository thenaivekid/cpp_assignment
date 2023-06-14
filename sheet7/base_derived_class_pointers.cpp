#include <iostream>

class Base {
public:
    virtual void foo() {
        std::cout << "Base::foo()" << std::endl;
    }
};

class Derived : public Base {
public:
    void foo() override {
        std::cout << "Derived::foo()" << std::endl;
    }
};

int main() {
    Base* basePtr = new Base();
    Derived* derivedPtr = new Derived();

    basePtr->foo();    // Calls Base::foo()
    derivedPtr->foo(); // Calls Derived::foo()

    Base* basePtrDerived = derivedPtr;
    basePtrDerived->foo(); // Calls Derived::foo()

    delete basePtr;
    delete derivedPtr;

    return 0;
}
