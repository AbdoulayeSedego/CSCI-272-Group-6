#include "header/Course.h"
#include "header/Student.h"
#include <iomanip>
#include <string>
#include <iostream>
#include <vector>
#include "header/Course.h"
#include "header/Student.h"
#include <iomanip>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Student{
  private:
    string name;
    string standing;
  public:
    Student (string n, string s){ // constructor to initialize nthe name
      name = n;
      standing = s;
    }
    ~Student(){ //destructor
        cout <<"Student class destroyed" << endl;
    }

    //setters and getters
    void setName(const string& n){
        name = n;
    }
    void setStanding(const string& s) {
        standing = s;
    }
    string getName() {
        return name;
        }
    string getStanding() {
        return standing;
        }


};
