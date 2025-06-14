#include <iostream>
#include <string>
using namespace std;

class A{
    private:
        int a;
    public:
        A() {a = 10;}
        void seta(int value);
    friend class B; // Declare B as a friend class
};

void A::seta (int value) { a = value;}
class B {
    private:
        int b;
    public:
        void showA(A& x) {cout << "A::a=" << x.a; };
};

int main() {
    A a; B b;
    a.seta(15);
    b.showA(a); // Accessing private member of A through B
    return 0;
}