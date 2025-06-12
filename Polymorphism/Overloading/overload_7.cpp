#include <iostream>
using namespace std;

class Pascal {
public:
    int x_pow;
    int y_pow;
   
    Pascal() : x_pow(0), y_pow(0) {}
    Pascal(int x, int y) : x_pow(x), y_pow(y) {}

    int Factorial(int n) const {
        if (n <= 1) return 1;
        return n * Factorial(n - 1);
    }

    int operator() (int x, int y) {
        return Factorial(x + y) / (Factorial(x) * Factorial(y));
    }
};

int main() {
    Pascal p1(3, 2);
    Pascal p2(4, 1);
   
    cout << "C(3, 2): " << p1(3, 2) << endl; // Output: 10
    cout << "C(4, 1): " << p2(4, 1) << endl; // Output: 5
   
    return 0;
}
