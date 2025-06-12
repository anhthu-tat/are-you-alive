#include <iostream>
using namespace std;

class Time {
public:
    int hours;
    int minutes;
    int seconds;
    int daytime; // 0 for AM, 1 for PM
    Time() : hours(0), minutes(0), seconds(0), daytime(0) {}
    Time(int h, int m, int s, int d) : hours(h), minutes(m), seconds(s), daytime(d) {}

    Time operator ++() {
        seconds = seconds + 1;
        if (seconds >= 60) {
            seconds -= 60;
            minutes++;
        }
        if (minutes >= 60) {
            minutes -= 60;
            hours++;
        }
        if (hours >= 12) {
            hours -= 12;
            daytime = 1 - daytime;
        }
        return *this;
    }
   
    int operator ()(){
        int duration = ((hours + ((daytime == 0) ? 0 : 12)) * 3600) + (minutes * 60) + seconds;
        return duration;
    }

    Time operator +=(int b) {
        seconds += b;
        if (seconds >= 60) {
            minutes = minutes + seconds/60;
            seconds %= 60;
        }
        if (minutes >= 60) {
            hours = hours + minutes/60;
            minutes %= 60;
        }
        if (hours >= 12) {
            int toggle = hours / 12;
            daytime = toggle % 2 == 0 ? daytime : 1 - daytime;
            hours %= 12;
        }
        return *this;
    }
};

int main() {
    Time t1(7, 52, 23, 0); // 7:52:23 AM
    cout << "Initial Time: " << t1.hours << ":" << t1.minutes << ":" << t1.seconds << " " << (t1.daytime == 0 ? "AM" : "PM") << endl;

    ++t1; // Increment time by one second
    cout << "After Increment: " << t1.hours << ":" << t1.minutes << ":" << t1.seconds << " " << (t1.daytime == 0 ? "AM" : "PM") << endl;

    int duration = t1(); // Get total duration in seconds
    cout << "Total Duration in seconds: " << duration << endl;

    t1 += 120; // Add 120 seconds (2 minutes)
    cout << "After Adding 120 seconds: " << t1.hours << ":" << t1.minutes << ":" << t1.seconds << " " << (t1.daytime == 0 ? "AM" : "PM") << endl;

    return 0;
}
