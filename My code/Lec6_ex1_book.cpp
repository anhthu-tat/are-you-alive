#include <iostream>
using namespace std; 

class Book {
private: 
    string Author;
    string Title;
    string Format;
    double Price;
    int Year;
    string Publisher; 
public: 
    //getters
    string getAu() const {return Author;}
    string getTitle() const {return Title;}
    string getFormat() const {return Format;}
    double getPrice() const {return Price;}
    int getYear() const {return Year;}
    string getPub() const {return Publisher;}

    //setters
    void setAu(string author) { Author = author;}
    void setTtile(string title) {Title = title;}
    void setFormat(string format) {Format = format;}
    void setPrice(double price) {Price = price;}
    void setYear(int year) {Year = year;}
    void setPub(string publlisher) {Publisher = publlisher;}

    //constructor 
    Book(string a, string t, string f, double p, int y, string pub) : Author(a), Title(t), Format(f), Price(p), Year(y), Publisher(pub) {}
    
    //function 
    void Introduction() {
        cout<<"Book: "<<getTitle()<<endl;
        cout<<"Author: "<<getAu()<<endl;
        cout<<"Format: "<<getFormat()<<endl;
        cout<<"Price: $"<<getPrice()<<endl;
        cout<<"Year of Publication: "<<getYear()<<endl;
        cout<<"Publisher: "<<getPub()<<endl;
    }
};

int main () {
    Book book1 = Book("TAT", "CATBOOK", "Novel", 125.34, 2025, "VGU");
    book1.Introduction();
}