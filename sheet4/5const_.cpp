// Write a program that illustrates the following relationship and comment on them. 

// i) const_object.non_const_mem_function

// ii) const_object.const_mem_function

// iii) non_const_object.non_const_mem_function

// iv) non_const_object.const_mem_function
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Travel{
private:
    static int count;
    const int id;
    const string destination;
    string duration;
    int price;

public:
    Travel(string dest, string dur, int p)
    : id(++count), destination(dest), duration(dur), price(p){
    }

    // const member function
    void display() const {
        cout << "ID: " << id << endl;
        cout << "Destination: " << destination << endl;
        cout << "Duration: " << duration << endl;
        cout << "Price: " << price << endl;
    }

    // non const member function
    void set_duration(string dur){
        cout << "Duration updated from " << duration << " to " << dur << endl;
        duration = dur;
    }
    
    // non const member function
    void set_price(int p){
        cout << "Price updated from " << price << " to " << p << endl;
        price = p;
    }

    ~Travel(){}
};

int Travel::count = 0;

int main(){
    Travel t1("India", "2 Days", 1000);//non const object
    Travel t2("Japan", "3 Days", 2000);//non const object
    
    t1.display();
    t2.display();

    t1.set_duration("3 Days");
    t1.set_price(2000);
    t1.display();

    t2.set_duration("4 Days");
    t2.set_price(3000);
    t2.display();

    const Travel t3("China", "4 Days", 30000);//const object
    t3.display();
    // t3.set_duration("5 Days");//error
    // t3.set_price(4000);//error
    t3.display();
    return 0;
}