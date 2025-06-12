#include <iostream>
using namespace std;

class Money {
public:
    int dollars;
    int cents;

    Money() : dollars(0), cents(0) {}
    Money(int d, int c) : dollars(d), cents(c) {}

    bool operator >(const Money& b) const {
        if (dollars != b.dollars) {
            return dollars > b.dollars;
        }
        return cents > b.cents;
    }

    bool operator <(const Money& b) const {
        if (dollars != b.dollars) {
            return dollars < b.dollars;
        }
        return cents < b.cents;
    }

    bool operator ==(const Money& b) const {
        return (dollars == b.dollars && cents == b.cents);
    }

    bool operator !=(const Money& b) const {
        return !(*this == b);
    }
};

int main() {
    Money m1(5, 75);
    Money m2(3, 50);
    Money m3(6, 0);
    Money m4(5, 75);
    Money m5(5, 76);

    cout << "m1 > m2: " << (m1 > m2) << endl; // true
    cout << "m1 < m3: " << (m1 < m3) << endl; // true
    cout << "m1 == m4: " << (m1 == m4) << endl; // true
    cout << "m1 != m5: " << (m1 != m5) << endl; // true
    cout << "m2 > m3: " << (m2 > m3) << endl; // false
    cout << "m3 < m5: " << (m3 < m5) << endl; // false
    return 0;
}
