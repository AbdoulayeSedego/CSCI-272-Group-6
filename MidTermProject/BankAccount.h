#include <iostream>
#include <vector>
using namespace std;


// Create a class as defined in the assignment
class BankAccount {
private:
    string ownerName; // name of the account holder
    int accountNumber; // account number associated with user
    double balance; // Account balance; can be adjusted
    vector <string> history; // Account history
public:
    // Create a constructor to initialize a BankAccount object
    BankAccount(const string &ownerName, const int accountNumber, const double balance) {
        this->ownerName = ownerName;
        this->accountNumber = accountNumber;
        this->balance = balance;

        // Announce
        cout << "Account created successfully! " << endl;
        // Record account creation
        history.push_back("Account created for " + ownerName + " with account number: " + to_string(accountNumber));
    };

    // Include functions that were specified in the assignment
    void deposit(const double amount) {
        balance += amount; // For each instance the function is called, take the
                           // input and add it to the previous balance

        // Record this action to the 'history' vector
        history.push_back(ownerName + " made a deposit of $" + to_string(amount));
    }

    bool withdraw(const double amount) {
        // Conditional to confirm whether the input is valid

        // If the amount exceeds the balance OR the amount entered
        // is less than or equal to zero -> a withdrawal is not possible
        if (amount <= 0) {
            // Invalid Input
            return false;
        } else if (amount > balance) {
            cout << "Insufficient balance" << endl;
            return false;
        } else {
            balance -= amount; // remove the amount from balance
            history.push_back(ownerName + " made a withdraw of $" + to_string(amount));

            // Special case: the account balance reaches $0
            if (balance == 0) {
                cout << "Balance is now zero" << endl;
            }

            return true;
        }

    }






};
