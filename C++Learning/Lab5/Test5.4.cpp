#include <iostream>
#include <string>
#include <cstring>

using namespace std;

//argc хранит количество аргументов командной строки
//`argv это массив указателей, который хранит все переданные аргументы командной строки
int main(int argc, char* argv[])
{
    system("chcp 1251");
    if (argc != 4) {
        cerr << argv[0] << " Запись должна быть следующего вида: -a/-m операнд1 операнд2" << endl;
        return 1;
    }

    const char* flag = argv[1];
    int oper1, oper2;

    if (strncmp(flag, "-a", 2) != 0 && strncmp(flag, "-m", 2) != 0) {
        cerr << "Неверный флаг. Используйте -a для сложения или -m для умножения" << endl;
        return 1;
    }

    try {
        //Перевод значений в числовой вид
        oper1 = stoi(argv[2]);
        oper2 = stoi(argv[3]);
    }
    catch (const invalid_argument& e) {
        cerr << "Один или оба операнда не являются целыми числами" << endl;
        return 1;
    }

    if (strncmp(flag, "-a", 2) == 0) {
        int sum = oper1 + oper2;
        cout << "Сумма: " << sum << endl;
    }
    else {
        int prod = oper1 * oper2;
        cout << "Произведение: " << prod << endl;
    }
}
//D:
//D:\Programming files\C++\Lab5\Test5.4\Debug\
//Test5.4.exe -m 32 145
