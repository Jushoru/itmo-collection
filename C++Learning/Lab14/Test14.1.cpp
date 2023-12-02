#include <iostream>

using namespace std;

template <typename T>
T averageMean(const T arr[], int n) {
    T x = 0;
    for (int i = 0; i < n; i++) {
        x += arr[i];
    }
    return x / n;
}

int main()
{
    int integ[] = {1, 2, 3, 4, 5, 6, 7 ,8};
    long longi[] = {54214525525232542, 3242352351516456, 45214525525232542 };
    double doubl[] = {255.345, 452.2, 64.2, 235};
    char chara[] = {1, 3, 4, 4, 2, 2};

    cout << "Integer: " << averageMean(integ, sizeof(integ) / sizeof(integ[0])) << endl;
    cout << "Long: " << averageMean(longi, sizeof(doubl) / sizeof(doubl[0])) << endl;
    cout << "Double: " << averageMean(doubl, sizeof(longi) / sizeof(longi[0])) << endl;
    cout << "Char: " << averageMean(chara, sizeof(chara) / sizeof(chara[0])) << endl;
}
