// Write three derived classes inheriting functionality of base class person (should have a member function that asks to enter name and age) and with added unique features of student, and employee, and functionality to assign, change and delete records of student and employee. And make one member function for printing the address of the objects of classes (base and derived) using this pointer. Create two objects of the base class and derived classes each and print the addresses of individual objects. Using a calculator, calculate the address space occupied by each object and verify this with address spaces printed by the program.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Person{
    protected:
        string name;
        int age;
    
    public:
        void set_name_age(){
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter age: ";
            cin >> age;
        }

        virtual void print() const {
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
        }

        virtual void print_address() const {
            cout << "Address of base object: " << this << endl;
        }

        ~Person(){
            cout << name << " deleted." << endl;
        }
};

class Student : public Person{
    private:
        int roll_no;
        string course;
    
    public:
        void set_roll_course(){
            cout << "Enter roll no: ";
            cin >> roll_no;
            cout << "Enter course: ";
            cin >> course;
        }
        
        void print() const override{
            Person::print();
            cout << "Roll no: " << roll_no << endl;
            cout << "Course: " << course << endl;
        }
        
        void print_address() const override{
            Person::print_address();
            cout << "Address of derived class object: " << this << endl;
        }
};

class Employee : public Person{
    private:
        int emp_id;
        string dept;
    
    public:
        void set_emp_dept(){
            cout << "Enter employee id: ";
            cin >> emp_id;
            cout << "Enter department: ";
            cin >> dept;
        }

        void print() const override{
            Person::print();
            cout << "Employee id: " << emp_id << endl;
            cout << "Department: " << dept << endl;
        }

        void print_address() const override{
            Person::print_address();
            cout << "Address of derived class object: " << this << endl;
        }
};

int main(){
    Person *p1 = new Person;
    Person *p2 = new Person;
    Student *s1 = new Student;
    Student *s2 = new Student;
    Employee *e1 = new Employee;
    Employee *e2 = new Employee;

    p1->set_name_age();
    p2->set_name_age();

    s1->set_name_age();
    s1->set_roll_course();

    e1->set_name_age();
    e1->set_emp_dept();

    e2->set_name_age();
    e2->set_emp_dept();

    cout << endl << "Printing p1" << endl;
    p1->print();
    p1->print_address();

    cout << endl << "Printing p2" << endl;
    p2->print();
    p2->print_address();

    cout << endl << "Printing s1" << endl;  
    s1->print();
    s1->print_address();

    cout << endl << "Printing s2" << endl;
    s2->print();
    s2->print_address();

    cout << endl << "Printing e1" << endl;
    e1->print();
    e1->print_address();

    cout << endl << "Printing e2" << endl;
    e2->print();
    e2->print_address();

    return 0;
}