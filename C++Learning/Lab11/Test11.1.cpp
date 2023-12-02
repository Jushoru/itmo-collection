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
    const char* what() const noexcept override
    {
        return message.c_str();
    }

private:
    string message;
};

// Данное исключение выбрасывается в случае, когда происходит попытка выполнить операцию
// вычитания (-) для двух объектов класса Time, и результат этой операции оказывается отрицательным.
class TimeValueError : public runtime_error
{
public:
    TimeValueError(const char* message) : runtime_error(message) {}
};

class Time
{
private:
    int hours;
    int minutes;
    int seconds;

    //нормализация времени
    void normalize() {
        int totalSeconds = getTotalSeconds();

        hours = totalSeconds / 3600;
        minutes = (totalSeconds % 3600) / 60;
        seconds = totalSeconds % 60;
    }

public:
    // Инициализация значений времени по умолчанию
    Time() : hours(0), minutes(0), seconds(0)
    {
    }

    Time(int h, int m, int s)
    {
        if (h < 0 || m < 0 || s < 0 || m >= 60 || s >= 60)
        {
            throw TimeError("Неправильные значения времени");
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

    // Это дружественная функция, перегружающая оператор +
    // для сложения числа типа double и объекта класса Time.
    friend Time operator+(double num, const Time& timeObj);

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
    //Возвращает общее количество секунд
    int getTotalSeconds() const
    {
        return hours * 3600 + minutes * 60 + seconds;
    }
    // Перегруженный оператор сравнения для двух объектов класса Time
    bool operator<(const Time& other) const {
        return getTotalSeconds() < other.getTotalSeconds();
    }
    // Установка времени на основании общего количества секунд
    void setTimeFromSeconds(int totalSeconds) {
        hours = totalSeconds / 3600;
        minutes = (totalSeconds % 3600) / 60;
        seconds = totalSeconds % 60;
        normalize();
    }

    //  Перегружен оператор + для сложения двух объектов класса Time
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
    //  Перегружен оператор + для сложения времени и числа типа double
    Time operator+(double secondsToAdd) const {
        Time result = *this;
        result.seconds += secondsToAdd;
        result.normalize();
        return result;
    }

    // Перегружен оператор - для вычитания времени.
    Time operator-(const Time& other) const {
        Time result;

        int thisSeconds = getTotalSeconds();
        int otherSeconds = other.getTotalSeconds();

        if (thisSeconds < otherSeconds) {
            throw TimeValueError("Невозможно вычесть большее время из меньшего.");
        }

        int diffSeconds = thisSeconds - otherSeconds;

        result.hours = diffSeconds / 3600;
        result.minutes = (diffSeconds % 3600) / 60;
        result.seconds = diffSeconds % 60;

        result.normalize();

        return result;
    }
};
// ?
Time operator+(double num, const Time& curr) {
    Time result = curr;
    int totalSec = result.getTotalSeconds();
    totalSec += static_cast<int>(num);
    result.setTimeFromSeconds(totalSec);
    return result;
}



int main()
{
    setlocale(LC_ALL, "ru");
    try {
        Time t2 = { 2, 7, 11 };
        Time t1 = { 3, 55, 36 };
        Time sub = t1 - t2;
        Time td = t1 + 3543;
        Time another_td = 324.3 + t2;
        Time sum;

        cout << "Время №1: ";
        t1.consoleTime();
        cout << "Время №2: ";
        t2.consoleTime();

        cout << "\n" << "Сумма времени №1 и времени №2: ";
        sum = t1 + t2;
        sum.consoleTime();
        
        cout << "Разность времени №1 и времени №2 : ";
        sub.consoleTime();

        cout << "Time + double ";
        td.consoleTime();

        cout << "double + Time ";
        another_td.consoleTime();

        cout << "Сравнение времени №1 и времени №2" << endl;
        if (t1 < t2) {
            cout << "№1 < №2" << endl;
        }
        else {
            cout << "№1 >= №2" << endl;
        }
    }
    catch (const TimeError& error) {
        cerr << "Ошибка: " << error.what() << endl;
    }
    catch (const TimeValueError& error) {
        cerr << "Невозможно вычесть из большего времени меньшее" << endl;
    }


}
