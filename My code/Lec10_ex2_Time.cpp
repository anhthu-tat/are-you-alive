#include <iostream> // Required for input/output operations

class Time {
private:
    int hours;
    int minutes;
    int seconds;

    void printTwoDigits(int val) const {
        if (val < 10) {
            std::cout << '0';
        }
        std::cout << val;
    }

    // Helper function to validate if the given time components are within a valid 24-hour range.
    bool isValidTime(int h, int m, int s) const {
        return (h >= 0 && h <= 23 &&
                m >= 0 && m <= 59 &&
                s >= 0 && s <= 59);
    }

public:
    // Default constructor: Initializes the Time object to 00:00:00.
    Time() : hours(0), minutes(0), seconds(0) {}

    // Constructor with parameters: Initializes the Time object with specified hours, minutes, and seconds.
    // Includes validation to ensure time is within the 24-hour clock range.
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
        if (!isValidTime(h, m, s)) {
            std::cerr << "ERROR: Invalid time values provided. Time must be within 00:00:00 and 23:59:59.\n";
            // Terminates the program due to invalid input
            std::exit(1); // Information from outside the given sources.
        }
    }

    // Overloaded plus operator (+)
    // Adds two Time objects based on a 24-hour clock, handling rollovers for minutes and hours.
    // Operator overloading allows custom types to behave like built-in types
    Time operator+(const Time& other) const {
        int newSeconds = seconds + other.seconds;
        int newMinutes = minutes + other.minutes;
        int newHours = hours + other.hours;

        // Handle second rollovers into minutes
        newMinutes += newSeconds / 60;
        newSeconds %= 60;

        // Handle minute rollovers into hours
        newHours += newMinutes / 60;
        newMinutes %= 60;

        // Handle hour rollovers for a 24-hour clock
        newHours %= 24;

        // Ensure results are non-negative, in case intermediate modulo results could be negative
        // (though for positive sums, this is typically not an issue with C++'s % operator on positive numbers).
        if (newSeconds < 0) newSeconds += 60;
        if (newMinutes < 0) newMinutes += 60;
        if (newHours < 0) newHours += 24;

        return Time(newHours, newMinutes, newSeconds);
    }

    // Overloaded comparison operator (>)
    // Compares two Time objects. Returns true if the current object's time is strictly greater than 'other'.
    bool operator>(const Time& other) const {
        if (hours > other.hours) {
            return true;
        }
        if (hours < other.hours) {
            return false;
        }
        // If hours are equal, compare minutes.
        if (minutes > other.minutes) {
            return true;
        }
        if (minutes < other.minutes) {
            return false;
        }
        // If minutes are also equal, compare seconds.
        return seconds > other.seconds;
    }

    // Overloaded assignment operator (=) 
    // Assigns the values of one Time object to another
    Time& operator=(const Time& other) {
        if (this != &other) { // Check for self-assignment to prevent unintended operations
            hours = other.hours;
            minutes = other.minutes;
            seconds = other.seconds;
        }
        return *this; // Return a reference to the current object
    }

    // Display method to print the time in a formatted HH:MM:SS string.
    // Uses the custom `printTwoDigits` helper instead of `iomanip`.
    void display() const {
        printTwoDigits(hours);
        std::cout << ":";
        printTwoDigits(minutes);
        std::cout << ":";
        printTwoDigits(seconds);
        std::cout << std::endl;
    }
};

int main() {
    Time t1;

    // Test parameterized constructor
    Time t2(10, 30, 45);
    t2.display();

    Time t3(23, 59, 59); // Time near maximum values
    t3.display();

    std::cout << "\n--- Testing Assignment Operator (=) ---\n";
    Time t4;
    t4 = t2; // Assigns t2's values to t4
    std::cout << "t4 = t2: ";
    t4.display(); // Expected: 10:30:45

    Time t5(1, 2, 3);
    std::cout << "t5 (initial): ";
    t5.display();
    t5 = t5; // Test self-assignment
    std::cout << "t5 = t5 (self-assignment): ";
    t5.display(); // Expected: 01:02:03 (no change)

    std::cout << "\n--- Testing Plus Operator (+) ---\n";
    Time sum_t1_t2 = t1 + t2; // 00:00:00 + 10:30:45
    std::cout << "t1 + t2: ";
    sum_t1_t2.display(); // Expected: 10:30:45

    Time sum_t2_t3 = t2 + t3; // 10:30:45 + 23:59:59 (should involve rollovers)
                              // Manual calculation:
                              // Seconds: 45 + 59 = 104. 104 % 60 = 44 seconds. Carry 1 minute.
                              // Minutes: 30 + 59 + 1 (carry) = 90. 90 % 60 = 30 minutes. Carry 1 hour.
                              // Hours: 10 + 23 + 1 (carry) = 34. 34 % 24 = 10 hours.
                              // Result: 10:30:44
    std::cout << "t2 + t3: ";
    sum_t2_t3.display(); // Expected: 10:30:44

    Time t_mid(12, 0, 0);
    Time t_add_minutes(0, 30, 0);
    Time sum_mid_add = t_mid + t_add_minutes; // 12:00:00 + 00:30:00
    std::cout << "12:00:00 + 00:30:00: ";
    sum_mid_add.display(); // Expected: 12:30:00

    std::cout << "\n--- Testing Comparison Operator (>) ---\n";
    std::cout << "t2 (10:30:45) > t1 (00:00:00): " << (t2 > t1 ? "True" : "False") << std::endl; // Expected: True
    std::cout << "t1 (00:00:00) > t2 (10:30:45): " << (t1 > t2 ? "True" : "False") << std::endl; // Expected: False
    std::cout << "t2 (10:30:45) > t4 (10:30:45): " << (t2 > t4 ? "True" : "False") << std::endl; // Expected: False (they are equal)

    Time t_later(10, 30, 46);
    std::cout << "t_later (10:30:46) > t2 (10:30:45): " << (t_later > t2 ? "True" : "False") << std::endl; // Expected: True

    Time t_earlier_min(10, 29, 59);
    std::cout << "t_earlier_min (10:29:59) > t2 (10:30:45): " << (t_earlier_min > t2 ? "True" : "False") << std::endl; // Expected: False

    Time t_earlier_hour(9, 59, 59);
    std::cout << "t_earlier_hour (09:59:59) > t2 (10:30:45): " << (t_earlier_hour > t2 ? "True" : "False") << std::endl; // Expected: False

    return 0;
}