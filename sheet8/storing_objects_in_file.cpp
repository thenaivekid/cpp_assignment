#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

class Account {
private:
    int accountNumber;
    string lastName;
    string firstName;
    double totalBalance;

public:
    Account() {}
    Account(int accNumber, const string& lName, const string& fName, double balance)
        : accountNumber(accNumber), lastName(lName), firstName(fName), totalBalance(balance) {}

    // Getters and setters
    int getAccountNumber() const { return accountNumber; }
    void setAccountNumber(int accNumber) { accountNumber = accNumber; }

    const string& getLastName() const { return lastName; }
    void setLastName(const string& lName) { lastName = lName; }

    const string& getFirstName() const { return firstName; }
    void setFirstName(const string& fName) { firstName = fName; }

    double getTotalBalance() const { return totalBalance; }
    void setTotalBalance(double balance) { totalBalance = balance; }

    // Display account information
    void display() const {
        cout << setw(15) << left << accountNumber
             << setw(15) << left << lastName
             << setw(15) << left << firstName
             << setw(15) << left << fixed << setprecision(2) << totalBalance << endl;
    }
};

class AccountFile {
private:
    fstream file;

public:
    AccountFile(const string& filename) {
        file.open(filename, ios::in | ios::out | ios::binary);
        if (!file) {
            cerr << "Error opening file." << endl;
            exit(1);
        }
    }

    ~AccountFile() {
        file.close();
    }

    void addAccount(const Account& account) {
        file.seekp((account.getAccountNumber() - 1) * sizeof(Account));
        file.write(reinterpret_cast<const char*>(&account), sizeof(Account));
        cout << "Account added successfully." << endl;
    }

    void updateAccount(int accountNumber, double newBalance) {
        Account account;
        file.seekg((accountNumber - 1) * sizeof(Account));
        file.read(reinterpret_cast<char*>(&account), sizeof(Account));

        if (account.getAccountNumber() != 0) {
            account.setTotalBalance(newBalance);

            file.seekp((accountNumber - 1) * sizeof(Account));
            file.write(reinterpret_cast<const char*>(&account), sizeof(Account));

            cout << "Account updated successfully." << endl;
        }
        else {
            cout << "Account not found." << endl;
        }
    }

    void deleteAccount(int accountNumber) {
        Account account;
        file.seekg((accountNumber - 1) * sizeof(Account));
        file.read(reinterpret_cast<char*>(&account), sizeof(Account));

        if (account.getAccountNumber() != 0) {
            account.setAccountNumber(0);

            file.seekp((accountNumber - 1) * sizeof(Account));
            file.write(reinterpret_cast<const char*>(&account), sizeof(Account));

            cout << "Account deleted successfully." << endl;
        }
        else {
            cout << "Account not found." << endl;
        }
    }

    void displayAccounts() {
        cout << setw(15) << left << "Account Number"
             << setw(15) << left << "Last Name"
             << setw(15) << left << "First Name"
             << setw(15) << left << "Total Balance" << endl;

        Account account;
        while (file.read(reinterpret_cast<char*>(&account), sizeof(Account))) {
            if (account.getAccountNumber() != 0) {
                account.display();
            }
        }
    }
};

int main() {
    AccountFile accountFile("accounts.dat");

    while (true) {
        cout << "1. Add Account" << endl;
        cout << "2. Update Account" << endl;
        cout << "3. Delete Account" << endl;
        cout << "4. Display Accounts" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int accNumber;
            string lastName, firstName;
            double balance;

            cout << "Enter account number: ";
            cin >> accNumber;

            cout << "Enter last name: ";
            cin.ignore();
            getline(cin, lastName);

            cout << "Enter first name: ";
            getline(cin, firstName);

            cout << "Enter total balance: ";
            cin >> balance;

            Account account(accNumber, lastName, firstName, balance);
            accountFile.addAccount(account);
            break;
        }
        case 2: {
            int accNumber;
            double newBalance;

            cout << "Enter account number to update: ";
            cin >> accNumber;

            cout << "Enter new total balance: ";
            cin >> newBalance;

            accountFile.updateAccount(accNumber, newBalance);
            break;
        }
        case 3: {
            int accNumber;
            cout << "Enter account number to delete: ";
            cin >> accNumber;

            accountFile.deleteAccount(accNumber);
            break;
        }
        case 4:
            accountFile.displayAccounts();
            break;
        case 5:
            return 0;
        default:
            cout << "Invalid choice. Try again." << endl;
        }

        cout << endl;
    }
}

