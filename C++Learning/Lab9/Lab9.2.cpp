#include <iostream>
#include <stdexcept>

using namespace std;

class TimeError : public exception
{
public:
    // Конструктор класса принимает строку message, которая содержит сообщение об ошибке
    TimeError(const string& message) : message(message) {}
    // Данный метод возвращает указатель на константную C - строку, представляющую сообщение об ошибке
    // override - явно указывает на то, что этот метод переопределен из базового класса exception.
    const char* what() const override
    {
        return message.c_str();
    }

private:
    string message;
};

class Time
{
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
        if (h < 0 || m < 0 || s < 0 || m >= 60 || s >= 60)
        {
            throw TimeError("Время задано неверно!");
        }

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

    try {
        Time t1 = { 15, 43, 2 };
        // Time t2 = { 12, 32, 1 };
        Time t2 = { -1, 0, 0 };
        Time sum;

        cout << "Время №1 : ";
        t1.consoleTime();
        cout << "Время №2 ";
        t2.consoleTime();

        cout << "Сумма времени №1 и времени №2 ";
        sum = t1 + t2;
        sum.consoleTime();
    }
    catch (const TimeError& error) {
        cerr << "Ошибка: " << error.what() << endl;
    }


}
