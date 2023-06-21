// // Write a program that stores the information about students (name, student id, department, and address) in a structure and then transfers the information to a file in your directory. Finally, retrieve the information from your file and print it in the proper format on your output screen.

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

struct Student
{
    string name;
    int student_id;
    string department;
    string address;

    Student(string name_, int student_id_, string department_, string address_) : name(name_), student_id(student_id_), department(department_), address(address_) {}
};


ostream &operator<<(ostream& os, const Student& student)
{
    os << setw(25) << student.name << setw(5) << " " << student.student_id << " " << setw(20) << student.department << " " << setw(25) << student.address;
    return os;
}


int main(){
    vector< Student > students;
    students.push_back(Student("John", 1, "Computer Science", "123 Main St."));
    students.push_back(Student("Jane", 2, "Computer Science", "123 Main St."));
    students.push_back(Student("Joe", 3, "Computer Science", "123 Main St."));
    students.push_back(Student("Jill", 4, "Computer Science", "123 Main St."));
    students.push_back(Student("Jack", 5, "Computer Science", "123 Main St."));

    ofstream output_file("students.txt", ios::binary);
    if(!output_file){
        cerr << "Error opening output file" << endl;
        return 1;
    }

    cout << "Writing to file" << endl;
    
    for (int i = 0; i < students.size(); i++)
    {
        output_file.write(reinterpret_cast<char*>(&students[i]), sizeof(Student));
    }
    cout << "Wrote to file" << endl;
    output_file.close();

    ifstream input_file("students.txt", ios::binary);
    if(!input_file){
        cerr << "Error opening file" << endl;
        return 1;
    }

    cout << "Reading from file" << endl;
    Student *temp = new Student("", 0, "", "");
    int i = 0;
    cout << setw(25) << "Name" << setw(5) << " " << "Id" << " " << setw(20) << "Dept" << " " << setw(25) << "Address" << endl;
    while(!input_file.eof())
    {
        input_file.read(reinterpret_cast<char*>(temp), sizeof(Student));
        cout << *temp << endl;
        if (i == int(students.size() - 1))//to prevent last line from being printed twice
            break;
        ++i;
    }
    delete temp;
    input_file.close();

    delete &students;
}

