#include <iostream>
#include <string>

using namespace std;

int transposition(int mas[], int size, int val) {
    for (int i = 0; i < size; ++i) {
        if (mas[i] == val) {
            if (i > 0) {
                swap(mas[i - 1], mas[i]);
            }
            return i;
        }
    }
    return -1;
}

int main()
{
    system("chcp 1251");
    int elem;
    int mas[] = { 1, 32, 323, 9, 14};
    int size = sizeof(mas) / sizeof(mas[0]);

    cout << "Введите искомый элемент: ";
    cin >> elem;

    for (int i = 0; i < size; ++i) {
        int ind = transposition(mas, size, elem);
        cout << "Индекс элемента в массиве: " << ind << endl;
        for (int i = 0; i < size; i++) {
            cout << mas[i] << ' ';
        }
    }
}
