#include "BankAccount.h"
#include <istream>
#include <limits> // for numeric limits

// isValid(): function used to determine if a given input is valid
bool isValid(const std::string &input) {

    // Begin by checking if the input is empty
    if (input.empty()) {
        return false;
    } else { // otherwise return true
        return true;
    }

}

int main() {

    // Declare necessary variables
    std::string ownerName, userInput;
    int accountNumber;
    double balance;

    // Ask user for their information
    std::cout <<"==== Banking System ==="<< std::endl;
    std::cout << "Enter your name: ";
    getline(std::cin, ownerName);

    // Input validation: consider for the possibility that user
    //                   can enter empty space as their name
    while (!isValid(ownerName)) {
        std::cout << "ERROR: INVALID ACCOUNT NAME!" << std::endl;
        std::cout << "Enter your name: ";
        getline(std::cin, ownerName);
    }
    // ----------------------------------------------------------

    // Ask user for an account number
    std::cout << "Enter an account number: ";
    // Input validation: consider that the user can either enter whitespace or
    //                   a negative number as their input.
    while (true) {

        // Conditional
        if (std::cin >> accountNumber) { // First, confirm if the input is acceptable
            if (accountNumber > 0) { // If valid input, check to see if the input is greater
                                     // than 0
                break;
            } else {
                std::cout << "ERROR: INVALID ACCOUNT NUMBER!" << std::endl; // Otherwise the input was invalid
            }
        } else {
            std::cout << "ERROR: INVALID ACCOUNT NUMBER!" << std::endl;
            std::cin.clear(); // RESET THE FAIL STATE
        }

        // Ensure to 'flush' any bad inputs before re-trying
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Enter an account number: ";
    }
    // -------------------------------------------------------
    // Ask the user for an initial balance
    std::cout << "Enter an initial deposit (>0) $: ";
    while (true) {
        if (std::cin >> balance) { // Check if assignment can be made
            if (balance > 0) { // Check if the input is greater than 0
                break; // if both checks are valid: break loop
            } else { // In the condition that balance < 0
                std::cout << "ERROR: INVALID BALANCE!" << std::endl;
            }
        } else {
            std::cout << "ERROR: INVALID BALANCE!" << std::endl;
            std::cin.clear();

        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Enter an initial deposit $: ";
    }

    // Create a BankAccount object using the parameters the user defined
    BankAccount account(ownerName, accountNumber, balance);

    //new line for clarity
    std::cout << std::endl;
    int choice ;
    do {
        std::cout << "1) Deposit\n"
          << "2) Withdraw\n"
          << "3) Show Balance\n"
          << "4) Show Account Info\n"
          << "5) Show Transaction History\n"
          << "6) Exit\n";
        std::cout << "Choose option: " << std::endl;
        std::cin >> choice;

        // switch to call the functions for each option on the menu
        switch(choice){
            case 1:{
                std::cout << "Enter the amount to deposit $: \n";
                std::cin >> userInput;
                int depositAmount = stod(userInput);
                account.deposit(depositAmount);
                break;
            }
            case 2: {
                std::cout << "Enter the amount to withdraw $: \n";
                std::cin >> userInput;
                // take user input as a string and convert it to double
                int withdrawAmount = stod(userInput);
                // store withdraw method return result into success variable
                bool success = account.withdraw(withdrawAmount);
                if (success == true) {
                    std::cout << "withdrewn $:" <<withdrawAmount<< std::endl;
                }
                break;
            }
            case 3:
                std::cout << "Balance: $" << std::fixed << std::setprecision(2) << account.getBalance() << std::endl;
                break;
            case 4:
                account.display();
                break;
            case 5:
                account.showHistory();
                break;
            case 6:
                std::cout << "Goodbye." << std::endl; // exit loop
                break;
            default:
                std::cout << "Invalid choice, try again." << std::endl; // default, in case user enters invalid input
        }

    } while (choice != 6); // loop ends when user enters 6 (exit)

    // Terminate
    return 0;



}
