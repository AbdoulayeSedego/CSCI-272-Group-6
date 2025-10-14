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
    Course(){

    }
    Course(string name, int credits, string grade);
    // destructor
    ~Course();
};
