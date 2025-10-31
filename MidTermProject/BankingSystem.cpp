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

    // Test the code, no actual data, only for testing purpose only
    
    myAccount.deposit(500.0);
    myAccount.withdraw(200.0);

    //end of test
    
    cout << "\nCurrent Balance: $" << myAccount.getBalance() << endl;  // Now works correctly!
    
    myAccount.display();
    myAccount.showHistory();
    do {
    int choice ;
    cout << "Menu: " << endl;
    cout << "1) Deposit." << endl ;
    cout << "2) Withdraw. " << endl ;
    cout << "3) Show Balance." << endl ;
    cout << "4) Show Account Info." << endl ;
    cout << "5) Show Transaction History." << endl ;
    cout << "6) Exit." << endl ;
    cout << "Choose option: " << endl;
    cin >> choice;

    // switch to call the functions for each option on the menu
    switch(choice){
        case 1:
            myAccount.deposit(); 
            break;
        case 2:
            myAccount.withdraw();
            break;
        case 3:
            myAccount.getBalance();
            break;
        case 4:
            myAccount.display();
            break;
        case 5:
            myAccount.showHistory();
            break;
        case 6:
            cout << "Goodbye." << endl; // exit loop
            break;
        default:
            cout << "Invalid choice, try again." << endl; // default, in case user enters invalid input 
    }

} while (choice != 6); // loop ends when user enters 6 (exit)




    // Terminate
    return 0;



}


