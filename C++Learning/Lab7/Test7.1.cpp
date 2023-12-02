#include <iostream>

using namespace std;

struct Time {
    int hours;
    int minutes;
    int seconds;

    //В функцию addTime передается обект структуры Time
    //В функции константная ссылка на объект типа Time (other)
    Time addTime(const Time& other) const {
        Time result;
        result.hours = hours + other.hours;
        result.minutes = minutes + other.minutes;
        result.seconds = seconds + other.seconds;

        if (result.seconds >= 60) {
            result.minutes += result.seconds / 60;
            result.seconds %= 60;
        }
        if (result.minutes >= 60) {
            result.hours += result.minutes / 60;
            result.minutes %= 60;
        }

        return result;
    }

    Time subTime(const Time& other) const {
        Time result;
        result.hours = hours - other.hours;
        result.minutes = minutes - other.minutes;
        result.seconds = seconds - other.seconds;

        if (result.seconds < 0) {
            result.seconds += 60;
            result.minutes--;
        }
        if (result.minutes < 0) {
            result.minutes += 60;
            result.hours--;
        }

        return result;
    }
};

int main()
{
    system("chcp 1251");

    Time time1;
    Time time2;

    cout << "Правая граница по времени" << endl;
    cout << "введите часы: ";
    cin >> time1.hours;
    cout << "введите минуты: ";
    cin >> time1.minutes;
    cout << "введите секунды: ";
    cin >> time1.seconds;
    cout << "время: " << time1.hours << " часов, " << time1.minutes << " минут, " << time1.seconds << " секунд" << "\n" << endl;
    
    cout << "Левая граница по времени" << endl;
    cout << "введите часы: ";
    cin >> time2.hours;
    cout << "введите минуты: ";
    cin >> time2.minutes;
    cout << "введите секунды: ";
    cin >> time2.seconds;
    cout << "время: " << time2.hours << " часов, " << time2.minutes << " минут, " << time2.seconds << " секунд" << endl;

    Time sum = time1.addTime(time2);
    Time dif = time1.subTime(time2);

    cout << "Сумма по времени: " << sum.hours << " часов, " << sum.minutes << " минут, " << sum.seconds << " секунд" << endl;
    cout << "Разница по времени: " << dif.hours << " часов, " << dif.minutes << " минут, " << dif.seconds << " секунд" << endl;
}
