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
    ~Student(); //this is the destructor

// setters
    void setName(const string& n);
    void setStanding(const string& s);
// getters
    string getName();
    string getStanding();


    
};
