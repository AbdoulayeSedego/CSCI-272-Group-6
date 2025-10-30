#include "BankAccount.h"

// Note: THIS IS NOT THE FINAL PROGRAM!! This is just a space to test the class
int main() {

    string userInput;

    // Ask user for their information
    cout << "Enter your name: ";
    getline(cin, userInput);

    // Note: The user can enter blank space
    // Add input validation to avoid empty space!!

    // Assign name to variable
    string ownerName = userInput;

    // Ask user for an account number
    cout << "Enter an account number: ";
    // Since an account number does not need white-space
    // a simple cin is acceptable
    cin >> userInput;

    // Since 'userInput' is a string by default, we will need to type-cast
    // it to the right type (int)

    // Like the previous assignment, be sure the user enters a valid input!!
    int accountNumber = stoi(userInput);

    // Ask the user for an initial balance
    cout << "Enter your initial deposit $: ";
    cin >> userInput;

    // Note: Ensure the user enters an amount greater than 0! (Input validation)
    double initialDeposit = stod(userInput);

    // Create a BankAccount object with the parameters
    BankAccount myAccount(ownerName, accountNumber, initialDeposit);

    // Terminate
    return 0;



}
