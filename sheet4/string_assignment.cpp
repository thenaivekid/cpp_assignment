#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;



int main(){
    string name = "Ashok Neupane";
    string nickname;
    nickname.assign(name);
    cout << nickname << endl;
    name = "Anil Shrestha";
    cout << nickname << endl;
    cout << name;
}