#include <iostream>
using namespace std; 

class Quadrilateral {
private: 
    double width; 
    double height;

public: 
    //constructor
    Quadrilateral(double w, double h) : width(w), height(h) {} // Constructor with parameters.
    Quadrilateral() : width(1), height(1) {}                   // Default constructor (width=1, height=1).
    virtual ~Quadrilateral() {}    
    
    //getters & setters
    double getWidth() const {return width;}
    double getHeight() const {return height;}
    void setWidth(double w) {width = w;}
    void setHeight(double h) {height = h;}

    //virtual methods 
    virtual double Area() const {return 0;}

    void print() {
        cout<<"Area: "<<Area();
    }

};

class Rectangle:public Quadrilateral {
public: 
    Rectangle(int w, int h) : Quadrilateral(w, h) {}

    double Area() const override {
        return getWidth()*getHeight();
    }
};

class Parallelogram:public Quadrilateral {

};

class Trapezium:public Quadrilateral {

};