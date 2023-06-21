// Write a program for transaction processing that write and read object randomly to and from a random access file so that user can add, update, delete and display the account information (account-number, last-name, first-name, total-balance).

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

const string FILENAME = "account.bin";

class Account{
private:
    static int account_number_counter;
    int account_number;
    string last_name;
    string first_name;
    double total_balance;

public:
    Account():account_number(account_number_counter++){}
    Account(string last_name_, string first_name_, double total_balance_) : account_number(account_number_counter++), last_name(last_name_), first_name(first_name_), total_balance(total_balance_) {}  

    ~Account(){}

    void set_account(){
        cout << "Enter last name: ";
        cin >> last_name;
        cout << "Enter first name: ";
        cin >> first_name;
        cout << "Enter total balance: (NRs)";
        cin >> total_balance;
        this->print();
    }

    void print() const {
        cout << setw(12) << account_number << " " << setw(12) << last_name << " " << setw(12) << first_name << " " << setw(12) << total_balance << endl;
    }

    void write_(){
        ofstream output_file(FILENAME, ios::binary | ios::app);
        if(!output_file){
            cerr << "Error opening output file" << endl;
            return;
        }
        output_file.write(reinterpret_cast<char*>(this), sizeof(Account));
        output_file.close();
        cout << "Written successfully" << endl;
    }

    static void update_(int account_number_){
        ofstream output_file(FILENAME, ios::binary);

        output_file.seekp((account_number_-1)*sizeof(Account));
        Account temp;
        temp.set_account();
        output_file.write(reinterpret_cast<char*>(&temp), sizeof(Account));
        output_file.seekp(0, ios::beg);
        output_file.close();
        cout << "Updated successfully" << endl;
    }

    static void delete_(int account_number_){
        vector <Account> accounts = read_(false);

        ofstream output_file(FILENAME, ios::binary);
        for (auto account: accounts){
            if (account.account_number != account_number_){
                output_file.write(reinterpret_cast<char*>(&account), sizeof(Account));
            }
        }
        output_file.close();
    }
    
    static vector <Account> read_(bool display = true){
        ifstream input_file(FILENAME, ios::binary);
        vector <Account> accounts;
        if(!input_file){
            cerr << "Error opening input file" << endl;
        } else {
            Account temp;
            if (display){
                cout << setw(12) << "Account no." << " " << setw(12) << "Last Name" << " " << setw(12) << "Firt Name" << " " << setw(12) << "Total balance" << endl;
            }
            while(input_file.read(reinterpret_cast<char*>(&temp), sizeof(Account))){
                if (display){
                    temp.print();
                }else{
                    accounts.push_back(temp);
                }
            }
        }
        input_file.close();

        return accounts;
    }
};

int Account::account_number_counter = 0;

int main(){
    Account a("Smith", "John", 100.0);
    Account b("Smith", "Jane", 200.0);
    // Account c;
    // c.set_account();
    Account d("Smith", "Jack", 100.0);
    Account e("Smith", "Jill", 200.0);
    a.write_();
    b.write_();
    d.write_();
    e.write_();
    // c.write_();
    Account::read_();
    Account::update_(2);
    Account::read_();
    // Account::delete_(3);
    // Account::read_();
    return 0;
}