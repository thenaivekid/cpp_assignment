#include <iostream>

class Base {
public:
    virtual ~Base() {}
    virtual void foo() { std::cout << "Base::foo()" << std::endl; }
};

class Derived : public Base {
public:
    void foo() override { std::cout << "Derived::foo()" << std::endl; }
};

int main() {
    Base* basePtr = new Derived();
    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);
    
    if (derivedPtr) {
        std::cout << "Dynamic casting successful!" << std::endl;
        derivedPtr->foo();  // Calls Derived::foo()
    } else {
        std::cout << "Dynamic casting failed!" << std::endl;
    }

    delete basePtr;
    return 0;
}
