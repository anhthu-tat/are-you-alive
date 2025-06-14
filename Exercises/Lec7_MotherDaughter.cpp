#include <iostream>
using namespace std;

class Mother {
private:
    string name;
    string hobby;
    string action;
public:
    // Setters
    void setName(string n) { name = n; }
    void setHobby(string h) { hobby = h; }
    void setAction(string a) { action = a; }

    // Getters
    string getName() { return name; }
    string getHobby() { return hobby; }
    string getAction() { return action; }

    // Constructor
    Mother() : name(""), hobby(""), action("") {}

    // Display method
    void display() {
        cout << "Hello! I am the mother. My name is " << name << ". I love " << hobby << " and I enjoy " << action << "." << endl;
    }
};

class Daughter : public Mother {
private:
    string secretJob;
    string favorBook;
    string secretPet;
public:
    // Setters
    void setSecretJob(string j) { secretJob = j; }
    void setFavorBook(string b) { favorBook = b; }
    void setSecretPet(string p) { secretPet = p; }

    // Getters
    string getSecretJob() { return secretJob; }
    string getFavorBook() { return favorBook; }
    string getSecretPet() { return secretPet; }

    // Constructor
    Daughter() : secretJob(""), favorBook(""), secretPet("") {}

    // Display method
    void display() {
        cout << "Hello! I am the daughter. My secret job is a " << secretJob << ", my favorite book is " << favorBook << ", and my secret pet is a " << secretPet << "." << endl;
    }
};

int main() {
    // Create a Daughter object
    Daughter daughter;

    // Setting values for Mother's attributes
    daughter.setName("Emily");
    daughter.setHobby("reading");
    daughter.setAction("gardening");

    // Setting values for Daughter's attributes
    daughter.setSecretJob("programmer");
    daughter.setFavorBook("How build a time machine");
    daughter.setSecretPet("cat");

    // Call display() method on Daughter
    daughter.display();

    // Call display() method on Mother
    daughter.Mother::display();

    return 0;
}