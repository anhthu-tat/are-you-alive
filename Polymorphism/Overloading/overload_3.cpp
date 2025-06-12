#include <iostream>
using namespace std;

class Complex {
public:
    double x;
    double y;
    Complex() : x(0), y(0) {}
    Complex(double real, double imag) : x(real), y(imag) {}

    Complex operator +(const Complex& b) {
        Complex result;
        result.x = x + b.x;
        result.y = y + b.y;
        return result;
    }

    Complex operator -(const Complex& b) {
        Complex result;
        result.x = x - b.x;
        result.y = y - b.y;
        return result;
    }

    Complex operator *(const Complex& b) {
        Complex result;
        result.x = x*b.x - y*b.y;
        result.y = x*b.y + y*b.x;
        return result;
    }

    Complex operator /(const Complex& b) {
        Complex result;
        result.x = (x*b.x + y*b.y)/(b.x*b.x + b.y*b.y);
        result.y = (-x*b.y + y*b.x)/(b.x*b.x + b.y*b.y);
        return result;
    }

    Complex operator <<(int b) {
        x = int(x) << b; // Left shift for real part
        y = int(y) << b; // Left shift for imaginary part
        return *this;
    }
};

int main() {
    Complex c1(3.0, 4.0); // Initialize complex number 3 + 4i
    Complex c2(1.0, 2.0); // Initialize complex number 1 + 2i
    cout << "Initial Complex Number 1: " << c1.x << " + " << c1.y << "i" << endl;
    cout << "Initial Complex Number 2: " << c2.x << " + " << c2.y << "i" << endl;
    Complex c3 = c1 + c2; // Add two complex numbers
    cout << "c1 + c2 = " << c3.x << " + " << c3.y << "i" << endl;
    Complex c4 = c1 - c2; // Subtract two complex numbers
    cout << "c1 - c2 = " << c4.x << " + " << c4.y << "i" << endl;
    Complex c5 = c1 * c2; // Multiply two complex numbers
    cout << "c1 * c2 = " << c5.x << " + " << c5.y << "i" << endl;
    Complex c6 = c1 / c2; // Divide two complex numbers
    cout << "c1 / c2 = " << c6.x << " + " << c6.y << "i" << endl;
    c1 << 3; // Left shift both parts by 3
    cout << "c1 << 3 = " << c1.x << " + " << c1.y << "i" << endl;
    return 0;
}
