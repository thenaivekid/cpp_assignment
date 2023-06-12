#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>

using namespace std;

typedef struct Student {
    string name;
    int roll_no;
    string address;
    string phone_number;
} student;

bool compareNames(const student& s1, const student& s2) {
    return s1.name < s2.name;
}

int main() {
    vector<student> students;
    students.push_back(student{ "ashok", 21, "Kavre", "9818467416" });
    students.push_back(student{ "anil", 9, "Bhaktapur", "1232435456" });
    students.push_back(student{ "raj", 2, "Kathmandu", "9818467416" });
    students.push_back(student{ "ravi", 4, "Kathmandu", "9818467416" });
    students.push_back(student{ "raji", 2, "Kathmandu", "9818467416" });

    string filename = "student_temp.csv";

    // Writing student information to file
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

    // Reading student information from file and sorting alphabetically
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cout << "Error opening file." << std::endl;
        return 0;
    }

    vector<student> sortedStudents;
    string line;
    while (getline(inputFile, line)) {
        cout << line << " ---" << endl;
        string name, rollNo, address, phoneNumber;
        stringstream ss(line);
        getline(ss, name, ',');
        cout << name << endl;
        getline(ss, rollNo, ',');
        getline(ss, address, ',');
        getline(ss, phoneNumber, ',');
        sortedStudents.push_back(student{ name, stoi(rollNo), address, phoneNumber });
    }
    inputFile.close();

    // sort(sortedStudents.begin(), sortedStudents.end(), compareNames);

    // // Displaying sorted student information
    // for (int i = 0; i < sortedStudents.size(); i++) {
    //     cout << "Name: " << sortedStudents[i].name << endl;
    //     cout << "Roll No: " << sortedStudents[i].roll_no << endl;
    //     cout << "Address: " << sortedStudents[i].address << endl;
    //     cout << "Phone Number: " << sortedStudents[i].phone_number << endl;
    //     cout << endl;
    // }

    return 0;
}
