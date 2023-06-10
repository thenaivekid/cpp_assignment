// Assume that one constructor initializes data member say num_vehicle, hour, and rate. There should be a 10% discount if num_vehicle exceeds 10. Display the total charge. Use two objects and show a bit-by-bit copy of one object to another (make your own copy constructor).

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Parking{
private:
    int num_vehicle;
    float hour, rate;

public:
    Parking(int n, float h, float r) : num_vehicle(n), hour(h), rate(r) {
        cout << "Number of vehicle: " << num_vehicle << endl;
    }
    
    // can copy object even without it
    Parking(const Parking &p) : num_vehicle(p.num_vehicle), hour(p.hour), rate(p.rate) {
        cout << "copying from " << p.num_vehicle << endl;
    }

    void display_total_charge() const {
        if (num_vehicle > 10) {
            cout << "Total charge: " << hour * rate * num_vehicle * 0.9 << endl;
        }
        else{
            cout << "Total charge: " << hour * rate * num_vehicle << endl;
        }
    }

    ~Parking(){}
};

int main(){
    Parking p1(10, 2, 5), p2(15, 3, 7);
    Parking p3 = p1;
    p1.display_total_charge();
    p2.display_total_charge();
    p3.display_total_charge();
    return 0;
}