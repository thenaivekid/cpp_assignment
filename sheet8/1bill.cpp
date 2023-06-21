// Write a program to demonstrate the use of different ios flags and functions to format the output. Create a program to generate the bill invoice of a department store by using different formatting.

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class InvoiceItem {
    private:
        string name;
        int quantity;
        double price;

    public:
        InvoiceItem(string name_, int quantity_, double price_) : name(name_), quantity(quantity_), price(price_) {}

        void print() const {
            cout << setw(25) << name << setw(10) << quantity << setw(10) << price << setw(10) << quantity * price << endl;
        }

        float total_price() const {
            return quantity * price;
        }

    ~InvoiceItem() {}
};


int main(){
    InvoiceItem item1("Milk", 2, 2.5);  
    InvoiceItem item2("cholcolate ice cream", 1, 5.5);

    cout << setw(25) << "Name" << setw(10) << "Quantity" << setw(10) << "Price" << setw(10) << "Total" << endl;
    item1.print();
    item2.print();

    cout.setf(ios::showpos);
    float total_price = item1.total_price() + item2.total_price();
    float discount = total_price * 0.1;
    cout << setw(45) << "Total" << setw(10) << setprecision(2) << total_price << endl;
    cout << setw(45) << "Discount" << setw(10) << setprecision(2) << discount << endl;
    cout << setw(45) << "Total"<< setw(10) << setprecision(2) << total_price - discount<< endl;


}