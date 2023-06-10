// Write a program that has a class with a dynamically allocated character array as its data member. One object should contain "Engineers are" and another should contain " Creatures of logic". Member function join() should concatenate two strings by passing two objects as arguments. Display the concatenated string through a member function. Use constructors to allocate and initialize the data member. Also, write a destructor to free the allocated memory for the character array. Make your own function for the concatenation of two strings.

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

class StringConcatenator{
private:
    char *str;

public:
    StringConcatenator(const char *s){
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    static void display(StringConcatenator s){
        cout << s.str << endl;
    }

    static char * join(StringConcatenator s1, StringConcatenator s2){
        int length_of_s1 = strlen(s1.str);
        int total_length = strlen(s1.str) + strlen(s2.str) + 1;
        char *s = new char[total_length];
        for(int i = 0; i < length_of_s1; i++){
            s[i] = s1.str[i];
        }
        for(int i = 0; i < strlen(s2.str); i++){
            s[i + length_of_s1] = s2.str[i];
        }
        s[total_length - 1] = '\0';
        return s;
    }

    ~StringConcatenator(){
        delete str;
        cout << "deleting" << str << endl;
    }

};

int main(){
    StringConcatenator s1("Engineers are");
    StringConcatenator s2(" Creatures of logic");
    StringConcatenator::display(s1);
    StringConcatenator::display(s2);
    StringConcatenator::display(StringConcatenator::join(s1, s2));
    StringConcatenator s(StringConcatenator::join(s1, s2));
    StringConcatenator::display(s);
}