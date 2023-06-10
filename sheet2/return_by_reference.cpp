#include <iostream>

using namespace std;

int x = 5;
int & asignx()
{
    return x;
}

int main()
{
    asignx() = 7;
    cout << x;
}