#include "header/Course.h"
#include "header/Student.h"
#include <iomanip>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

// Constructor
Course::Course(string name, int credits, string grade) {
    courseName = name;
    creditHours = credits;
    letterGrade = grade;
}

// Destructor
Course::~Course() {
    cout << "Class destroyed. "<< endl;
}

int main() {
    int numberofcourses;
    cout << "Enter the number of courses: ";
    cin >> numberofcourses;
    cin.ignore(); // clear newline before getline

    vector<Course> totalCourses;
    totalCourses.reserve(numberofcourses);

    for (int i = 0; i < numberofcourses; i++) {
        string name;
        int creditsHours;
        string letterGrade;

        cout << "\nEnter course name: ";
        getline(cin, name);

        cout << "Enter credit hours: ";
        cin >> creditsHours;

        cout << "Enter letter grade (e.g. A, B+, C-): ";
        cin >> letterGrade;
        cin.ignore(); // clear leftover newline before next getline

        Course course(name, creditsHours, letterGrade);
        totalCourses.push_back(course);
    }

    cout << "\nYour courses entered:\n";
    for (auto &detail : totalCourses) {
        detail.display();  // display course detaills
    }

    return 0;
}
