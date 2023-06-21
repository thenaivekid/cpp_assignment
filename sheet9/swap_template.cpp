#include <iostream>
#include <string>
using namespace std;

// template <class T>
template <typename T>
void swap_(T &x, T &y){
    T temp = x;
    x = y;
    y = temp;
}

int main(){
    int a = 9;
    int b = 6;
    cout << a << " " << b << endl;
    swap_(a,b);
    cout << a << " " << b << endl;

    char c = 'a';
    char d = 's';
    cout << c << " " << d << endl;
    swap_(c, d);
    cout << c << " " << d << endl;

    string e = "hello";
    string f = "world";
    cout << e << " " << f << endl;
    swap_(e, f);
    cout << e << " " << f << endl;
}