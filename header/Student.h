/*
Gisneiry Galan
 Oct 16th,2025
While doing the Student class I learned(or reinforced) about what should be inside a class and how to connect it with other files.
Which was also difficul because I'm still learning about it. Also, is a group assigment, so knowing what to code so it can
it can be good for my teammeates to continue (especially Kevin with the GPA calculation) was tricky.
*/


#include "Course.h"
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <numeric>

// !!STUDENT CLASS CREATED BY GISNEIRY!!

class Student {
private:
    // Declare private variables
    string name;
    vector<Course> courses;

public:
    // Constructor
    Student(const string& n = "") : name(n) {}

    // Add a course to the student's list
    void addCourse(const Course& c) {
        courses.push_back(c);
    }

    // Compute GPA
    double calculateGPA() const {
        double totalPoints = 0.0;
        int totalCredits = 0;

        for (const auto& c : courses) {
            totalPoints += c.getTotalPoints();
            totalCredits += c.getCredits();
        }

        if (totalCredits == 0) return 0.0;
        return totalPoints / totalCredits;
    }

    // Determine academic standing
    string getStanding() const {
        double gpa = calculateGPA();
        if (gpa >= 3.7) return "Dean's List";
        else if (gpa >= 2.0) return "Good Standing";
        else return "Probation :(";
    }

    // Display formatted transcript
    void printTranscript() const {
        cout << "\nStudent: " << name << "\n\n";
        cout << left << setw(20) << "Course Name"
             << setw(10) << "Credits"
             << setw(10) << "Grade"
             << setw(10) << "GradePts"
             << setw(10) << "TotalPts" << endl;
        cout << string(60, '-') << endl;

        for (const auto& c : courses) {
            c.display();
        }

        cout << string(60, '-') << endl;
        cout << "Total Credits: " << setw(5)
             << accumulate(courses.begin(), courses.end(), 0,
                           [](int sum, const Course& c) { return sum + c.getCredits(); })
             << endl;
        cout << "GPA: " << fixed << setprecision(2) << calculateGPA() << endl;
        cout << "Standing: " << getStanding() << endl;
    }
};

