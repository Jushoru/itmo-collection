#include <iostream>
#include <string>

using namespace std;

int* maxv(int kc, int a[], int b[]) {
    int* result = new int[kc];
    for (int i = 0; i < kc; ++i) {
        result[i] =  max(a[i], b[i]);
    }
    return result;
}

int main()
{
    int a[] = { 1, 2, 3, 4, 1, 6, 7, 7 };
    int b[] = { 7, 7, 5, 4, 3, 9, 1, 3 };
    int kc = sizeof(a) / sizeof(a[0]);

    int* c;

    c = maxv(kc, a, b);
    for (int i = 0; i < kc; i++) {
        cout << c[i] << ' ';
    }
    cout <<  endl;

    delete[] c;
}
