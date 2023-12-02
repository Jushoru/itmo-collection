#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    system("chcp 1251");
    string line;
    string name = "YourPoem.txt";
    ofstream file(name);

    if (file.is_open()) {
        cout << "Введите стихотворение. Для завершения введите пустую строку:\n";

        while (true) {
            getline(cin, line);

            if (line.empty()) break;

            file << line << '\n';
        }

        file.close();
        cout << "Стих записан в файл " << name << endl;
    }
    else {
        cerr << "Ошибка открытия файла" << endl;
    }
}