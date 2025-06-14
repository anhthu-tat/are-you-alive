#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int age;
    string studentID;
    string major;
    float GPA;
    string routine[7];
    string enrolledCourses[5];
    int courseCount = 0;
    int routineCount = 0;

public:
    // Constructor
    Student(string n, int a, string id, string m, float gpa) {
        name = n;
        age = a;
        studentID = id;
        major = m;
        GPA = gpa;
    }

    // Method to add a course (max 5)
    void enrollCourse(string course) {
        if (courseCount < 5) {
            enrolledCourses[courseCount] = course;
            courseCount++;
        }
    }

    void setRoutine(string task, int index) {
        if (index >= 0 && index < 7) {
            routine[index] = task;
            if (index + 1 > routineCount) routineCount = index + 1;
        }
    }

    // Method to display student profile
    void showProfile() {
        cout << "===== VGU Student Profile =====" << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Student ID: " << studentID << endl;
        cout << "Major: " << major << endl;
        cout << "GPA: " << GPA << endl;
        cout << "===============================" << endl;
    }

    void showCourses() {
        cout << "Courses enrolled this semester:" << endl;
        for (int i = 0; i < courseCount; i++) {
            cout << "- " << enrolledCourses[i] << endl;
        }
    }

    void showDailyRoutine() {
        cout << name << "'s Daily Routine at VGU:" << endl;
        for (int i = 0; i < routineCount; i++) {
            cout << "- " << routine[i] << endl;
        }
    }

    void study(int hours) {
        cout << name << " is studying for " << hours << " hours today." << endl;
    }

    void attendClass(string course) {
        cout << name << " is attending the " << course << " class." << endl;
    }

    void takeBreak() {
        cout << name << " is taking a break and recharging." << endl;
    }
};

// Main function
int main() {
    Student s("JiaFei", 20, "CS23", "Computer Science and Engineering", 3.5);

    // Enroll in courses
    s.enrollCourse("DSA");
    s.enrollCourse("OOP");
    s.enrollCourse("IoT");
    s.enrollCourse("TCS");

    // Set daily routine
    s.setRoutine("Wake up at 5:30 AM", 0);
    s.setRoutine("Morning study session", 1);
    s.setRoutine("Attend VGU lectures", 2);
    s.setRoutine("Work on group project", 3);
    s.setRoutine("Study in library", 4);
    s.setRoutine("Evening exercise", 5);
    s.setRoutine("Wind down with a tiktok", 6);

    // Simulate actions
    s.showProfile();
    s.showCourses();
    s.showDailyRoutine();
    cout << endl;
    s.attendClass("OOP");
    s.study(3);
    s.takeBreak();

    return 0;
}