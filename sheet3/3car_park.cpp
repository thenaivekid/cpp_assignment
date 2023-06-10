// Create a class called carpark that has int data member for car id, int data member for charge_per_hr/hour, and float data member for the parked time. Make functions to set data members and show the charge_per_hrs and parked hours of the corresponding car id. Make functions for setting and showing the data members. Member function should be called from other functions.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CarPark{
    private:
        int id;
        int charge_per_hr;
        float parked_time;

    public:
        CarPark(){}
    
        void set_id(int car_id){
            id = car_id;
        }

        void set_charge_per_hr(int charge_per_hour){
            charge_per_hr = charge_per_hour;
        }

        void set_parked_time(float time){
            parked_time = time;
        }

        int get_id(){
            return id;
        }

        int get_charge_per_hr(){
            return charge_per_hr;
        }

        float get_parked_time(){
            return parked_time;
        }

        void show_charge(){
            cout << "Total charge is: " << get_charge_per_hr() * get_parked_time() << "Rs" << " for " << get_id() << " for "<< get_parked_time() << " hours" << endl;
        }

        void show_parked_time(){
            cout << "Parked time is: " << get_parked_time() << " hours" << " for " << get_id() << endl;
        }

        ~CarPark(){
        }
};

int main(){
    CarPark *car1 = new CarPark();
    car1->set_id(1);
    car1->set_charge_per_hr(10);
    car1->set_parked_time(2.3);
    car1->show_charge();
    car1->show_parked_time();
    delete car1;

    CarPark car2;
    car2.set_id(2);
    car2.set_charge_per_hr(10);
    car2.set_parked_time(3.6);
    car2.show_charge();
    car2.show_parked_time();
    return 0;
}