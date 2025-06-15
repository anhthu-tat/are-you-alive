#include <iostream>
using namespace std;

class CSStudent{
    private:
        int Student_id;
        string Student_name;
        string Student_address;
        string Scholarship;
    public:
        // constructor
        CSStudent(int id, string name, string address, string scholar){
            Student_id = id;
            Student_name = name;
            Student_address = address;
            Scholarship = scholar;
        }

        // copy constructor
        CSStudent(const CSStudent& other ){
            Student_id = other.Student_id;
            Student_name = other.Student_name;
            Student_address = other.Student_address;
            Scholarship = other.Scholarship;
        }

        // destructor
        ~CSStudent(){}

        // setter 
        void setID(int id){
            Student_id = id;
        }

        void setName(string name){
            Student_name = name;
        }

        void setAddress(string address){
            Student_address = address;
        }

        void setScholar(string scholar){
            Scholarship = scholar;
        }

        // getter

        int getID(){
            return Student_id;
        }

        string getName(){
            return Student_name;
        }

        string getAddress(){
            return Student_address;
        }

        string getScholar(){
            return Scholarship;
        }

        //function

        void printInfo(){
            cout << "Student info:" << "\n" 
                 << "Name: " << Student_name << "\n" 
                 << "ID: " << Student_id << "\n" 
                 << "Address: " << Student_address << "\n" 
                 << "Scholar: " << Scholarship << endl;
        }
};