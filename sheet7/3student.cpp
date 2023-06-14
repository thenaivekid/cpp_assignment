// Write a program with an abstract class Student and create derive classes Engineering, Medicine and Science from base class Student. Create the objects of the derived classes and process them and access them using an array of pointers of type base class Student.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student{
    protected:
        string name;
        int roll;

    public:
        Student(string name_, int roll_)
        :name(name_), roll(roll_){}

        virtual void print(){
            cout << "Name: " << name << endl;
            cout << "Roll: " << roll << endl;
        }

        virtual ~Student(){}
};

class Engineering: public Student{
    private:
        string teckstack;

    public:
        Engineering(string name_, int roll_, string teckstack_)
        :Student(name_, roll_), teckstack(teckstack_){}

        void print(){
            Student::print();
            cout << "Teckstack: " << teckstack << endl;
        }
};

class Medicine: public Student{
    private:
        string hospital;

    public:
        Medicine(string name_, int roll_, string branch_)
        :Student(name_, roll_), hospital(branch_){}

        void print(){
            Student::print();
            cout << "hospital: " << hospital << endl;
        }

        ~Medicine(){}
};

class Science: public Student{
    private:
        string subject;

    public:
        Science(string name_, int roll_, string subject_)
        :Student(name_, roll_), subject(subject_){}

        void print(){
            Student::print();
            cout << "subject: " << subject << endl;
        }

        ~Science(){}
};


int main(){
    Engineering e("Rahul", 1, "C++");
    Medicine m("Raj", 2, "Patan");
    Science s("Rohan", 3, "Physics");

    vector<Student*> students;
    students.push_back(&e);
    students.push_back(&m);
    students.push_back(&s);

    for(int i = 0; i < students.size(); i++){
        students[i]->print();
        cout << endl;
    }
    
    return 0;
}