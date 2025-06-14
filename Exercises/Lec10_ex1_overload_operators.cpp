#include <iostream>

// Exercise 1: Counter with overloaded ++
class Counter {
    int count;
public:
    Counter() : count(0) {}
    // Prefix increment
    Counter& operator++() {
        ++count;
        return *this;
    }
    // Postfix increment
    Counter operator++(int) {
        Counter temp = *this;
        ++count;
        return temp;
    }
    int getCount() const { return count; }
};

// Exercises 2-5: Number class with overloaded operators
class Number {
    int value;
public:
    Number(int v = 0) : value(v) {}
    
    // Exercise 2: Addition operator
    Number operator+(const Number& other) const {
        return Number(value + other.value);
    }
    
    // Exercise 3: Subtraction operator
    Number operator-(const Number& other) const {
        return Number(value - other.value);
    }
    
    // Exercise 4 & 5: Increment/Decrement operators
    Number& operator++() {        // Prefix ++
        ++value;
        return *this;
    }
    const Number operator++(int) { // Postfix ++
        Number temp = *this;
        ++value;
        return temp;
    }
    Number& operator--() {        // Prefix --
        --value;
        return *this;
    }
    const Number operator--(int) { // Postfix --
        Number temp = *this;
        --value;
        return temp;
    }
    
    int getValue() const { return value; }
};

int main() {
    // Exercise 1 Test
    Counter c;
    ++c;    // Prefix
    c++;    // Postfix
    std::cout << "Count: " << c.getCount() << std::endl;  // Should show 2

    // Exercise 2 Test
    Number a(5), b(3);
    Number sumResult = a + b;
    std::cout << "Sum: " << sumResult.getValue() << std::endl;  // 8

    // Exercise 3 Test
    Number d(10), f(4), g(3);
    Number result = d + f - g;  // Corrected to use d, f, g
    std::cout << "Result: " << result.getValue() << std::endl;  // 11

    // Exercise 4 Test
    Number x(5);
    Number y = x++;  // Postfix
    Number z = ++x;  // Prefix
    std::cout << "x: " << x.getValue()   // 7
              << ", y: " << y.getValue() // 5
              << ", z: " << z.getValue() // 7
              << std::endl;

    // Exercise 5 Test
    ++(++x);        // Valid: prefix returns non-const reference
    // (x++)++;     // Would cause compiler error: const object
    std::cout << "Final x: " << x.getValue() << std::endl;  // 9
}