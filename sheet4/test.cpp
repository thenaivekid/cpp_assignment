#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

int main(){
    char *str;
    string new_string = "ashok";

    str = new char[strlen(new_string.c_str())+1];
    strcpy(str, new_string.c_str());
    cout<<str<<endl;
}