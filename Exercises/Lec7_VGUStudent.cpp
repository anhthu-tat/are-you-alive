#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

class studentVgu {
private:
    // Personal information
    string name;
    string studentID;
    string major;
    string nationality;
    int age;
    int enrollmentYear;
    int currentSemester;

    // Academic information
    double gpa;
    string currentCourses[100];
    int courseCount = 0;
    int creditsCompleted;
    bool academicWarning;
    bool onScholarship;
    string scholarshipName;

    // Resources
    double mealCardBalance;
    int printingCredits;
    string borrowedBooks[100];
    int borrowedBookCount = 0;
    string dormRoom;

    // Mental/Physical
    int stressLevel;
    double sleepHours;
    int caffeineIntake;

    // Social
    string friends[20];
    int friendCount = 0;
    string clubMemberships[10];
    int clubCount = 0;
    double socialMediaHours;

    // Activity Log
    string recentActivities[100];
    int activityCount = 0;

public:
    // Parameterized Constructor
    studentVgu(string name, string studentID, string major, int enrollYear, 
        string nationality = "", int age = 0): name(name), studentID(studentID), major(major), nationality(nationality),age(age), enrollmentYear(enrollYear){
        currentSemester = 1;
        gpa = 1.5;
        mealCardBalance = 100.0;
        stressLevel = 30;
        sleepHours = 7.0;
        dormRoom = "Not assigned";
        academicWarning = false;
        onScholarship = true;
        scholarshipName = "DAAD";
        creditsCompleted = 30;
        printingCredits = 0;
        caffeineIntake = 0;
        socialMediaHours = 0;
    }

    // Default Constructor
    studentVgu() {
        name = "Unknown";
        studentID = "000000";
        major = "Undeclared";
        enrollmentYear = 0;
        currentSemester = 1;
        gpa = 5.0;
        mealCardBalance = 100.0;
        stressLevel = 30;
        sleepHours = 7.0;
        dormRoom = "Not assigned";
        academicWarning = false;
        onScholarship = false;
        scholarshipName = "None";
        creditsCompleted = 0;
        nationality = "";
        age = 0;
        printingCredits = 0;
        caffeineIntake = 0;
        socialMediaHours = 0;
    }

    // Getters and Setters
    void setName(string name) { this->name = name; }
    string getName() { return name; }

    void setStudentID(string studentID) { this->studentID = studentID; }
    string getStudentID() { return studentID; }

    void setMajor(string major) { this->major = major; }
    string getMajor() { return major; }

    void setEnrollmentYear(int year) { enrollmentYear = year; }
    int getEnrollmentYear() { return enrollmentYear; }

    void setGPA(double gpa) { 
        this->gpa = gpa; 
        checkScholarshipEligibility();
    }
    double getGPA() { return gpa; }

    int getCurrentSemester() { return currentSemester; }
    int getCreditsCompleted() { return creditsCompleted; }
    double getMealCardBalance() { return mealCardBalance; }
    int getStressLevel() { return stressLevel; }
    bool isOnScholarship() { return onScholarship; }
    string getScholarshipName() { return scholarshipName; }

    void setNationality(string nationality) { this->nationality = nationality; }
    string getNationality() { return nationality; }

    void setAge(int age) { this->age = age; }
    int getAge() { return age; }

    // Scholarship Check
    void checkScholarshipEligibility() {
        onScholarship = (gpa < 2.0);
        scholarshipName = onScholarship ? "DAAD" : "None";}

    // Academic Methods
    void attendClass(string course, int hours) {
        if (courseCount < 100) {
            currentCourses[courseCount++] = course;
            logActivity("Attended " + course + " for " + to_string(hours) + " hours");
        } else {
            cerr << "Cannot add more courses. Limit reached.\n";
        }
        stressLevel += hours * 2;
        sleepHours = max(0.0, sleepHours - 0.5 * hours);
        creditsCompleted += hours;  // Added credit accumulation
    }

    void takeExam(string course) {
        double performance = (rand() % 100 + stressLevel) / 200.0;
        gpa = (gpa + performance) / 2.0;
        academicWarning = (gpa >= 2.0);

        logActivity("Took exam: " + course + ". GPA updated to " + to_string(gpa));
        if (academicWarning) cout << "ACADEMIC WARNING!\n";
    }

    // Campus Life
    void rechargeMealCard(double amount) {
        mealCardBalance += amount;
        logActivity("Recharged meal card: +" + to_string(amount) + "k VND");
    }

    void rain(bool hasUmbrella) {
        if (hasUmbrella) {
            logActivity("Used umbrella during rain");
        } else {
            stressLevel = min(100, stressLevel + 40);
            logActivity("Got soaked in rain! Stress +40");
        }
    }

