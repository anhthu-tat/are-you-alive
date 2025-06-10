#include <iostream>
using namespace std;

class Employee {
    //all attributes of class is private by default
    //must make public
public:
    string Name;
    string Company;
    int Age;

    //a class method aka a function
    void IntroduceYourself() {
            cout << "Name - " << Name << endl;
            cout << "Company - " << Company << endl;
            cout << "Age - " << Age << endl;
    }
};


int main()
{
    Employee employee1;
    employee1.Name = "TAT";
    employee1.Company = "Catkery";
    employee1.Age = 20;
    employee1.IntroduceYourself();

}