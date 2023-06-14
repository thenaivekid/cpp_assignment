#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Animal{
    public:
        Animal(){
            cout << "Animal constructor called" << endl;
        }

        void eat() {cout << "I'm eating generic food" << endl;}

        virtual void makeSound(){
            cout << "The animal says grr" << endl;
        };

        virtual ~Animal(){
            cout << "Animal destructor called" << endl;
        }
};

class Dog : public Animal{
    public:
        void makeSound() override {cout << "Woof!" << endl;}

        ~Dog(){
            cout << "Dog destructor called" << endl;
        }
};

class Cat : public Animal{
    public:
        void makeSound() override {cout << "Meow!" << endl;}

        ~Cat(){
            cout << "Cat destructor called" << endl;
        }
};

int main(){
    Animal* animalPtr = new Dog();
    cout << typeid(animalPtr).name() << endl;
    Dog* dogPtr = dynamic_cast<Dog*>(animalPtr);

    // Dog* dogPtr2 = new Animal();//error: cannot allocate an object of abstract type ‘Animal’ 
    cout << "dogPtr: " << dogPtr << endl;
    cout << "animalPtr: " << animalPtr << endl;

    cout << typeid(dogPtr).name() << endl;
    cout << typeid(animalPtr).name() << endl;

    delete animalPtr;
    delete dogPtr;
}