
#include <iostream>
using namespace std;

class Money {
public:
    int dollars;
    int cents;

    Money() : dollars(0), cents(0) {}
    Money(int d, int c) : dollars(d), cents(c) {}

    Money operator +(const Money& b) {
        Money result;
        result.cents = cents + b.cents;
        result.dollars = dollars + b.dollars;
        if (result.cents >= 100) {
            result.dollars++;
            result.cents -= 100;
        }
        return result;
    }

    Money operator -(const Money& b) {
        Money result;
        if (dollars < b.dollars) {
            result.dollars = b.dollars - dollars;
            result.cents = b.cents - cents;
        } else if (dollars == b.dollars) {
            result.dollars = 0;
            if (cents < b.cents) {
                result.cents = b.cents - cents;
            } else {
                result.cents = cents - b.cents;
            }
        } else {
            result.dollars = dollars - b.dollars;
            result.cents = cents - b.cents;
        }

        if (result.cents < 0) {
            result.dollars--;
            result.cents += 100;
        }
        return result;
    }

    Money operator *=(int b) {
        cents *= b;
        dollars *= b;
        if (cents >= 100) {
            dollars += cents / 100;
            cents %= 100;
        }
        return *this;
    }

    Money operator /=(int b) {
        cents /= b;
        dollars /= b;
        return *this;
    }
};

int main() {
    Money m1(5, 75);
    Money m2(3, 50);

    Money m3 = m1 + m2;
    Money m4 = m1 - m2;
    m1 *= 2;
    m2 /= 3;

    cout << "m1 + m2 = " << m3.dollars << " dollars and " << m3.cents << " cents" << endl;
    cout << "m1 - m2 = " << m4.dollars << " dollars and " << m4.cents << " cents" << endl;
    cout << "m1 * 2 = " << m1.dollars << " dollars and " << m1.cents << " cents" << endl;
    cout << "m2 / 3 = " << m2.dollars << " dollars and " << m2.cents << " cents" << endl;

    return 0;
}
