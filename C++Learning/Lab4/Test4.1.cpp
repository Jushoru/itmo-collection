#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int quad(double a, double b, double c, double& x1, double& x2) {
    double d = pow(b, 2) - 4 * a * c;
    if (d < 0) {
        return -1;
    }

    d = sqrt(d);
    if (d > 0) {
        x1 = (-b - d) / 2;
        x2 = (-b + d) / 2;
        return 1;
    }
    else {
        x1 = x2 = -b / 2;
        return 0;
    }
}

int main()
{
    system("chcp 1251");
    double a, b, c;
    double x1, x2;

    cout << "Введите коэффициенты квадратного уравнения ( a, b, c ) через пробел: ";
    cin >> a >> b >> c;

    int result = quad(a, b, c, x1, x2);
    if (result == 1) {
        cout << "Корни уравнения x1 = " << x1 << ", x2 = " << x2 << endl;
    }
    else if (result == 0) {
        cout << "Корень уравнения один x1 = x2 = " << x1 << endl;
    }
    else {
        cout << "Корней нет" << endl;
    }
}