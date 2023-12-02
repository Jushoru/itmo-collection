#include <iostream>

using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    // Конструктор по умолчанию, который вызывается
    // при создании объекта этого класса без передачи аргументов.
    Time() : hours(0), minutes(0), seconds(0)
    {
    }

    Time(int h, int m, int s)
    {
        int bigMinutes = 0;
        int bigHours = 0;

        if (s >= 60)
        {
            bigMinutes = s / 60;
            s %= 60;
        }

        if (m >= 60)
        {
            bigHours = m / 60;
            m %= 60;
        }

        hours = h + bigHours;
        minutes = m + bigMinutes;
        seconds = s;
    }
    int getHours() const {
        return hours;
    }
    int getMinutes() const {
        return minutes;
    }
    int getSeconds() const {
        return seconds;
    }

    void consoleTime() const {
        cout << "\n" << hours << ":" << minutes << ":" << seconds << endl;
    }

    Time operator+(const Time& other) const {
        Time result;
        result.seconds = seconds + other.seconds;
        result.minutes = minutes + other.minutes;
        result.hours = hours + other.hours;

        if (result.seconds >= 60) {
            result.seconds -= 60;
            result.minutes += 1;
        }

        if (result.minutes >= 60) {
            result.minutes -= 60;
            result.hours += 1;
        }

        return result;
    }

};


int main()
{
    system("chcp 1251");
    Time t1 = { 15, 43, 2 };
    Time t2 = { 12, 32, 1 };
    Time sum;

  
}
