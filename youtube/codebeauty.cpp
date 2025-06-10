#include <iostream>
using namespace std;

//an abstract class: an easy interface for users to use, hiding complex things 
class AbstractEmployee {
//a contracts with 1 rule
//whichever class want to sign the contract need to provide implementation for the method 
//eg: AskForPromotion method 
//this must be obligatory by making this a pure virtual function / abstract function
    virtual void AskForPromotion()=0;
};

//sign contract by ":AbstractEmployee"
class Employee:AbstractEmployee {
    //all attributes of class is private by default
    //must make public
    //now we move to encapsulation
private: 
    string Name;
    string Company;
    int Age;
//these 3 properties are now encapsulated 
public:
    //a class method aka a function
    void IntroduceYourself() {
            cout << "Name - " << Name << endl;
            cout << "Company - " << Company << endl;
            cout << "Age - " << Age << endl;
    }

    //constructor
    Employee(string name, string company, int age) {
        Name = name;
        Company = company;
        Age = age;
    }

    //setter & getter
    //methods are public => everyone can access to setters and getters

    void setName(string name) {
        //receives 1 parameter "name" then set the value of "Name" to "name"
        //original 20, receives name = 25, set Name = name = 25
        Name = name;
    }
    string getName() {
        //return the value of "Name" to whoever invokes getName()
        return Name;
    }

    void setCompany(string company) {
        Company = company;
    }
    string getCompany() {
        return Company;
    }

    void setAge(int age) {
        //set the rules for the properties
        if (age>=18)
        Age = age;
    }
    int getAge() {
        return Age;
    }

    //implementation for abstract function
    void AskForPromotion() {
        if(Age>30)
            cout<<Name<<" got promoted!"<<endl;
        else
            cout<<Name<<" , sorry NO promotion for you!"<<endl;
    }
};


int main()
{
    Employee employee1 = Employee("TAT", "Catkery",20);
    employee1.IntroduceYourself();

    Employee employee2 = Employee("Don", "Korcat", 21);
    employee2.IntroduceYourself();

    employee1.setAge(35);
    cout << employee1.getName() << " is " << employee1.getAge() << " years old." << endl;

    //test abstract class & virtual function
    employee1.AskForPromotion();
    employee2.AskForPromotion();
}