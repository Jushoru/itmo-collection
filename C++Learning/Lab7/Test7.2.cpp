#include <iostream>
#include <cmath>

using namespace std;

struct roots {
    double x1;
    double x2;
};

roots getRoots(int a, int b, int c) {
    roots result;

    double d = b * b - 4 * a * c;

    if (d < 0) {
        result.x1 = result.x2 = 0;
    }
    else if (d == 0) {
        result.x1 = result.x2 = -b / (2 * a);
    }
    else {
        result.x1 = (-b + sqrt(d)) / (2 * a);
        result.x2 = (-b - sqrt(d)) / (2 * a);
    }

    return result;
}

int main()
{
    system("chcp 1251");
    int a, b, c;

    cout << "Введите переменную a: ";
    cin >> a;
    cout << "Введите переменную b: ";
    cin >> b;
    cout << "Введите переменную c: ";
    cin >> c;

    roots rts = getRoots(a, b, c);

    if (rts.x1 == 0 && rts.x2 == 0) cout << "Нет корней" << endl;
    else if (rts.x1 == rts.x2) cout << "x1 = x2 = " << rts.x1 << endl;
    else cout << "x1 = " << rts.x1 << ", x2 = " << rts.x2 << endl;
}