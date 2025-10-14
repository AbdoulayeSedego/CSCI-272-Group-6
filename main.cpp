#include "header/Course.h"
#include "header/Student.h"
#include "Course.cpp"
#include "Student.cpp"
#include <iomanip>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main () {
    //take the number of course from the student
    int numberofcourses;
    cout << "Enter the number of courses: "<<endl;
    cin >> numberofcourses;
    cin.ignore();
    

    // vector to hold the total number of course
    vector<Course> totalCourses;
    totalCourses.reserve(numberofcourses);

    //main loop to take courses details
    for(int i = 0; i < numberofcourses; i++){
        string name;
        int creditsHours;
        string letterGrade;

        cout <<"Enter course name :"<<endl;
    }



    Course course;

}