#include <iostream>
#include <string>

using namespace std;

int funct(int n, int depth)
{
    if (n == 0) return 0;
    return funct(n - 1, depth + 1) + 5 * depth;
}

int main()
{
    system("chcp 1251");
    int n;

    cout << "Введите разряд: ";
    cin >> n;

    cout << "Сумма равна: " << funct(n, 1) << endl;
}
