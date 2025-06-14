
#include <iostream>
#include <string>
using namespace std;

// Base class: Person
class Person {
protected:
    int age;

public:
    void SetAge(int n) {
        age = n;
    }

    void Greet() {
        cout << "Hello!" << endl;
    }
};

// Derived class: Student
class Student : public Person {
public:
    void GoToClasses() {
        cout << "I'm going to class." << endl;
    }

    void ShowAge() {
        cout << "My age is: " << age << " years old." << endl;
    }
};

// Derived class: Teacher
class Teacher : public Person {
private:
    string subject;

public:
    void SetSubject(string s) {
        subject = s;
    }

    void Explain() {
        cout << "Explanation begins." << endl;
    }
};

// Test class
class StudentAndTeacherTest {
public:
    static void Main() {
        // Create a Person and make it say hello
        Person person;
        person.Greet();

        cout << endl;

        // Create a Student, set age, greet, and show age
        Student student;
        student.SetAge(21);
        student.Greet();
        student.ShowAge();
        student.GoToClasses();

        cout << endl;

        // Create a Teacher, set age, greet, and explain
        Teacher teacher;
        teacher.SetAge(30);
        teacher.Greet();
        teacher.Explain();
    }
};

// Main function
int main() {
    StudentAndTeacherTest::Main();
    return 0;
}
