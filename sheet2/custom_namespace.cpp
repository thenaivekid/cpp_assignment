#include <iostream>

namespace nsn
{
    int item = 4;

    void show_item(int n)
    {
        std::cout << n << std::endl;
    }
}

int main(){
    // cout << "LODGING" << lexp << endl;
    // cout << "CLOTHING" << cexp << endl;
    using namespace nsn;
    // using namespace std; //can't use two namespaces simultaneously
    std::cout << item << std::endl;
    show_item(5);
}