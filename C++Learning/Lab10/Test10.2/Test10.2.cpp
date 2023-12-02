#pragma once
#include "Triangle.cpp"
#include <cmath>
#include <iostream>

using namespace std;

int main()
{
    system("chcp 1251");

    //
    cout << "Это композиция: " << "\n" << endl;

    // В данном случае используется композиция, т.к. объекты Dot существуют лишь в рамках
    // класса triangle и по отдельности не могут существовать
    Triangle triangle(3, 0, 0, 4, 0, 0);

    cout << "Длины сторон:" << endl;
    triangle.printSideLengths();

    cout << "Периметр равен: " << triangle.calculatePerimeter() << endl;

    cout << "Площадь равна: " << triangle.area() << endl;

    return 0;
}

