#include <iostream>
#include <string>
using namespace std;

typedef struct student{
    string name;
    int roll;
}student;

void show_student(student st){
    cout << st.name << st.roll << endl;
}

int main(){
    student st1;
    st1.name = 'Ashok Neupane';
    st1.roll = 21;
    show_student(st1);
}