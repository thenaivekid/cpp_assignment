// Write two classes to store distances in meter-centimeter and feet-inch systems respectively. Write conversions functions so that the program can convert objects of both types.
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BritishUnit;

class SIUnit{
private:
    int meter;
    float centimeter;

public:
    SIUnit(int meter_, float centimeter_)
    : meter(meter_), centimeter(centimeter_) {}

    SIUnit(BritishUnit b);

    int get_meter() const{
        return meter;
    }

    float get_centimeter() const{
        return centimeter;
    }

    void print(){
        cout << meter << "m " << centimeter << "cm" << endl;
    }

    ~SIUnit(){}
};

class BritishUnit{
private:
    int feet;
    float inch;

public:
    BritishUnit(int feet_, float inch_)
    : feet(feet_), inch(inch_) {}

    BritishUnit(SIUnit s){
        float meter = s.get_meter() + s.get_centimeter()/100.0;
        feet = int(meter * 3.2808);
        inch = float(meter*3.2808 - feet)*12;
    }

    int get_feet() const{
        return feet;
    }

    int get_inch() const{
        return inch;
    }

    void print(){
        cout << feet << "ft " << inch << "in" << endl;
    }

    ~BritishUnit(){}
};

SIUnit::SIUnit(BritishUnit b){
    float feet = b.get_feet() + b.get_inch()/12.0;
        meter = int(feet*0.3048);
        centimeter = float(feet*0.3048 - meter)*100;
}



int main(){
    SIUnit s(1, 23);
    BritishUnit b(1,2);
    s.print();
    b.print();
    BritishUnit(s).print();
    SIUnit(b).print();
}