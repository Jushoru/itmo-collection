#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

template <typename T>
void Print(const T& container, const string& separator) {

    bool first = true;

    // Проходим по элементам контейнера и сохраняем текущий элемент в переменной element
    for (const auto& element : container) {

        if (!first) {
            cout << separator;
        }
        else {
            // Для первого элемента, чтобы перед ним не ставился разделитель
            first = false;
        }
        cout << element;
    }
    cout << endl;
}

int main() {
    vector<int> data = { 1, 2, 3};
    Print(data, ", ");

    list<string> strin = { "q", "w", "e", "r", "t", "y"};
    Print(strin, "-");
}