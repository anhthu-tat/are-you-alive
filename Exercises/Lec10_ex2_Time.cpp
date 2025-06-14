#include <iostream>

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    // Default constructor
    Time() : hours(0), minutes(0), seconds(0) {}

    // Parameterized constructor
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

    // Display function
    void display() const {
        std::cout << "Time: " << hours << ":" << minutes << ":" << seconds << std::endl;
    }

    // Overloaded + operator
    Time operator+(const Time& t) {
        int totalSeconds = ((hours * 3600 + minutes * 60 + seconds) +
                            (t.hours * 3600 + t.minutes * 60 + t.seconds)) % (24 * 3600);
        return Time(totalSeconds / 3600, (totalSeconds % 3600) / 60, totalSeconds % 60);
    }

    // Overloaded > operator
    bool operator>(const Time& t) {
        if (hours != t.hours) return hours > t.hours;
        if (minutes != t.minutes) return minutes > t.minutes;
        return seconds > t.seconds;
    }

    // Overloaded = operator
    Time& operator=(const Time& t) {
        if (this != &t) {
            hours = t.hours;
            minutes = t.minutes;
            seconds = t.seconds;
        }
        return *this;
    }
};

int main() {
    Time t1(10, 30, 45);
    Time t2(5, 45, 15);

    // Display initial times
    t1.display();
    t2.display();

    // Add two times
    Time t3 = t1 + t2;
    t3.display();

    // Compare two times
    if (t1 > t2) {
        std::cout << "t1 is greater than t2" << std::endl;
    } else {
        std::cout << "t1 is not greater than t2" << std::endl;
    }
    
    // Assign t2 to t1
    t1 = t2;
    std::cout << "After assignment, t1: ";
    t1.display();

    return 0;
}