#include <iostream> 
#include <string>
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
    //Getters
    string getAuthor() const { return Author; }
    string getTitle() const { return Title; }
    string getFormat() const { return Format; }
    double getPrice() const { return Price; }
    int getYear() const { return Year;}
    string getPublisher() const { return Publisher; }

    //Setters
    void setAuthor(const string& author) { Author = author; }
    void setTitle(const string& title) { Title = title; }
    void setFormat(const string& format) { Format = format; }
    void setPrice(double price) { Price = price; }
    void setYear(int year) { Year = year; }
    void setPublisher(const string& publisher) { Publisher = publisher; }

    //constructor 
    Book(string author, string title, string format, double price, int year, string publisher){
        Author = author;
        Title = title;
        Format = format;
        Price = price;
        Year = year;
        Publisher = publisher;
    }

    //method
    void Introduce(){
        cout<<"Book: "<<getTitle()<<endl;
        cout<<"Author: "<<getAuthor()<<endl;
        cout<<"Type: "<<getFormat()<<endl;
        cout<<"Price: "<<getPrice()<<endl;
        cout<<"Year of Publishcation: "<<getYear()<<endl;
        cout<<"Publisher: "<<getPublisher()<<endl;
    }
};

int main(){
    Book book1 = Book("TAT", "Cattor", "Novel", 125.43, 2025, "NTL");
    book1.getAuthor();
    book1.Introduce();
}