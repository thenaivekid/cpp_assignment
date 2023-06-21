#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

const string FILENAME = "account.bin";

class Account {
private:
    int account_number;
    string last_name;
    string first_name;
    double total_balance;

public:
    Account() {}
    Account(int account_number_, string last_name_, string first_name_, double total_balance_)
        : account_number(account_number_), last_name(last_name_), first_name(first_name_), total_balance(total_balance_) {}

    void set_account() {
        cout << "Enter account number: ";
        cin >> account_number;
        cout << "Enter last name: ";
        cin >> last_name;
        cout << "Enter first name: ";
        cin >> first_name;
        cout << "Enter total balance (NRs): ";
        cin >> total_balance;
        this->print();
    }

    void print() const {
        cout << setw(12) << account_number << " " << setw(12) << last_name << " " << setw(12) << first_name << " " << setw(12) << total_balance << endl;
    }

    void write_() {
        ofstream output_file(FILENAME, ios::binary | ios::app);
        if (!output_file) {
            cerr << "Error opening output file" << endl;
            return;
        }
        output_file.write(reinterpret_cast<char*>(this), sizeof(Account));
        output_file.close();
        cout << "Written successfully" << endl;
    }

    static vector<Account> read_() {
        ifstream input_file(FILENAME, ios::binary);
        vector<Account> accounts;
        if (!input_file) {
            cerr << "Error opening input file" << endl;
        }
        else {
            Account temp;
            cout << setw(12) << "Account no." << " " << setw(12) << "Last Name" << " " << setw(12) << "First Name" << " " << setw(12) << "Total balance" << endl;
            while (input_file.read(reinterpret_cast<char*>(&temp), sizeof(Account))) {
                temp.print();
                accounts.push_back(temp);
            }
        }
        input_file.close();

        return accounts;
    }

    static void delete_(int account_number_) {
        ifstream input_file(FILENAME, ios::binary);
        ofstream temp_file("temp.bin", ios::binary);

        if (!input_file || !temp_file) {
            cerr << "Error opening file" << endl;
            return;
        }

        Account temp;
        bool found = false;

        while (input_file.read(reinterpret_cast<char*>(&temp), sizeof(Account))) {
            if (temp.account_number != account_number_) {
                temp_file.write(reinterpret_cast<char*>(&temp), sizeof(Account));
            }
            else {
                found = true;
            }
        }

        input_file.close();
        temp_file.close();

        if (!found) {
            cerr << "Account with account number " << account_number_ << " was not found." << endl;
            remove("temp.bin");
            return;
        }

        remove(FILENAME.c_str());
        rename("temp.bin", FILENAME.c_str());

        cout << "Account with account number " << account_number_ << " has been deleted." << endl;
    }

    static void update_(int account_number_) {
        ifstream input_file(FILENAME, ios::binary);
        ofstream temp_file("temp.bin", ios::binary);

        if (!input_file || !temp_file) {
            cerr << "Error opening file" << endl;
            return;
        }

        Account temp;
        bool found = false;

        while (input_file.read(reinterpret_cast<char*>(&temp), sizeof(Account))) {
            if (temp.account_number == account_number_) {
                found = true;
                temp.set_account();
                temp_file.write(reinterpret_cast<char*>(&temp), sizeof(Account));
            }
            else {
                temp_file.write(reinterpret_cast<char*>(&temp), sizeof(Account));
            }
        }

        input_file.close();
        temp_file.close();

        if (!found) {
            cerr << "Account with account number " << account_number_ << " was not found." << endl;
            remove("temp.bin");
            return;
        }

        remove(FILENAME.c_str());
        rename("temp.bin", FILENAME.c_str());

        cout << "Account with account number " << account_number_ << " has been updated." << endl;
    }
};

int main() {
    Account a(1, "Smith", "John", 100.0);
    Account b(2, "Smith", "Jane", 200.0);
    Account c;

    a.write_();
    b.write_();
    c.set_account();
    c.write_();

    vector<Account> accounts = Account::read_();
    for (const auto& account : accounts) {
        account.print();
    }

    int accountToDelete;
    cout << "Enter the account number to delete: ";
    cin >> accountToDelete;
    Account::delete_(accountToDelete);

    int accountToUpdate;
    cout << "Enter the account number to update: ";
    cin >> accountToUpdate;
    Account::update_(accountToUpdate);

    return 0;
}
