#include <iostream>
#include <typeinfo>

class Base {
public:
    virtual ~Base() {}
};

class Derived : public Base {
};

int main() {
    Base* basePtr = new Derived();
    const std::type_info& type = typeid(*basePtr);
    std::cout << "Object type: " << type.name() << std::endl;

    delete basePtr;
    return 0;
}
