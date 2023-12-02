#include <iostream>
#include <string>

using namespace std;

void sort(int resum[], int n) {
    for (int i = 0; i < n; i++) {
        int min = i;

        for (int j = i + 1; j < n; j++) {
            min = (resum[j] < resum[min]) ? j : min;
        }

        swap(resum[i], resum[min]);
    }
}

int summa(int resum[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += resum[i];
    }
    return sum;
}

int negative(int resum[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (resum[i] < 0) {
            sum += resum[i];
        }
    }
    return sum;
}

int positive(int resum[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (resum[i] > 0) {
            sum += resum[i];
        }
    }
    return sum;
}

int odd(int resum[], int n) {
    int sum = 0;
    for (int i = 1; i < n; i += 2) {
        sum += resum[i];
    }
    return sum;
}

int even(int resum[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i += 2) {
        sum += resum[i];
    }
    return sum;
}



int main()
{
    system("chcp 1251");
    const int n = 5;
    int mas[n];
    for (int i = 0; i < n; i++) {
        cout << "mas[" << i << "]=";
        cin >> mas[i];
    }

    cout << "Сумма всех чисел массива: " << summa(mas, n) << endl;
    cout << "Сумма всех отрицательных чисел массива: " << negative(mas, n) << endl;
    cout << "Сумма всех положительных массива: " << positive(mas, n) << endl;
    cout << "Сумма всех чисел с нечётным индексом в массиве: " << odd(mas, n) << endl;
    cout << "Сумма всех чисел с чётным индексом в массиве: " << even(mas, n) << endl;

    sort(mas, n);
    cout << "Отсортированный масив: ";
    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            cout << ' ';
        }
        cout << mas[i];
    }
    cout << endl;
}