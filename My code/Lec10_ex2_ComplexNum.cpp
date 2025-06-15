#include <iostream> 
using namespace std;

class Complex;
// Declaration of the overloaded stream insertion operator as a non-member friend function.
// This allows for direct printing of Complex objects to output streams (e.g., cout << myComplexObject;).
// Declaring it as a 'friend' function grants it access to the private members of the Complex class
ostream& operator<<(ostream& os, const Complex& c);

class Complex {
private:
    double real;
    double imaginary; 

public:
    
    Complex() : real(0.0), imaginary(0.0) {}

    Complex(double r, double i) : real(r), imaginary(i) {}

    double getModulusSquared() const {
        return real * real + imaginary * imaginary;
    }

    bool operator>(const Complex& other) const {
        return this->getModulusSquared() > other.getModulusSquared();
    }

    Complex& operator=(const Complex& other) {
        if (this != &other) { // Check for self-assignment
            this->real = other.real;
            this->imaginary = other.imaginary;
        }
        return *this; // Return reference to the current object
    }

    friend ostream& operator<<(ostream& os, const Complex& c);
};

ostream& operator<<(ostream& os, const Complex& c) {
    os << c.real;
    if (c.imaginary >= 0) {
        os << " + " << c.imaginary << "i";
    } else {
        os << " - " << -c.imaginary << "i"; // Ensures positive imaginary part is printed after minus sign
    }
    os << " (Modulus^2: " << c.getModulusSquared() << ")";
    return os;
}

void bubbleSortDescending(Complex arr[], int n) {
    // This is a standard Bubble Sort implementation
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            // Compare arr[j] and arr[j+1] using the overloaded '>' operator.
            // If arr[j] is NOT greater than arr[j+1] (meaning arr[j] <= arr[j+1]), then swap them to achieve decreasing order.
            if (!(arr[j] > arr[j+1])) {
                Complex temp = arr[j];     // Uses Complex's overloaded assignment operator 
                arr[j] = arr[j+1];         // Uses Complex's overloaded assignment operator 
                arr[j+1] = temp;           // Uses Complex's overloaded assignment operator 
            }
        }
    }
}

int main() {
    // A fixed-size C-style array is used to store the complex numbers, as dynamic containers
    // like `std::vector` from the `<vector>` library are not permitted by the given constraints.
    const int MAX_COMPLEX_NUMBERS = 10;
    Complex complexNumbers[MAX_COMPLEX_NUMBERS]; // Array to hold Complex objects.
    int numComplex;

    // Prompt the user to enter the number of complex numbers.
    cout << "Enter the number of complex numbers (up to " << MAX_COMPLEX_NUMBERS << "): ";
    cin >> numComplex; // Reads integer input from user [1, 3].

    // Validate the input to ensure it's within the array's capacity.
    if (numComplex <= 0 || numComplex > MAX_COMPLEX_NUMBERS) {
        cout << "Invalid number of complex numbers. Please enter a number between 1 and "
             << MAX_COMPLEX_NUMBERS << ". Exiting.\n";
        return 1; // Indicate an error occurred.
    }

    // Read the complex numbers from user input.
    cout << "\nEnter " << numComplex << " complex numbers (real part then imaginary part):\n";
    for (int i = 0; i < numComplex; ++i) {
        double r, imag;
        cout << "  Complex " << (i + 1) << " (e.g., 3.5 -2.1):" << endl;
        cout << "    Real part: ";
        cin >> r; // Reads real part [1, 3].
        cout << "    Imaginary part: ";
        cin >> imag; // Reads imaginary part [1, 3].
        complexNumbers[i] = Complex(r, imag); // Uses the parameterized constructor and overloaded assignment operator [13].
    }

    // Print the original list of complex numbers.
    cout << "\n--- Original list of complex numbers ---" << endl;
    for (int i = 0; i < numComplex; ++i) {
        cout << complexNumbers[i] << endl; // Uses the overloaded stream insertion operator.
    }

    // Arrange (sort) the complex numbers in decreasing order of their modulus [13].
    // A custom Bubble Sort is used as standard sorting algorithms from <algorithm> are not allowed.
    bubbleSortDescending(complexNumbers, numComplex);

    // Print the list of complex numbers after sorting.
    cout << "\n--- Complex numbers sorted in decreasing order of modulus ---" << endl;
    for (int i = 0; i < numComplex; ++i) {
        cout << complexNumbers[i] << endl; // Uses the overloaded stream insertion operator.
    }

    // Explicitly demonstrate the overloaded assignment operator (=) [13].
    cout << "\n--- Demonstrating Overloaded Assignment Operator (=) ---" << endl;
    Complex c1_assign_test(10.0, 20.0);    // Initialize c1 with values
    Complex c2_assign_test;                // Default construct c2 (0.0 + 0.0i)
    cout << "Before assignment: c1 = " << c1_assign_test
         << ", c2 = " << c2_assign_test << endl;
    c2_assign_test = c1_assign_test;       // Call the overloaded assignment operator [13].
    cout << "After assignment (c2 = c1): c1 = " << c1_assign_test
         << ", c2 = " << c2_assign_test << endl;

    // Explicitly demonstrate the overloaded comparison operator (>) [13].
    cout << "\n--- Demonstrating Overloaded Comparison Operator (>) ---" << endl;
    Complex test_num1(3.0, 4.0); // Modulus^2 = 3^2 + 4^2 = 9 + 16 = 25
    Complex test_num2(1.0, 1.0); // Modulus^2 = 1^2 + 1^2 = 1 + 1 = 2
    Complex test_num3(5.0, 0.0); // Modulus^2 = 5^2 + 0^2 = 25 + 0 = 25

    cout << test_num1 << " > " << test_num2 << "? "
         << (test_num1 > test_num2 ? "Yes" : "No") << endl; // Expected: Yes (25 > 2)
    cout << test_num2 << " > " << test_num1 << "? "
         << (test_num2 > test_num1 ? "Yes" : "No") << endl; // Expected: No (2 is not > 25)
    cout << test_num1 << " > " << test_num3 << "? "
         << (test_num1 > test_num3 ? "Yes" : "No") << endl; // Expected: No (25 is not > 25)

    return 0; // Indicates successful program execution.
}