// Assume that an object represents an employee report that contains information like employee id, total bonus, total overtime in a particular year. Use an array of objects to represent n employees' reports. Write a program that displays the report. Use setpara() member function to set report attributes by passing the arguments and member function displayreport() to show the report according to the parameter passed. Display the report in the following format.

// An employee with ... ... ... has received Rs ... ... ...as a bonus

// and

// had worked ... ... ... hours as overtime in the year ... ... ...

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Employee{
private:
    static int count;
    int id, year;
    float total_bonus, total_overtime, total_salary;


public:
    Employee(float bonus = 0.0f, float overtime = 0.0f, float salary = 0.0f, int yr = 2022)
    : id(count++), total_bonus(bonus), total_overtime(overtime), total_salary(salary), year(yr){}

    void set_param(float bonus, float overtime, float salary){
        total_bonus = bonus;
        total_overtime = overtime;
        total_salary = salary;
    }

    void display_report(){
        cout << "An employee with id " << id << " has received Rs" << total_bonus << " as a bonus" << " and Rs" << endl << " " << total_salary << " as a salary" << endl << " and had worked " << total_overtime << " hours as overtime in the year " << year << endl;
    }

    static int get_count(){
        return count;
    }
};


int Employee::count = 0;


int main(){
    Employee emp[3];
    emp[0].set_param(1000, 10, 10000);
    emp[1].set_param(2000, 20, 20000);
    emp[2].set_param(3000, 30, 30000);

    for(int i = 0; i < 3; i++){
        emp[i].display_report();
    }

    cout << endl;
    cout << "Current employees count: " << Employee::get_count() << endl;
    return 0;
}