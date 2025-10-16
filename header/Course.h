// !!Course class & header created by Abdoulaye!!
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class Course {
private:
    string courseName;
    int creditHours;
    string letterGrade;
    // Missing variable to account for grade points
    // (added by Kevin)
    double gradePoints; // 4.0 conversion of letter grade

    // Helper function to convert letter grade to 4.0 scale
    // Could use a switch statement for this process, however, came
    // to the conclusion that this process would require converting
    // string values to char values or enum
    // Used conditionals

    // (added by Kevin)
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
    // default constructor
    // Initially declared with nothing; used an initializer list
    // as its better to initialize class variables than if they
    // were assigned in the { body }
    Course(): creditHours(0), gradePoints(0.0) {}

    // parameterized constructor
    Course(const string& name, int credits, const string& grade):
        courseName(name), creditHours(credits), letterGrade(grade) {
            gradePoints = gradeToPoints(grade);
    }

    // Missing setters and getters
    // added by Kevin
    string getName() const {
        return courseName;
    }

    int getCredits() const {
        return creditHours;
    }

    string getLetterGrade() const {
        return letterGrade;
    }

    double getGradePoints() const {
        return gradePoints;
    }

    double getTotalPoints() const {
        return gradePoints * creditHours;
    }


    // Added formatting for visual purposes (good-looking table == good grade :) )
    // Initialized by Abdoulaye;
    void display() const {
        cout << left << setw(20) << courseName
        << setw(10) << creditHours
        << setw(10) << letterGrade
        << setw(10) << fixed << setprecision(2) << gradePoints
        << setw(10) << fixed << setprecision(2) << getTotalPoints()
        << endl;
    }

};
