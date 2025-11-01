#include <iostream>
#include <vector>
#include <string>
#include <iomanip>    
#include <sstream>
using namespace std;

/* --------------------------------------------------------------
   Helper Function: format a double as "$xxxx.xx"
   e.g. 1234.5 → "1234.50"
   -------------------------------------------------------------- */
string money(double amount)
{
    stringstream ss;
    ss << fixed << setprecision(2) << amount;
    return "$" + ss.str();
}

// Create a class BankAccount
class BankAccount {
private:
    string ownerName; // name of the account holder
    int accountNumber; // account number associated with user
    double balance; // Account balance; can be adjusted
    vector <string> history; // Account history
public:
    // Create a constructor to initialize a BankAccount object
    BankAccount(const string &ownerName, const int accountNumber, const double balance) : 
      ownerName(ownerName), 
      accountNumber(accountNumber), 
      balance(balance)
      {
        // Announce
        cout << "Account created successfully! " << endl;
        // Record account creation
        history.push_back("Account created with initial deposit: " + money(balance));
    };

    // deposit method that allow users to make a deposit
    void deposit(const double amount) {
        balance += amount; // For each instance the function is called, take the
                           // input and add it to the previous balance
        // Record this action to the 'history' vector
        cout <<"Deposited: "<< money(amount) <<endl;;
        history.push_back(ownerName + " made a deposit of " + money(amount));
    }
    // withdraw method, for user to withdraw money from their current balance
    bool withdraw(const double amount) {
        // Conditional to confirm whether the input is valid
        // If the amount exceeds the balance OR the amount entered
        // is less than or equal to zero -> a withdrawal is not possible
        if (amount <= 0) {
            // Invalid Input
            return false;
        } else if (amount > balance) { // return false if the balance is insufisent 
            cout << "Insufficient funds" << endl; 
            return false;
        } else {
            balance -= amount; // remove the amount from balance
            history.push_back(ownerName + " made a withdraw of " + money(amount));

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
        cout << "Current Balance   : "<< money(balance) <<endl;
    }
//showHistory method, to display the list of the transaction did by the user
    void showHistory() const {
        cout <<"Transaction History("<<history.size()<<")"<<endl;
        for (const auto& transaction : history){
            cout <<"-"<<transaction<<endl;
        }
    }

};
