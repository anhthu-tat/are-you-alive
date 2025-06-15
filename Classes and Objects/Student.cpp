#include <iostream> 
#include <string>
using namespace std;

class Course { // As defined in source [11]
private:
    string name;
public:
    Course() { }
    Course( const string & cname ) : name(cname) {} // Added body for functionality
};

class Student { // As defined in source [11]
private:
    Course * coursesTaken;
    unsigned numCourses;
public:
    Student( unsigned nCourses ); // [11]
    ~Student(); // [11]
    // Copy constructor
    Student( const Student & s); // [9]
    unsigned getNumCourses() const { return numCourses; }
    Course getCourse(unsigned i) const { return coursesTaken[i]; }
};

Student::Student( unsigned nCourses ) { // [11]
    coursesTaken = new Course[nCourses]; // [11]
    numCourses = nCourses; // [11]
}

Student::~Student() { // [11]
    delete [] coursesTaken; // [11]
}

Student::Student( const Student & s) { // [9]
    numCourses = s.getNumCourses(); // [9]
    coursesTaken = new Course[numCourses]; // [9]
    for(int i = 0; i < numCourses; i++) { // [9]
        coursesTaken[i] = s.getCourse(i); // [9]
    }
}

int main () {
    int nCourses = 7; // [11]
    Student x(nCourses); // [11] // calls parameterized constructor
    Student y(x); // [11]      // calls copy constructo
}
