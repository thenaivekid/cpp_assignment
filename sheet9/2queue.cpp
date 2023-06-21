// Write a class template for queue class. Assume the programmer using the queue won't make mistakes, like exceeding the capacity of the queue or trying to remove an item when the queue is empty. Define several queues of different data types and insert and remove data from them.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <class T>
class Queue{
    vector <T> v;

public:
    void push(T var){
        v.push_back(var);
    }

    T pop(){
        T temp = v.front();
        v.erase(v.begin());
        return temp;
    }
};

int main(){
    Queue <int> q1;
    Queue <string> q2;
    Queue <char> q3;
    for (int i = 0; i < 10 ; ++i){
        q1.push(i); 
    }

    q2.push("ashok");
    q2.push("is");
    q2.push("a");
    q2.push("good");
    q2.push("man");

    q3.push('a');
    q3.push('s');
    q3.push('h');
    q3.push('o');
    q3.push('k');

    for (int i = 0; i < 10 ; ++i){
        cout << q1.pop() << " ";
    }

    cout << endl;

    for (int i = 0; i < 5 ; ++i){
        cout << q2.pop() << " ";
    }

    cout << endl;

    for (int i = 0; i < 5 ; ++i){
        cout << q3.pop() << " ";
    }

    return 0;
}