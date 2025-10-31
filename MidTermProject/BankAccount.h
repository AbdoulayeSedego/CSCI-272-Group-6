#include <iostream>
#include <vector>
#include <string>
using namespace std;


// Create a class BankAccount
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

    // deposit method that allow users to make a deposit
    void deposit(const double amount) {
        balance += amount; // For each instance the function is called, take the
                           // input and add it to the previous balance

        // Record this action to the 'history' vector
        history.push_back(ownerName + " made a deposit of $" + to_string(amount));
    }
    // withdraw method, for user to withdraw money from their current balance
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

    // get Balance method, allowing users to see their current balance
    double getBalance () const{
        return balance;
    }

    // display method that allow users to display their account info
    void display  () const{
        cout << "Account Owner Name: "<< ownerName <<endl;
        cout << "Acount Number     : "<< accountNumber <<endl;
        cout << "Current Balance   : $"<< balance <<endl;
    }
//showHistory method, to display the list of the transaction did by the user
    void showHistory() const {
        cout <<"Transaction History("<<history.size()<<")"<<endl;
        for (const auto& transaction : history){
            cout <<"-"<<transaction<<endl;
        }
    }

    /*
double getBalance() const; — Returns current balance
void display() const; — Prints account info
void showHistory() const; — Prints transaction history*/






};
