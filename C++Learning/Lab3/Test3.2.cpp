#include <cmath>
#include <iostream>

using namespace std;

double fPow(double n) {
    return pow(n, 1.0 / 3.0);
}

double fForm(double n, int iter_count) {
    double result = n;
    for (int i = 0; i < iter_count; ++i) {
        result = (n / pow(result, 2) + 2 * result) / 3;
    }
    return result;
}

int main() {
    system("chcp1251");

    double n;
    int iter_count;

    cout << "Введите число: ";
    cin >> n;
    cout << "Введите количество итераций: ";
    cin >> iter_count;

    cout << "Pow: " << fPow(n) << endl;
    cout << "IterFormula: " << fForm(n, iter_count) << endl;
}
