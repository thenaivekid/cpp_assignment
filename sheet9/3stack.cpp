// Modify the stack class given in the previous lab to add the exception when a user tries to add an item while the stack is full and when the user tries to add the item while the stack is empty. Throw exceptions in both of the cases and handle these exceptions.

#include <iostream>
#include <string>
#include <exception>
#include <vector>
using namespace std;

class StackExecption : public exception{
private:
    string message;

public:
    StackExecption(string message_)
    : message(message_) {}

    const char* what() const throw(){
        return message.c_str();
    }
};

template <class T>
class Stack{
    int capacity = 10;
    vector <T> v;

public:
    Stack(int capacity_ = 10)
    : capacity(capacity_){}

    bool is_empty(){
        return this->v.size() == 0;
    }

    bool is_full(){
        return v.size() == capacity;
    }

    void push(T var){
        if (v.size() == capacity){
            throw StackExecption("Stack is full");
        }
        v.push_back(var);
    }

    T pop(){
        if (is_empty()){
            throw StackExecption("Stack is empty");
        }
        T temp = v.back();
        v.pop_back();
        return temp;
    }

    T peek(){
        if (is_empty()){
            throw StackExecption("Stack is empty");
        }
        return v.back();
    }
};

int main(){
    Stack <int> s1;
    Stack <string> s2;
    Stack <char> s3;

    try{
        for (int i = 0; i < 15 ; ++i){
            s1.push(i); 
        }
        s1.push(10);
    }
    catch(StackExecption& e){
        cout << e.what() << endl;
    }

    try{
        for (int i = 0; i < 15 ; ++i){
            s2.push("ashok " + to_string(i));
        }
    }
    catch(StackExecption& e){
        cout << e.what() << endl;
    }

    try{
        for (int i = 0; i < 15 ; ++i){
            s3.push('a' + i);
        }
    }
    catch(StackExecption& e){
        cout << e.what() << endl;
    }

    try{
        for (int i = 0; i < 15 ; ++i){
            cout << s1.pop() << " ";
        }
        cout << endl;
        cout << s1.pop() << endl;
    }
    catch(StackExecption& e){
        cout << e.what() << endl;
    }

    try{
        for (int i = 0; i < 15 ; ++i){
            cout << s2.pop() << " ";
        }
        cout << endl;
    }
    catch(StackExecption& e){
        cout << e.what() << endl;
    }

    try{
        for (int i = 0; i < 15 ; ++i){
            cout << s3.pop() << " ";
        }
        cout << endl;
    }
    catch(StackExecption& e){
        cout << e.what() << endl;
    }
    return 0;
}