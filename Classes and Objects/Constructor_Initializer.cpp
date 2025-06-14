#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;            // Member 1
    int id;                 // Member 2
    const int gradYear;     // Must be initialized in initializer list
public:
    // Constructor definition
    Student(string n, int i, int year) : name(n), id(i), gradYear(year)
    //Initializer List Syntax - Appears after colon : before function body ": member1(value1), member2(value2), ..."
    //Members are initialized in declaration order
    {
        if(id < 0) id = 0;  // Optional: Can add validation here
    }

    void display() const {
        cout << name << " (ID:" << id << ", Graduates:" << gradYear << ")\n";
    }
};

int main() {
    Student s1("Alice", 12345, 2025);
    s1.display();           // Output: Alice (ID:12345, Graduates:2025)
}