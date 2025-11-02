#include "BankAccount.h"
/**********************************************************
 *  Bank Account System - Group 6
 *  Authors:
 *    • Abdoulaye Sedego 
 *    • Galan Matias, Gisneiry
 *    • Silva Jimenez, Kevin
 *  Date: 2025-11-02
 * GitHub Repository: https://github.com/AbdoulayeSedego/CSCI-272-Group-6.git
 **********************************************************/

 // main function set up by Gisneiry and Kevin
int main() {

    string userInput;
    // Ask user for their information
    cout <<"==== Banking System ==="<<endl;
    cout << "Enter your name: ";
    getline(cin, userInput);
    // Assign name to variable
    string ownerName = userInput;

    // Ask user for an account number
    cout << "Enter an account number: ";
    int accountNumber; // 
    // INPUT VALIDATION START by kevin
    while (true) {
        if (cin >> accountNumber) { // Check cin.fail()
            if (accountNumber > 0) { // Reject nonpositive values
                break; // Valid input, exit loop
            } else {
                cout << "ERROR: INVALID ACCOUNT NUMBER! Must be greater than 0." << endl;
            }
        } else {
            cout << "ERROR: INVALID ACCOUNT NUMBER! Please enter a numeric value." << endl;
            cin.clear(); //Clear the fail state
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Flush invalid input
        cout << "Enter an account number: "; // Re-prompt
    }
    // INPUT VALIDATION END HERE

    // Ask the user for an initial balance
    cout << "Enter your initial deposit (>0) $: ";
    double initialDeposit; // 
    // INPUT VALIDATION START  by Kevin 
    while (true) {
        if (cin >> initialDeposit) { // Check cin.fail()
            if (initialDeposit > 0) { //Reject non-positive values
                break; // Valid input, exit loop
            } else {
                cout << "ERROR: INVALID DEPOSIT! Must be greater than 0." << endl;
            }
        } else {
            cout << "ERROR: INVALID DEPOSIT! Please enter a numeric value." << endl;
            cin.clear(); //Clear the fail state
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Flush invalid input
        cout << "Enter your initial deposit (>0) $: "; // Re-prompt for user, when invalid input
    }
    // INPUT VALIDATION END 
    
    // Create a BankAccount object with the parameters by Gisneiry
    BankAccount myAccount(ownerName, accountNumber, initialDeposit);

    //new line for clarity, menu implementation start here by Gisneiry
    cout <<endl;
    int choice ;
    do {
    cout << "Menu: " << endl;
    cout << "1) Deposit." << endl ;
    cout << "2) Withdraw. " << endl ;
    cout << "3) Show Balance." << endl ;
    cout << "4) Show Account Info." << endl ;
    cout << "5) Show Transaction History." << endl ;
    cout << "6) Exit." << endl ;
    cout << "Choose option: " << endl;
    // Input validation by kevin
    while (!(cin >> choice)) { // Check cin.fail()
        cout << "ERROR: INVALID CHOICE! Please enter a numeric value." << endl;
        cin.clear(); // Clear the fail state
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ADDED: Flush invalid input
        cout << "Choose option: "; // Re-prompt in case user enter wrong input
    }
    // end of Input validation for choice

    // switch to call the functions for each option on the menu by Gisneiry
    switch(choice){
        case 1:{ // case handle by Abdoulaye
            double depositAmount;
            cout << "Enter the amount to deposit $: ";
            // input validation for deposit
            while (true) {
                if (cin >> depositAmount) { //  Check cin.fail()
                    if (depositAmount > 0) { //  Reject non-positive values
                        myAccount.deposit(depositAmount);
                        break; // Valid input, exit loop
                    } else {
                        cout << "ERROR: INVALID DEPOSIT AMOUNT! Must be greater than 0." << endl;
                    }
                } else {
                    cout << "ERROR: INVALID DEPOSIT AMOUNT! Please enter a numeric value." << endl;
                    cin.clear(); //  Clear the fail state
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Flush invalid input
                cout << "Enter the amount to deposit $: "; // // case handle by Gisneiry
            }
            // end input validation for deposite
            break;
        }
        case 2: { // case handle by Abdoulaye
            double withdrawAmount; 
            cout << "Enter the amount to withdraw $: ";
            // INPUT VALIDATION for withdraw
            while (true) {
                if (cin >> withdrawAmount) { //Check cin.fail()
                    if (withdrawAmount > 0) {//Reject non-positive values
                        // store withdraw method return result into success variable
                        bool success = myAccount.withdraw(withdrawAmount);
                        if (success == true) {
                            cout << "withdrawn $:" <<withdrawAmount<<endl;
                        }
                        break; // Valid input, exit loop
                    } else {
                        cout << "ERROR: INVALID WITHDRAW AMOUNT! Must be greater than 0." << endl;
                    }
                } else {
                    cout << "ERROR: INVALID WITHDRAW AMOUNT! Please enter a numeric value." << endl;
                    cin.clear(); //Clear the fail state
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Flush invalid input by user
                cout << "Enter the amount to withdraw $: "; // Re-prompt, when user enter invalid input
            }
            // INPUT VALIDATION END 
            break;
        }
        case 3: // case handle by Abdoulaye
             cout << "Balance: $" << fixed << setprecision(2) << myAccount.getBalance() << endl;
            break;
        case 4: // case handle by Gisneiry
            myAccount.display();
            break;
        case 5: // case handle by Gisneiry
            myAccount.showHistory();
            break;
        case 6:
            cout << "Goodbye." << endl; // exit loop
            break;
        default:
            cout << "Invalid choice, try again." << endl; // default, in case user enters invalid input 
    }

    } while (choice != 6); // loop ends when user enters 6 (exit) switch handle by Gisneiry

    // Terminate program
    return 0;

}

/*
====== Abdoulaye Sedego ======
Abdoulaye : I was taked to creat the method(getBalance, display and showHistory) and to handle the cases
in the switch, to make sure than when I case is selected it handle the proper method. I have learn once again more
about OOP in C++ which were difficult for me at the beginning of the chapter about OOP. I have learn
about advanced git command when we run into an merging issue, one teammate work on the code localy without 
pulling the update code from the repo, when I merge the pull request it changed the code to a non-working
version, I had to use git checkout to reverse it and then reimplement the added code. Now my teammat and I know that before working
on out code localy we need to git pull the update code from the repo.
I improved my debugging skill by reading and debbuging my teammate code as I was tasked to put everything 
together before submiting, to be honest I enjoy working with my team, we learn a lot about each other.
and finally I learn more about Object member initialization, which was tricky for me, I had to research to find 
which implementation was effective and cleaner to read. And according to my researches the most practical is this one recommended by modern C++:

 == BankAccount(const string &ownerName, const int accountNumber, const double balance) 
    : ownerName(ownerName), accountNumber(accountNumber), balance(balance) { } ==

    and this one the least practical :
== BankAccount(const std::string &ownerName, const int accountNumber, const double balance) {
        this->ownerName = ownerName;
        this->accountNumber = accountNumber;
        this->balance = balance; ==
*/

 /*
 ===== Galan Matias, Gisneiry =====
  Gisneiry: I was asked to do the menu loop. I used a do while loop with 
  a  switch statement inside in order to get the menu to repeat. Doing that 
  was straightforward. However, I struggled and/or was confused about the logic 
  inside the switch.I had to call the functions for each case, but I felt like 
  “I was missing something “, and the code did not run properly, for that I reached 
  to my teammates they explained and helped with the  “cout<<“ inputs and missing 
  logic. I learned  about how to implement logic to call the functions properly.Also,
   I learned from my teammate Abdoulaye how to push/pull code to GitHub using the terminal
 */
//==================================
/*
===== Silva Jimenez, Kevin =====
Kevin: I was tasked with creating the BankAccount class (up to the withdrawal function)
 along with implementing input validation where it was necessary. Creating the constructor,
deposit and withdrawal function were straightforward as no complicated instructions were needed.
However I did encounter some issues when tackling input validation for certain parameters - 
for instance, when it came to an int or double type, once must consider whether the user is going
to enter empty space, string, and or a negative number (it’s possible the user could also enter a 
combination of the two “123abc”). With that considered, I created a while loop which 
is set to ‘true’ by default until it can confirm that all prerequisites are met; which, 
in that case, the loop will break. When making final touches, I’ve encountered an issue when it 
came to ‘using namespace std;’ for some reason, the IDE would throw a “compilation error” though 
I couldn’t find the exact reason, it wasn’t until I removed ‘using namespace std;’ from the header 
file that the issue was resolved.
 
 */

