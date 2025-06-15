#include <iostream>
using namespace std;

class Rational {
private:
    int numerator;
    int denominator;

public: 
    //default constructor 
    Rational() : numerator(1), denominator(1) {}
    //constructor with given numerator and denomirator
    Rational(int num, int denom) : numerator(num), denominator(denom) {
        if (denominator == 0) cout<<"Invalid!"<<endl;
        simplify();
    }

    //constructor for whole number
    Rational(int wholeNum): numerator(wholeNum), denominator(1) {}

    //function to calculate greatest common divisor
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void simplify() {
        int GCD = gcd(numerator, denominator);
        numerator /= GCD;
        denominator /= GCD;
        //make the fraction more neat
        if (denominator < 0) {
            numerator *= -1;
            denominator *= -1;
        }
    }

    //getters
    int getNum() const {return numerator;}
    int getDenom() const {return denominator;}

    //setters
    void setNum(int n) {numerator = n;}
    void setDenom(int d) {denominator = d;}

    //functions
    void Display() {
        cout<<"The rational number is "<<getNum()<<"/"<<getDenom()<<endl;
    }
};

int main() {
    Rational r1 = Rational(5, -15);
    r1.Display();
}