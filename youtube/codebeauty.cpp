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
protected: 
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

    //polymorphism 
    //first, we create a method 
    //make this function virtual after creating a pointer of base class referred to an object of derived class
    //virtual function invoked: check if there is implementation of method inside the derived classes
    //if yes, execute the implementation instead of this method
    virtual void Work() {
        cout<<Name<<" is checking email, task, performing tasks..."<<endl;
    }
};

//this "Developer" class is now the subclass of the "Employee" class
//every single properties and methods of "Employee" is in "Developer"
//inheritance is private => objects can not access to properties that inherited from "Employee" class
//Make inheritance public to get access to "AskForPromotion"
class Developer:public Employee {
public: 
    string FavProgrammingLanguage;

    //constructor
    Developer(string name, string company, int age, string favprogramminglanguage) 
        :Employee(name, company, age)
    {
        FavProgrammingLanguage = favprogramminglanguage;
    }

    //method
    void FixBug() {
        //getName() when the properties is private
        //Name when the properties is protected => derived class can access to
        cout<<getName()<<" fixed bug using "<<FavProgrammingLanguage<<endl;
    }

    //polymorphism
    void Work() {
        cout<<Name<<" is writing "<<FavProgrammingLanguage<<" lesson."<<endl;
    }
};

class Teacher:public Employee {
public:
    string Subject;

    //constructor
    Teacher(string name, string company, int age, string subject)
        :Employee(name, company, age) 
    {
        Subject = subject;
    }

        //method
    void prepareLesson() {
        cout<<Name<<" is preparing "<<Subject<<" lesson."<<endl;
    }

    //polymorphism
    void Work() {
        cout<<Name<<" is teaching "<<Subject<<" subject."<<endl;
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

    Developer d = Developer("NTA", "Catube", 45, "C++");
    d.FixBug();
    //d can not access to "AskForPromotion"
    //inheritance is private => objects can not access to properties that inherited from "Employee" class
    //Public inheritance to get access to "AskForPromotion"
    d.AskForPromotion();

    Teacher t = Teacher("MNhu", "LTV", 36, "Math");
    t.prepareLesson();
    t.AskForPromotion();

    //polymorphism
    employee1.Work();
    d.Work();
    t.Work();

    //create a pointer of type Employee
    //Rule: A pointer of base class can hold reference to derived class objects
    //pointer e1 holds a reference to object d
    Employee* e1= &d;
    Employee* e2= &t;
    e1->Work();
    e2->Work();
    //at first, it does not work. now add virtual into void Work => it worked
}