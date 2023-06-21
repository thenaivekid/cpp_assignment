	
#include <iostream>

using namespace std;

template <class T>

class Stack

{

private:

    T st[100];

    int top;

public:

    Stack();

    void push(T var);

    T pop();

};

template <class T>

Stack<T>::Stack()

{

    top=-1;

}

template <class T>

void Stack<T>::push(T var)

{

    st[++top]=var;

}

template <class T>

T Stack<T>::pop()

{

    return st[top--];

}

int main()

{

    Stack<float> s1;

    s1.push(111.1F);

    s1.push(222.2F);

    s1.push(333.3F);

    cout<<"1 : "<<s1.pop()<<endl;

    cout<<"2 : "<<s1.pop()<<endl;

    cout<<"3 : "<<s1.pop()<<endl;

    Stack<long> s2;

    s2.push(123123123L);

    s2.push(234234234L);

    s2.push(345345345L);

    cout<<"1 : "<<s2.pop()<<endl;

    cout<<"2 : "<<s2.pop()<<endl;

    cout<<"3 : "<<s2.pop()<<endl;

    Stack <string> s3;
    s3.push("hello");
    s3.push("world");
    s3.push("!");
    cout<<"1 : "<<s3.pop()<<endl;
    cout<<"2 : "<<s3.pop()<<endl;
    cout<<"3 : "<<s3.pop()<<endl;

    return 0;

}