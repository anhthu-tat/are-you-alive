#include <iostream> 
using namespace std;

class CSStudent {
private: 
    int ID;
    string Name;
    string Address;
    string Scholarship;

public: 
    //constructor
    CSStudent(int id, string name, string address, string scholar) : ID(id), Name(name), Address(address), Scholarship(scholar) {}

    //getters
    int getID() const {return ID;}
    string getName() const {return Name;}
    string getAddress() const {return Address;}
    string getScholar() const {return Scholarship;}

    //setters
    void setID(int id) {ID = id;}
    void setName(string name) {Name = name;}
    void setAddress(string address) {Address = address;}
    void setScholar(string scholar) {Scholarship = scholar;}

    //function
    void Print() {
        cout <<"Student ID: " << getID()<<"\n"
            << "Name: " << getName()<<"\n"
            << "Address: " << getAddress()<<"\n"
            << "Scholarship: " << getScholar()<<endl;
    }
};

int main() {
    CSStudent s1 = CSStudent(10423173, "TAT", "Ruby", "Merit");
    s1.Print();
}