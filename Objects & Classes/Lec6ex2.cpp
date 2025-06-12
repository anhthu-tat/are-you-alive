#include <iostream>
#include <string>
using namespace std;

class Rational {
private:
    int Numerator;
    int Denominator;

public: 
    // default constructor that initializes the fraction with 1
    Rational () {
        Numerator = 1;
        Denominator = 1;
    }
    // constructor that initializes the fraction with a given numerator and denominator
    Rational (int num, int denom) {
        Numerator = num;
        Denominator = denom;
        if (Denominator <= 0) throw invalid_argument("Denominator cannot be zero");
    }
    //constructor that initializes the fraction with a given whole number
    Rational(int wholeNum) {
        Numerator = wholeNum;
        Denominator = 1;
    }

    //functions 
    void numerator() {

    }

    int gcd(int a, int b) {
        while (b)
    }
};

int main() {

}