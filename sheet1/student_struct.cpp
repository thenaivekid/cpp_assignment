// Write a program to read name, rollno, address, and phone number of each student in your class using structure.
//  Store the information in file so that you can recover the information later. 
//  While recovering the information from the file sort the information alphabetically according to the name.

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

typedef struct Student{
    string name;
    int roll_no;
    string address;
    string phone_number;
}student;

int main(){
    vector < student > students;
    students.push_back(student{"ashok", 21, "Kavre", "9818467416"});
    students.push_back(student{"anil", 9, "Bhaktapur", "1232435456"});      
    students.push_back(student{"raj", 2, "Kathmandu", "9818467416"});
    students.push_back(student{"ravi", 4, "Kathmandu", "9818467416"});
    students.push_back(student{"raji", 2, "Kathmandu", "9818467416"});

    // cout << students[0].name << " " << students[0].roll_no << " " << students[0].address << " " << students[0].phone_number << endl;

    student temp;
    string filename = "student_temp.csv";

    ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error opening file." << std::endl;
        return 0;
    }

    for (int i = 0; i < students.size(); i++) {
            file << students[i].name << ", " << students[i].roll_no << ", " << students[i].address << ", " << students[i].phone_number << endl;
        }
    file.close();
    std::cout << "Table written to file: " << filename << std::endl;

    ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error opening file." << std::endl;
        return 0;
    }
    cout << file;
    string temp;
    // while(getline(file, temp)){
    //     cout << temp << endl;
    // }
    file.close();
    return 0;
}