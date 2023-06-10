// Store and retrieve the name of the students and obtained marks in c programming in 1st semester using structure
#include <iostream>
#include <string>
using namespace std;

typedef struct Result{
    string name;
    int mark_in_c;
}student;

int main(){
    student student1;
    
    // store
    student1.name = "Ashok";
    student1.mark_in_c = 58;

    // retrieve
    cout << student1.name << " scored " << student1.mark_in_c << " mark in c programming. " << endl;
    return 1;
}