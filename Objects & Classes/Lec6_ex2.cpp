#include <iostream>
#include <stdexcept>
using namespace std;

class Rational {
private:
    int numerator;
    int denominator;

    void simplify() {
        int commonDivisor = gcd(abs(numerator), abs(denominator));
        numerator /= commonDivisor;
        denominator /= commonDivisor;
        
        if (denominator < 0) {
            numerator *= -1;
            denominator *= -1;
        }
    }

public:
    static int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // Constructors
    //":"Member initializer list that directly initializes numeratorb -> 1 & denominator -> 1
    Rational() : numerator(1), denominator(1) {}
    Rational(int num, int denom) : numerator(num), denominator(denom) {
        if (denominator == 0) throw invalid_argument("Denominator cannot be zero");
        simplify();
    }
    Rational(int wholeNumber) : numerator(wholeNumber), denominator(1) {}

    // Getters
    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }

    // Arithmetic operations
    Rational operator+(const Rational& other) const {
        return Rational(
            numerator * other.denominator + other.numerator * denominator,
            denominator * other.denominator
        );
    }

    Rational operator-(const Rational& other) const {
        return Rational(
            numerator * other.denominator - other.numerator * denominator,
            denominator * other.denominator
        );
    }

    Rational operator*(const Rational& other) const {
        return Rational(numerator * other.numerator, denominator * other.denominator);
    }

    Rational operator/(const Rational& other) const {
        if (other.numerator == 0) throw invalid_argument("Cannot divide by zero");
        return Rational(numerator * other.denominator, denominator * other.numerator);
    }

    // Display method
    void display() const {
        if (denominator == 1) {
            cout << numerator;
        } else {
            cout << numerator << "/" << denominator;
        }
    }
};