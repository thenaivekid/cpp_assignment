// Create a class Person and two derived classes Employee and Student, inherited from class Person. Now create a class Manager which is derived from two base classes Employee and Student. Show the use of the virtual base class.


// virtual class avoids ambiguity in the derived class because Manage can inherit print() from both Employee and Student, but it will only inherit print() from Person once.
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Person{
    protected:
        string name;
        int age;

    public:
        Person(string name_, int age_)
        :name(name_), age(age_){
            cout << "Person constructor called" << endl;
        }

        virtual void print(){
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
        }

        virtual ~Person(){
            cout << "Person destructor called" << endl;
        }
};

class Employee: virtual public Person{
    protected:
        int salary;

    public:
        Employee(string name_, int age_, int salary_)
        :Person(name_, age_), salary(salary_){}

        void print(){
            Person::print();
            cout << "Salary: " << salary << endl;
        }

        ~Employee(){
            cout << "Employee destructor called" << endl;
        }
};

class Student: virtual public Person{
    protected:
        int roll;

    public:
        Student(string name_, int age_, int roll_)
        :Person(name_, age_), roll(roll_){}

        void print(){
            Person::print();
            cout << "Roll: " << roll << endl;
        }

        ~Student(){
            cout << "Student destructor called" << endl;
        }
};

class Manager: public Employee, public Student{
    public:
        Manager(string name_, int age_, int salary_, int roll_)
        :Person(name_, age_), Employee(name_, age_, salary_), Student(name_, age_, roll_){}

        void print(){
            Person::print();
            cout << "Salary: " << salary << endl;
            cout << "Roll: " << roll << endl;
        }

        ~Manager(){
            cout << "Manager destructor called" << endl;
        }
};

int main(){
    Employee e("John", 30, 10000);
    Student s("Jane", 20, 1);
    Manager m("Jack", 40, 20000, 2);
    e.print();
    s.print();
    m.print();

    return 0;
}