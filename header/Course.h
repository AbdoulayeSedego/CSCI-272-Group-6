#include <string>
#include <iostream>
using namespace std;

class Course {
private:
    string courseName;
    int creditHours;
    string letterGrade;

public:
    //default constructor
    Course(){}
    
    //parametized constroctor
    Course(string name, int credits, string grade);

    // destructor
    ~Course();

    void display() const {
    cout << "Course: " << courseName << endl; 
    cout << "Credits: " << creditHours << endl;
    cout << "Grade: " << letterGrade << endl;
}

};
