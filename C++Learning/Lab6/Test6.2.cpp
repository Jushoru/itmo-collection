#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    system("chcp 1251");
    const int N = 10;
    int a[N] = { 1, 25, 6, 32, 43, 5, 96, 23, 4, 55 };
    int min = 0; // для записи минимального значения
    int buf = 0; // для обмена значениями
    ofstream file("mas.txt"); // файл для записи

    if (file.is_open())
    {
        file << "Исходный массив: ";
        for (int i = 0; i < N; i++)
        {
            file << a[i] << ' ';
        }
        file << '\n';

        //Сортировка упражения 2, ПР 5
        for (int i = 0; i < N; i++)
        {
            min = i;
            for (int j = i + 1; j < N; j++)
                min = (a[j] < a[min]) ? j : min;
            if (i != min)
            {
                buf = a[i];
                a[i] = a[min];
                a[min] = buf;
            }
        }

        // Запись отсортированного массив
        file << "Отсортированный массив: ";
        // Цикл с перебором массива(foreach)
        for (int i : a) file << i << ' ';
        file.close();

        cout << "Массивы записаны в файл mas.txt." << endl;
    }
    else
    {
        cerr << "Ошибка открытия файла." << endl;
    }
}