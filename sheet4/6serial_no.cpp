// Create a class with a data member to hold a "serial number" for each object created from the class. That is, the first object created will be numbered 1, the second 2, and so on by using the basic concept of static data members. Use static member function if it is useful in the program. Otherwise, make a separate program that demonstrates the use of static member function.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Item{
private:
    static int count;
    int id;
    string name;

public:
    Item(string name_)
    : id(count++), name(name_){}

    void display() const {
        cout << id << " " << name << endl;
    }

    static void display_count() {
        cout << count << endl;
    }

    ~Item(){}
};

int Item::count = 1;
int main(){
    Item i1("A"), i2("B"), i3("C");

    i1.display();
    i2.display();
    i3.display();
    return 0;
}