#include <iostream>
#include <string>
#include <vector>
using namespace std;

class B;

class A{
    int a = 5;
    
    friend class B;

public:
    void print(){
        cout << a << endl;
    }
};

class B{
    int b = 10;

public:
    void print(){
        cout << b << endl;
    }

    int sum(A a){
        return a.a + b;
    }

    void set_a(A& a){
        a.a = 20;
    }

    // does not work
    // void set_a(A a){
    //     a.a = 20;
    // }
};

int main(){
    A a;
    B b;
    a.print();
    b.print();
    cout << b.sum(a) << endl;
    b.set_a(a);
    a.print();
    return 0;
}