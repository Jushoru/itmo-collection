#include <iostream>
#include <string>

using namespace std;

string convert(int a)
{
	if (a == 0) return "";
	return convert(a / 2) + to_string(a % 2);
}

int main()
{
	system("chcp 1251");
	int n;
	cout << "Введите десятичное число: ";
	cin >> n;

	cout << convert(n);
}
