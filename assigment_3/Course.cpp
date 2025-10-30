#include "header/Course.h"
#include "header/Student.h"
#include <iomanip>
#include <string>
#include <iostream>
#include <vector>

class Course {
    private:
        string courseName;
        int creditHours;
        string letterGrade;

    public:
        Course(string name, int credits, string grade);


};