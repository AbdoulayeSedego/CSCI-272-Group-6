#include "header/Course.h"
#include "header/Student.h"
#include <iostream>
#include <string>
#include <limits>
#include <cctype>
using namespace std;

// Main function created by Kevin
// While not asked in the assignment
// adding input validation ensures the user
// does not enter invalid inputs
// This function returns a boolean value
// either true or false depending on the input
// parameters
bool isValidName(const string& name) {

    // Ensure that the user doesn't enter empty space
    if (name.empty()) return false;

    // declare variable that will be used to check if the input has a letter
    bool hasLetter = false;

    // Using a for-loop, treat the name as an array of characters
    // ex. Jane Doe = [J, a, n, e, , D, o, e]
    // iterate through each index
    for (char ch : name) {
        if (isalpha(static_cast<unsigned char>(ch))) {
            hasLetter = true;
        } else if (isspace(static_cast<unsigned char>(ch))) {
            continue; // continue iterating if these conditions are true
        } else {
            return false; // otherwise return false and terminate
        }
    }
    return hasLetter;
}

// Similar to name input, ensure that the letter grade is inserted correctly
bool isValidGrade(const string& grade) {
    // Initialize valid inputs in an array
    string validGrades[] = {"A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F"};

    // if the user's input matches that of the defined array, return true;
    // otherwise, return false and prompt the user to try again
    for (auto& g : validGrades) {
        if (grade == g) return true;
    }
    return false;
}

int main() {

    // Prompt user to enter their name
    string studentName;
    cout << "Enter your full name: ";
    getline(cin, studentName);

    // Input validation: if user inserts invalid input
    while (!isValidName(studentName)) {
        cout << "Invalid name. Please enter letters and spaces only: ";
        getline(cin, studentName);
    }

    // Once the user enters a valid name, create an object using the defined class
    Student student(studentName);

    // Prompt user to enter the number of courses they wish to report
    int numCourses;
    cout << "Enter number of courses (1–10): ";

    // Input validation: check if within limits
    while (!(cin >> numCourses) || numCourses < 1 || numCourses > 10) {
        cout << "Invalid number. Enter a value between 1 and 10: ";
        cin.clear(); // clear new line
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore new line
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear newline before next getline

    // For-loop to allow user to enter the information
    for (int i = 0; i < numCourses; i++) {
        // ------------VISUAL PURPOSE ONLY! --------------------
        cout << "\n--- Course " << i + 1 << " ---" << endl;
        // -----------------------------------------------------
        string courseName, grade;
        int credits;

        // Prompt user to enter information regarding course
        cout << "Enter course name: ";
        getline(cin, courseName);

        // Get credit hours
        cout << "Enter credit hours: ";

        // Input validation: ensure user doesn't enter a negative integer
        while (!(cin >> credits) || credits < 0) {
            cout << "Invalid input. Enter a positive integer: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Prompt user for their grade in the class (letter format only!)
        cout << "Enter letter grade (A, A-, B+, B, B-, C+, C, C-, D, F): ";
        cin >> grade;

        while (!isValidGrade(grade)) {
            cout << "Invalid grade. Try again: ";
            cin >> grade;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear newline

        // Create a new object with the inputs provided
        Course c(courseName, credits, grade);
        student.addCourse(c);
    }

    // Print the transcript
    student.printTranscript();

    cout << "\nProgram complete.\n";
    return 0;
}
