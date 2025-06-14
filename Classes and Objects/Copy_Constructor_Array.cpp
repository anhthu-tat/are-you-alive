#include <iostream> 
#include <string>
using namespace std;

class IntArray {
private:
    int* data;      // Pointer to dynamic array
    int size;       // Number of elements
public:
    // Regular constructor
    IntArray(int s) : size(s) {
        data = new int[size];  // Allocate array
        for(int i = 0; i < size; i++) {
            data[i] = 0;       // Initialize elements
        }
    }
    // Copy constructor
    IntArray(const IntArray& other) {
        size = other.size;                // 1. Copy primitive members
        data = new int[size];             // 2. Allocate new memory  / Create brand new array
        for(int i = 0; i < size; i++) {   // 3. Copy array elements
            data[i] = other.data[i];      // 4. Deep copy each element / Copy values, not pointers
        }
        cout << "Copy constructor called!\n";
    }

    // Destructor
    ~IntArray() {
        delete[] data;  // Free memory
    }

    // Function to modify array
    void setValue(int index, int value) {
        if(index >= 0 && index < size) 
            data[index] = value;
    }

    // Function to print
    void print() {
        for(int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    // Create original array
    IntArray original(3);
    original.setValue(0, 10);
    original.setValue(1, 20);
    
    // Use copy constructor
    IntArray copy = original;
    
    // Modify original
    original.setValue(0, 100);
    
    cout << "Original: ";
    original.print();  // Output: 100 20 0
    
    cout << "Copy: ";
    copy.print();      // Output: 10 20 0
}