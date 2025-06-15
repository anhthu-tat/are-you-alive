#include <iostream>
using namespace std;             

class A {                         // Define class A
protected:
    int a;                        // 'a' is protected: accessible in A and its derived classes, but not outside
public:
    A() { a=10; }                 // Constructor: initializes 'a' to 10
    void seta(int value);         // Public method to set the value of 'a'
    int geta() {return a;}        //problem solved creating a getter in the base class then call the getter in the derived class
};

void A::seta(int value)           // Implementation of seta
{
    a = value;                    // Assign the given value to 'a'
} 

class B: public A {               // Define class B, which inherits publicly from A
private:
    int b;                        // Private member 'b', only accessible within B
public:
    void showA(A x) {             // Public method that takes an object of type A
        cout << "A::a=" << x.geta(); // x.a => ERROR: Cannot access 'a' of another A object, even in derived class
                                  //But if we change "x.a" into "x.geta()", then we will be alright
    }
};

int main() {
   A a;                          // Create an object 'a' of class A
   B b;                          // Create an object 'b' of class B
   a.seta(15);                   // Set 'a' in object 'a' to 15 using the public setter
   b.showA(a);                   // Attempt to display 'a' of object 'a' using B's showA (will cause compile error if using "x.a")
   return 0;                     // Indicate successful program termination
}


/*
This code demonstrates the use of the 'protected' access specifier in C++ inheritance.

- Class A has a protected integer member 'a', a constructor that initializes 'a' to 10, and a public setter for 'a'.
- Class B publicly inherits from A, adds a private member 'b', and defines a method showA that tries to access the protected member 'a' of another A object.
- In main(), objects of A and B are created. The value of 'a' in object 'a' is set to 15, and then B's showA is called with 'a' as an argument.

Key Point:
- The code will NOT compile because B::showA(A x) tries to access x.a, but 'a' is protected in A. 
- A derived class can access protected members of its own base subobject, but NOT those of another instance (even if it's of the base type).

If 'a' were public, the output would be: A::a=15
As written, this code will cause a compilation error due to access violation.
*/