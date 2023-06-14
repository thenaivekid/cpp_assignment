#include <iostream>

class Animal {
public:
    int age;

    Animal() {
        std::cout << "Animal constructor" << std::endl;
    }

    ~Animal() {
        std::cout << "Animal destructor" << std::endl;
    }
};

class Mammal : public virtual Animal {
public:
    Mammal() {
        std::cout << "Mammal constructor" << std::endl;
    }

    void breathe() {
        std::cout << "Mammal is breathing" << std::endl;
    }

    ~Mammal() {
        std::cout << "Mammal destructor" << std::endl;
    }
};

class WingedAnimal : public virtual Animal {
public:
    WingedAnimal() {
        std::cout << "Winged animal constructor" << std::endl;
    }

    void flapWings() {
        std::cout << "Winged animal is flapping wings" << std::endl;
    }

    ~WingedAnimal() {
        std::cout << "Winged animal destructor" << std::endl;
    }
};

class Bat : public Mammal, public WingedAnimal {
public:
    Bat() {
        std::cout << "Bat constructor" << std::endl;
    }

    void fly() {
        std::cout << "Bat is flying" << std::endl;
    }

    ~Bat() {
        std::cout << "Bat destructor" << std::endl;
    }
};

int main() {
    Bat bat;
    bat.age = 10;
    bat.breathe();
    bat.flapWings();
    bat.fly();

    return 0;
}
