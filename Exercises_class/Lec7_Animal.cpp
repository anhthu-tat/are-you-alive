#include <iostream>
#include <string>
using namespace std;

class Animal {
protected: 
    string name;
    int age;
public:
    void set_value(string n, int a) {
        name = n;
        age = a;
    }
};

class Zebra : public Animal {
private:
    string favFood;
    string origin;
    int lifeSpan;
    string funFact;
public:
    void set_value(string n, int a, string f, string o, int m, string ff) {
        Animal::set_value(n, a); 
        favFood = f;
        origin = o;
        lifeSpan = m;
        funFact = ff;
    }
    void display(){
        cout << "Hi there! I'm " << name << ", a zebra. I'm " << age << " years old. My favorite food is " 
             << favFood << ". Zebras originate from " << origin << ". We live up to " << lifeSpan 
             << " years. Fun fact: " << funFact << "\n" << endl;
    }
    
};

class Dolphin : public Animal {
    private:
        string favFood;
        string origin;
        int lifeSpan;
        string funFact;
    public:
    void set_value(string n, int a, string f, string o, int m, string ff) {
        Animal::set_value(n, a); 
        favFood = f;
        origin = o;
        lifeSpan = m;
        funFact = ff;
    }

    void display(){
        cout << "Hi there! I'm " << name << ", a dolphin. I'm " << age << " years old. My favorite food is " 
             << favFood << ". Dolphins originate from " << origin << ". We live up to " << lifeSpan 
             << " years. Fun fact: " << funFact << "\n" << endl;
    }
};

int main() {
    Zebra zebra;
    zebra.set_value("Marty", 5, "Grass", "Africa", 25, "Every zebra has its own unique stripe pattern!");
    zebra.display();
    Dolphin dolphin;
    dolphin.set_value("Flipper", 8, "Fish", "Oceans", 40, "Dolphins Are Carnivores. They eat fish, squid, and crustaceans.");
    dolphin.display();
    return 0;
}