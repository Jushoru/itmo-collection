#include <iostream>
#include <string>

using namespace std;

bool Input(int& a, int& b) {
    cin >> a;
    cin >> b;

    if (!cin.good() || !cin.good()) {
        return false;
    }

    return true;
}

int main()
{
    system("chcp 1251");
    int a, b;

    cout << "Введите два числа через пробел: ";
    if(!Input(a,b))
    {
        cerr << "error";
        return 1;
    }
    int s = a + b;
    cout << "Сумма равна: " << s << endl;
    return 0;
}
