#include <iostream>
#include <string>

using namespace std;

double square(double a, double b, double c)
{
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

double square(double a)
{
    return 0.43301 * a * a;
}



int main()
{
    system("chcp 1251");

    int n;
    double a;
    double b;
    double c;

    cout << "Площадь какого треугольника необходимо посчитать?" << endl;
    cout << "1. Равностороннего" << endl;
    cout << "2. Разностороннего" << endl;
    cout << "Укажите цифру вашего выбора: ";
    cin >> n;

    cout << "Введите сторону a: ";
    cin >> a;
    if (n == 1) cout << square(a);
    else
    {
        cout << "Введите сторону b: ";
        cin >> b;
        cout << "Введите сторону c: ";
        cin >> c;
        cout << square(a, b, c);
    }


}
