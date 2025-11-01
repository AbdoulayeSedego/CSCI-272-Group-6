#include <iomanip>
#include <iostream>
#include <vector>


// Create a class as defined in the assignment
class BankAccount {
private:
    std::string ownerName; // name of the account holder
    int accountNumber; // account number associated with user
    double balance; // Account balance; can be adjusted
   std:: vector <std::string> history; // Account history
public:
    // Create a constructor to initialize a BankAccount object
    BankAccount(const std::string &ownerName, const int accountNumber, const double balance) {
        this->ownerName = ownerName;
        this->accountNumber = accountNumber;
        this->balance = balance;

        // Announce
        std::cout << "Account created successfully! " << std::endl;
        // Record account creation
        history.push_back("Account created for " + ownerName +
                  " (Account #" + std::to_string(accountNumber) +
                  ") with initial balance: $" + std::to_string(balance));
    };

    // Include functions that were specified in the assignment
    void deposit(const double amount) {
        balance += amount; // For each instance the function is called, take the
                           // input and add it to the previous balance

        // Record this action to the 'history' vector
        history.push_back(ownerName + " made a deposit of $" + std::to_string(amount));
    }

    bool withdraw(const double amount) {
        // Conditional to confirm whether the input is valid

        // If the amount exceeds the balance OR the amount entered
        // is less than or equal to zero -> a withdrawal is not possible
        if (amount <= 0) {
            // Invalid Input
            return false;
        } else if (amount > balance) {
            std::cout << "Insufficient balance" << std::endl;
            return false;
        } else {
            balance -= amount; // remove the amount from balance
            history.push_back(ownerName + " made a withdrawal of $" + std::to_string(amount));

            // Special case: the account balance reaches $0
            if (balance == 0) {
                std::cout << "Balance is now zero" << std::endl;
            }

            return true;
        }

    }

    // getBalance() method allows for the user to see their current balance
    double getBalance() const {
        return balance;
    }

    // display() method allows for the user to see their account information
    void display () const {
        std::cout << "Account Owner: " << ownerName << std::endl;
        std::cout << "Account Number: " << accountNumber << std::endl;

        // Print balance with decimal precision of 2
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Balance $: " << balance << std::endl;
    }

    // showHistory() method allows for the user to see their transaction, deposit, and
    // withdrawal history
    void showHistory () const {

        for (const auto & i : history) {
            std::cout << i << std::endl;
        }
    }

};