    // Social Activities
    void joinClub(string club) {
        if (clubCount < 10) {
            clubMemberships[clubCount++] = club;
            logActivity("Joined club: " + club);
        } else {
            cerr << "Cannot join more clubs. Limit reached.\n";
        }
        socialMediaHours += 2;
    }

    void vguFestEvent() {
        stressLevel = max(0, stressLevel - 25);
        mealCardBalance = max(0.0, mealCardBalance - 50);
        logActivity("Attended VGU Fest! Stress -25, Meal balance -50k");
    }

    // Status Display
    void displayStatus() {
        cout << "\n=== VGU Student Status ==="
             << "\nName: " << name
             << "\nMajor: " << major
             << "\nGPA: " << gpa
             << "\nStress: " << stressLevel << "/100"
             << "\nMeal Balance: " << mealCardBalance << "k"
             << "\nDorm: " << dormRoom
             << "\nClubs: ";

        for (int i = 0; i < clubCount; ++i) {
            cout << clubMemberships[i] << (i < clubCount-1 ? ", " : "");
        }
        cout << "\n==========================\n";
    }

    // Utilities
    void complainAboutDeadline() {
        stressLevel = min(100, stressLevel + 15);
        logActivity("Complained about deadlines. Stress +15");
    }

    void useVGUBus(string from, string to) {
        logActivity("Took bus from " + from + " to " + to);
        sleepHours += 0.25;
    }

    void displayRecentActivities() {
        cout << "\n=== Recent Activities ===\n";
        for (int i = 0; i < activityCount; ++i) {
            cout << "- " << recentActivities[i] << endl;
        }
    }

    //game mechanics!! Yippee
    void setCurrentSemester(int semester) { currentSemester = semester; }
    void setCreditsCompleted(int credits) { creditsCompleted = credits; }
    void setStressLevel(int level) { stressLevel = level; }

private:
    void logActivity(string message) {
        if (activityCount < 100) {
            recentActivities[activityCount++] = message;
        }
    }
};

int main() {
    srand(time(0));
    studentVgu student("Jiafei", "10423200", "Computer Science", 2023);
    student.setGPA(1.8);
    student.setCreditsCompleted(0);

    while (true) {
        cout << "\n=== VGU Student Life ===" << endl;
        cout << "1. Attend class\n2. Take exam\n3. Recharge meal card\n4. Join club\n"
             << "5. Attend VGU Fest\n6. Complain about deadlines\n7. Use VGU bus\n"
             << "8. Face rain\n9. Check status\n10. Show activities\n11. Quit\n";
        cout << "Choice: ";

        int choice;
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }
        cin.ignore();

        if (choice == 11) break;

        switch (choice) {
            case 1: {
                string course;
                int hours;
                cout << "Course name: ";
                getline(cin, course);
                cout << "Hours: ";
                cin >> hours;
                cin.ignore();
                student.attendClass(course, hours);
                break;
            }
            
            case 2: {
                string course;
                cout << "Exam course: ";
                getline(cin, course);
                student.takeExam(course);
                break;
            }

            case 3: {
                double amount;
                cout << "Recharge amount: ";
                cin >> amount;
                cin.ignore();
                student.rechargeMealCard(amount);
                break;
            }

            case 4: {
                string club;
                cout << "Club name: ";
                getline(cin, club);
                student.joinClub(club);
                break;
            }

            case 5:
                student.vguFestEvent();
                break;

            case 6:
                student.complainAboutDeadline();
                break;

            case 7: {
                string from, to;
                cout << "From: ";
                getline(cin, from);
                cout << "To: ";
                getline(cin, to);
                student.useVGUBus(from, to);
                break;
            }

            case 8: {
                char hasUmbrella;
                cout << "Do you have an umbrella? (y/n): ";
                cin >> hasUmbrella;
                cin.ignore();
                student.rain(hasUmbrella == 'y' || hasUmbrella == 'Y');
                break;
            }

            case 9:
                student.displayStatus();
                break;

            case 10:
                student.displayRecentActivities();
                break;

            case 11: 
                cout << "Exiting...\n";
                return 0;

            default: cout << "Invalid choice!\n";
        }

        // Semester advancement check
        int reqCredits = 30 * student.getCurrentSemester();
        if (student.getCreditsCompleted() >= reqCredits) {
            student.setCurrentSemester(student.getCurrentSemester() + 1);
            cout << "\nAdvanced to Semester " << student.getCurrentSemester() << "!\n";
            student.setStressLevel(min(100, student.getStressLevel() + 10));
        }

        // End conditions
        if (student.getStressLevel() >= 100) {
            cout << "STRESS OVERLOAD! GAME OVER!\n";
            break;
        }
        if (student.getGPA() >= 2.0) {
            cout << "LOST SCHOLARSHIP! GAME OVER!\n";
            break;
        }
        if (student.getCurrentSemester() > 8) {
            cout << "CONGRATULATIONS! YOU GRADUATED!\n";
            break;
        }
    }

    return 0;
}