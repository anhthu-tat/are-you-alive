#include <iostream>
using namespace std;

class Complex {
public:
    double x;
    double y;
    Complex() : x(0), y(0) {}
    Complex(double real, double imag) : x(real), y(imag) {}

    Complex operator +=(int b) {
        y += b;
        return *this;
    }

    Complex operator -=(int b) {
        y -= b;
        return *this;
    }

    Complex operator *=(int b) {
        x *= b;
        y *= b;
        return *this;
    }

    Complex operator /=(int b) {
        x /= b;
        y /= b;
        return *this;
    }

    Complex operator <<(int b) {
        x = int(x) << b; // Left shift for real part
        y = int(y) << b; // Left shift for imaginary part
        return *this;
    }
};

int main() {
    Complex c1(3.0, 4.0); // Initialize complex number 3 + 4i
    cout << "Initial Complex Number: " << c1.x << " + " << c1.y << "i" << endl;

    c1 += 3; // Increment imaginary part by 3
    cout << "After += 3: " << c1.x << " + " << c1.y << "i" << endl;

    c1 -= 5; // Decrement imaginary part by 5
    cout << "After -= 5: " << c1.x << " + " << c1.y << "i" << endl;

    c1 *= 2; // Multiply both parts by 2
    cout << "After *= 2: " << c1.x << " + " << c1.y << "i" << endl;

    c1 /= 3; // Divide both parts by 3
    cout << "After /= 3: " << c1.x << " + " << c1.y << "i" << endl;

    c1 << 3; // Left shift both parts by 3
    cout << "After <<= 3: " << c1.x << " + " << c1.y << "i" << endl;

    return 0;
}
