#include <string>   // For std::string
#include <iostream> // For std::cout

class Course {
private:
    std::string name;
    unsigned units;

public:
    // Default constructor
    Course() : name(""), units(0) {
    }

    // Parameterized constructor
    Course(const std::string& n, unsigned u) : name(n), units(u) {
    }

    // Getters
    std::string getName() const {
        return name;
    }
    unsigned getUnits() const {
        return units;
    }

    // Member function to print course information
    void printInfo() const {
        std::cout << "  Course: " << name << " (Units: " << units << ")\n";
    }
};

class Student {
private:
    std::string name;
    double gpa;
    Course* courses_taken;      // Pointer to dynamic array of Course objects
    unsigned num_courses_taken;  // Current number of courses
    unsigned max_courses_capacity; // Maximum capacity of the array

public:
    // Default constructor [3-5]
    Student() : name(""), gpa(0.0), courses_taken(nullptr), num_courses_taken(0), max_courses_capacity(0) {
    }

    // Parameterized constructor [3-5]
    Student(const std::string& n, double g, unsigned initial_capacity)
        : name(n), gpa(g), num_courses_taken(0), max_courses_capacity(initial_capacity) {
        if (max_courses_capacity > 0) {
            courses_taken = new Course[max_courses_capacity]; // Allocate memory on heap
        } else {
            courses_taken = nullptr;
        }
        std::cout << "Student parameterized constructor called for: " << name << " (Capacity: " << max_courses_capacity << ")\n";
    }

    // Destructor: Deallocates dynamically allocated memory
    ~Student() {
        delete[] courses_taken; // Free the allocated memory
        courses_taken = nullptr; // Good practice to nullify dangling pointer
        std::cout << "Student destructor called for: " << name << "\n";
    }

    // Copy Constructor: Performs deep copy
    Student(const Student& other)
        : name(other.name), gpa(other.gpa), num_courses_taken(other.num_courses_taken), max_courses_capacity(other.max_courses_capacity) {
        if (max_courses_capacity > 0) {
            courses_taken = new Course[max_courses_capacity];
            for (unsigned i = 0; i < num_courses_taken; ++i) {
                courses_taken[i] = other.courses_taken[i]; // Copy each Course object
            }
        } else {
            courses_taken = nullptr;
        }
        std::cout << "Student copy constructor called for: " << name << " (copied from " << other.name << ")\n";
    }

    // Copy Assignment Operator: Performs deep copy, handles self-assignment
    Student& operator=(const Student& other) {
        if (this != &other) { // Check for self-assignment
            // Deallocate old memory
            delete[] courses_taken;
            courses_taken = nullptr; // Nullify to prevent dangling pointer issues before new allocation

            // Copy non-pointer members
            name = other.name;
            gpa = other.gpa;
            num_courses_taken = other.num_courses_taken;
            max_courses_capacity = other.max_courses_capacity;

            // Allocate new memory and copy courses
            if (max_courses_capacity > 0) {
                courses_taken = new Course[max_courses_capacity];
                for (unsigned i = 0; i < num_courses_taken; ++i) {
                    courses_taken[i] = other.courses_taken[i];
                }
            } else {
                courses_taken = nullptr;
            }
        }
        std::cout << "Student copy assignment operator called for: " << name << " (assigned from " << other.name << ")\n";
        return *this;
    }

    // Getters
    std::string getName() const {
        return name;
    }
    double getGPA() const {
        return gpa;
    }

    // Function to add a course to the student's list
    void addCourse(const Course& course) {
        if (num_courses_taken < max_courses_capacity) {
            courses_taken[num_courses_taken] = course; // Copy the Course object
            num_courses_taken++;
            std::cout << name << " enrolled in " << course.getName() << ".\n";
        } else {
            std::cout << "Error: " << name << "'s course list is full (capacity: " << max_courses_capacity << "). Cannot add " << course.getName() << ".\n";
        }
    }

