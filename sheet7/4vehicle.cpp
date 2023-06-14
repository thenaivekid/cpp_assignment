// Create a polymorphic class Vehicle and create other derived classes Bus, Car, and Bike from Vehicle. Illustrate RTTI by the use of dynamic_cast and typeid operators in this program.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Vehicle{
    protected:
        string name;
        int wheels;

    public:
        Vehicle(string name_, int wheels_)
        :name(name_), wheels(wheels_){}

        virtual void print(){
            cout << "Name: " << name << endl;
            cout << "Wheels: " << wheels << endl;
        }

        virtual ~Vehicle(){}
};

class Bus : public Vehicle{
    private:
        int passengers;
    
    public:
        Bus(string name_, int wheel_, int passengers_)
        : Vehicle(name_, wheel_), passengers(passengers_){}

        void print () override {
            Vehicle::print();
            cout << passengers << endl;
        }

        ~Bus(){}
};

class Car: public Vehicle{
    private:
        string model;
    
    public:
        Car(string name_, int wheel_, string model_)
        : Vehicle(name_, wheel_), model(model_){}

        void print () override {
            Vehicle::print();
            cout << model << endl;
        }

        ~Car(){}
};

class Bike: public Vehicle{
    private:
        string type;
    
    public:
        Bike(string name_, int wheel_, string type_)
        : Vehicle(name_, wheel_), type(type_){}

        void print () override {
            Vehicle::print();
            cout << type << endl;
        }

        ~Bike(){}
};


int main(){
    Bike b("Bike", 2, "Sports");
    Car c("Car", 4, "SUV");
    Bus bu("Bus", 6, 50);

    b.print();
    c.print();
    bu.print();

    Vehicle *v1 = &b;
    Vehicle *v2 = &c;
    Vehicle *v3 = &bu;

    v1->print();
    v2->print();
    v3->print();

    cout << typeid(*v1).name() << endl;
    cout << typeid(*v2).name() << endl;
    cout << typeid(*v3).name() << endl;

    Bike *b1 = dynamic_cast<Bike*>(v1);
    Car *c1 = dynamic_cast<Car*>(v2);
    Bus *bu1 = dynamic_cast<Bus*>(v3);

    cout << typeid(*b1).name() << endl;
    cout << typeid(*c1).name() << endl;
    cout << typeid(*bu1).name() << endl;

    b1-> print();
    c1-> print();
    bu1-> print();

    c.Vehicle::print();

    Vehicle v("Vehicle", 0);
    cout << typeid(v).name() << endl;

    // Bike *b2 = dynamic_cast<Vehicle*>(v1);

    return 0;
}