#ifndef COURSE_H
#define COURSE_H
// !!Course class & header created by Abdoulaye!!
/*
Abdoulaye Sedego
Oct 17th, 2025
While working on the project, I have learn a lot about team work and code collaboration,
how to read other people code and write on top of it without breaking it. I have practice and learn more 
about classes (OOP) in C++, I enjoyed working on the EXTRA CREDIT sorting function.
*/

#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class Course {
private:
    string courseName;
    int creditHours;
    string letterGrade;

    double gradePoints; // 4.0 conversion of letter grade

    // Helper function to convert letter grade to 4.0 scale
    // Could use a switch statement, but used conditionals
    double gradeToPoints(const string& grade) const {

        if (grade == "A") {
            return 4.0;
        } else if (grade == "A-") {
            return 3.7;
        } else if (grade == "B+") {
            return 3.3;
        } else if (grade == "B") {
            return 3.0;
        } else if (grade == "B-") {
            return 2.7;
        } else if (grade == "C+") {
            return 2.3;
        } else if (grade == "C") {
            return 2.0;
        } else if (grade == "C-") {
            return 1.7;
        } else if (grade == "D") {
            return 1.0;
        } else {
            return 0.0; // Failing grade OR invalid input
        }
    }

public:
    // Default constructor
    Course(): creditHours(0), gradePoints(0.0) {}

    // Parameterized constructor
    Course(const string& name, int credits, const string& grade):
        courseName(name), creditHours(credits), letterGrade(grade) {
            gradePoints = gradeToPoints(grade);
    }

    // Setters and Getters added by Kevin
    string getName() const { return courseName; }
    int getCredits() const { return creditHours; }
    string getLetterGrade() const { return letterGrade; }
    double getGradePoints() const { return gradePoints; }
    double getTotalPoints() const { return gradePoints * creditHours; }

    // Added formatting for visual purposes
    // Initialized by Abdoulaye
    void display() const {
        cout << left << setw(20) << courseName
             << setw(10) << creditHours
             << setw(10) << letterGrade
             << setw(10) << fixed << setprecision(2) << gradePoints
             << setw(10) << fixed << setprecision(2) << getTotalPoints()
             << endl;
    }
};

#endif // COURSE_H