    // Member function to print student information, including courses taken [5, 6]
    void printInfo() const {
        std::cout << "\n--- Student Information ---\n";
        std::cout << "Name: " << name << "\n";
        std::cout << "GPA: " << gpa << "\n";
        std::cout << "Courses Taken (" << num_courses_taken << "/" << max_courses_capacity << "):\n";
        if (num_courses_taken == 0) {
            std::cout << "  No courses taken yet.\n";
        } else {
            for (unsigned i = 0; i < num_courses_taken; ++i) {
                courses_taken[i].printInfo(); // Call Course's printInfo
            }
        }
        std::cout << "---------------------------\n";
    }
};


int main() {
    // 1. Create Course objects
    std::cout << "--- Creating Course Objects ---\n";
    Course math101("Calculus I", 3);
    Course cs201("Data Structures", 4);
    Course phys101("Physics I", 3);
    Course hist300("World History", 3);
    Course lit200("Literature Survey", 3);
    std::cout << "\n";

    // 2. Create Student objects
    std::cout << "--- Creating Student Objects ---\n";
    // Student1 with capacity for 3 courses
    Student student1("Alice Smith", 3.9, 3);
    // Student2 with capacity for 2 courses
    Student student2("Bob Johnson", 3.5, 2);
    // Student3 with default constructor, will have 0 capacity initially
    Student student3;
    student3.addCourse(math101); // This will show an error as capacity is 0

    std::cout << "\n";

    // 3. Add courses to Student objects
    std::cout << "--- Adding Courses to Students ---\n";
    student1.addCourse(math101);
    student1.addCourse(cs201);
    student1.addCourse(phys101);
    student1.addCourse(hist300); // Attempt to add beyond capacity

    std::cout << "\n";

    student2.addCourse(cs201);
    student2.addCourse(lit200);
    student2.addCourse(math101); // Attempt to add beyond capacity

    std::cout << "\n";

    // 4. Print Student information
    std::cout << "--- Printing Student Information ---\n";
    student1.printInfo();
    student2.printInfo();
    student3.printInfo(); // Will show no courses and default name/GPA

    std::cout << "\n";

    // 5. Demonstrate Copy Constructor and Assignment Operator for Student
    std::cout << "--- Demonstrating Copy Constructor and Assignment Operator ---\n";

    // Test Copy Constructor [13-16]
    std::cout << "\nCreating student_copy using copy constructor from student1:\n";
    Student student_copy = student1; // Calls copy constructor
    student_copy.printInfo();

    // Modify student1 after copying to show it's a deep copy
    std::cout << "\nModifying original student1 (adding 'Calculus II')...\n";
    Course math102("Calculus II", 3);
    // Note: student1's capacity is already 3, so cannot add another course directly.
    // To demonstrate modification clearly, it would require resizing or a larger initial capacity.
    // For now, let's assume `addCourse` worked as intended earlier and the copy is separate.
    // If student1 had more capacity, we could add a course to it and see student_copy remains unchanged.
    // For this example, let's assume student1 had enough capacity earlier to avoid error message here.
    // Let's create a new student_orig for this test.
    Student student_orig("Original Test", 3.7, 5);
    student_orig.addCourse(math101);
    student_orig.addCourse(cs201);
    student_orig.printInfo();

    std::cout << "\nCreating student_copy_for_modify using copy constructor from student_orig:\n";
    Student student_copy_for_modify = student_orig;
    student_copy_for_modify.printInfo();

    std::cout << "\nModifying original student_orig by adding 'Physics II'...\n";
    Course phys102("Physics II", 4);
    student_orig.addCourse(phys102);
    student_orig.printInfo();
    std::cout << "\nstudent_copy_for_modify remains unchanged:\n";
    student_copy_for_modify.printInfo(); // Should show no Physics II - confirming deep copy

    // Test Assignment Operator [13-16]
    std::cout << "\nAssigning student1 to student3 (using assignment operator):\n";
    student3 = student1; // Calls assignment operator
    student3.printInfo();

    std::cout << "\nAttempting self-assignment (student1 = student1):\n";
    student1 = student1; // Should handle self-assignment gracefully
    student1.printInfo();

    std::cout << "\nEnd of main function. Destructors will be called as objects go out of scope.\n";
    return 0;
}