#include <iostream> 
#include <string>   

class Student {
private:
    std::string name; // Private data member for name 
    double gpa;       // Private data member for GPA 

public:
    // Default constructor
    Student() : name(""), gpa(0.0) {}   
    // Parameterized constructor
    Student(const std::string& n, double g) : name(n), gpa(g) {}

    // Member function to print student information
    void printInfo() const { // 'const' guarantees the function doesn't modify object state
        std::cout << "Name: " << name << ", GPA: " << gpa << std::endl;
    }
};

class Course {
private:
    unsigned capacity;        // Maximum number of students the course can hold 
    Student* students;        // Pointer to a dynamically allocated array of Student objects
    unsigned currentEnrollment; // Current number of students enrolled

public:
    // Constructor: Allocates memory for the student array
    Course(unsigned maxCapacity) : capacity(maxCapacity), currentEnrollment(0) {
        if (capacity > 0) {
            students = new Student[capacity]; // Allocate an array of Student objects on the heap
        } else {
            students = nullptr; // Handle 0 capacity case
        }
        std::cout << "Course created with capacity: " << capacity << std::endl;
    }

    // Destructor: Deallocates dynamically allocated memorymemory
    ~Course() {
        delete[] students; // Frees the memory allocated by 'new Student[capacity]'
        students = nullptr; // Set pointer to null to prevent dangling pointers 
        std::cout << "Course destroyed and memory deallocated." << std::endl;
    }

    // Function to enroll a student in the coursecourse
    void enrollStudent(const Student& s) {
        if (currentEnrollment < capacity) {
            students[currentEnrollment] = s; // Copy the student object into the array
            currentEnrollment++;
            std::cout << "Student enrolled successfully. Current enrollment: " << currentEnrollment << std::endl;
        } else {
            std::cout << "Course is full. Cannot enroll more students." << std::endl;
        }
    }

    // Function to print information about all enrolled students
    void printAllEnrolledStudents() const {
        std::cout << "\n--- Students enrolled in this Course (" << currentEnrollment << "/" << capacity << ") ---" << std::endl;
        if (currentEnrollment == 0) {
            std::cout << "No students enrolled yet." << std::endl;
        } else {
            for (unsigned i = 0; i < currentEnrollment; ++i) { // Loop through the enrolled students
                students[i].printInfo(); // Call the Student's printInfo function
            }
        }
        std::cout << "------------------------------------------\n" << std::endl;
    }

    // Declarations for the Rule of Three/Five (for robust dynamic memory management):
    // Course(const Course& other); // Copy constructor
    // Course& operator=(const Course& other); // Copy assignment operator
};

int main() {
    // Create Student objects
    Student student1("Alice", 3.8);
    Student student2("Bob", 3.5);
    Student student3("Charlie", 4.0);
    Student student4("David", 3.2);

    // Create a Course object with a capacity for 3 students
    Course myCourse(3);

    // Enroll students in the course
    myCourse.enrollStudent(student1);
    myCourse.enrollStudent(student2);
    myCourse.enrollStudent(student3);

    // Attempt to enroll a student beyond the course capacity
    myCourse.enrollStudent(student4); // This should indicate the course is full

    // Print information for all students currently enrolled in the course
    myCourse.printAllEnrolledStudents();

    // Demonstrate a course with no students enrolled
    Course emptyCourse(1);
    emptyCourse.printAllEnrolledStudents();

    return 0; // Indicate successful program termination
}