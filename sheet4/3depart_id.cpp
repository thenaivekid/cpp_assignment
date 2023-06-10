// Write a class that can store Department ID and Department Name with constructors to initialize its members. Write destructor member in the same class and display the message "Object n goes out of the scope". Your program should be made such that it should show the order of constructor and destructor invocation.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Department{
private:
    int id;
    string name;

public:
    Department(int d_id, string d_name)
    : id(d_id), name(d_name){
        cout << "Constructor " << id << endl;
    }

    ~Department(){
        cout << "Object " << id << " goes out of the scope" << endl;
    }
};
int main(){
    Department d1(1, "Computer Science");
    Department d2(2, "Electrical Engineering");
    Department d3(3, "Mechanical Engineering");
    

    Department *d4, *d5, *d6;
    d4 = new Department(4, "Civil Engineering");
    d5 = new Department(5, "Electronics Engineering");
    d6 = new Department(6, "Aerospace Engineering");
    delete d4;
    delete d5;
    delete d6;
    delete &d1;
    // if first of the stactically created object is deleted, then the compiler won't automatically call the destructor of other static objects as well
    return 0;
}

// Constructor 1
// Constructor 2
// Constructor 3
// Constructor 4
// Constructor 5
// Constructor 6
// Object 4 goes out of the scope
// Object 5 goes out of the scope
// Object 6 goes out of the scope
// Object 1 goes out of the scope
// Object 3 goes out of the scope
// Object 2 goes out of the scope
// Object 1 goes out of the scope


// Constructor 1
// Constructor 2
// Constructor 3
// Constructor 4
// Constructor 5
// Constructor 6
// Object 4 goes out of the scope
// Object 5 goes out of the scope
// Object 6 goes out of the scope
// Object 1 goes out of the scope
