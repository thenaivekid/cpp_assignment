#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int lexp = 100; 
    int cexp = 200;
    int texp = 300;

    cout << "LODGING: " << setw(10) << lexp << endl;
    cout << "CLOTHING: " << setw(9) << cexp << endl;
    cout << "TRAVELING: " << setw(8) << texp << endl;


    return 0;
}
