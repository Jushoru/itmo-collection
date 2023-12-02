#pragma once
#include <iostream>
#include <cmath>
#include "Dot.h"

using namespace std;

class Triangle
{
private:
    Dot* point1;
    Dot* point2;
    Dot* point3; 

    // Приватный метод для вычисления длин сторон треугольника
    void calculateSideLengths(double& side1, double& side2, double& side3) const
    {
        side1 = point1->distanceTo(*point2);
        side2 = point2->distanceTo(*point3);
        side3 = point3->distanceTo(*point1);
    }
public:
    // Инициализация вершин треугольника
    Triangle(Dot* p1, Dot* p2, Dot* p3) : point1(p1), point2(p2), point3(p3) {}

    double area() const
    {
        double side1, side2, side3;
        calculateSideLengths(side1, side2, side3);

        double s = (side1 + side2 + side3) / 2;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    void printSideLengths() const
    {
        double side1, side2, side3;
        calculateSideLengths(side1, side2, side3);

        cout << "Сторона 1: " << side1 << endl;
        cout << "Сторона 2: " << side2 << endl;
        cout << "Сторона 3: " << side3 << endl;
    }

    double calculatePerimeter() const
    {
        double side1, side2, side3;
        calculateSideLengths(side1, side2, side3);

        return side1 + side2 + side3;
    }

};

int main()
{
    system("chcp 1251");
    
    // В данном случае используется агрегация, т.к. объекты Dot создаются отдельно
    // и по отдельности их может существовать сколько угодно
    cout << "Используется агрегация" << "\n" << endl;
    Dot p1(0, 0);
    Dot p2(3, 0);
    Dot p3(0, 4);
    Triangle triangle(&p1, &p2, &p3);

    cout << "Длины сторон:" << endl;
    triangle.printSideLengths();

    cout << "Периметр равен: " << triangle.calculatePerimeter() << endl;

    cout << "Площадь равна: " << triangle.area() << endl;

    return 0;
}