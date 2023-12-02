#include <iostream>
#include <cmath>
#include <tuple>

using namespace std;

// Использую tuple для возвращения корней и флага
tuple<double, double, bool> getRoots(int a, int b, int c) {
    double d = b * b - 4 * a * c;

    if (d < 0) {
        
        // В функции make_tuple сохраненные типы объектов автоматически
        // определяются компилятором, и их не требуется задавать явным образом.
        // Нет корней
        return make_tuple(0.0, 0.0, false);
    }
    else if (d == 0) {
        // Один корень
        double root = -b / (2.0 * a);
        return make_tuple(root, root, true);
    }
    else {
        // Два корня
        double root1 = (-b + sqrt(d)) / (2.0 * a);
        double root2 = (-b - sqrt(d)) / (2.0 * a);
        return make_tuple(root1, root2, true);
    }
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

    // Получаю результат в виде кортежа
    auto result = getRoots(a, b, c);

    // Извлекаю значения из кортежа
    double root1 = get<0>(result);
    double root2 = get<1>(result);
    bool hasRoots = get<2>(result);

    if (!hasRoots) cout << "Нет корней" << endl;
    else if (root1 == root2) cout << "x1 = x2 = " << root1 << endl;
    else cout << "x1 = " << root1 << ", x2 = " << root2 << endl;

    return 0;
}