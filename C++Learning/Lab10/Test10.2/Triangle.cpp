#pragma once
#include "Dot.h"
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

class Triangle
{
public:
    Dot point1;
    Dot point2;
    Dot point3;

    Triangle(double x1, double y1, double x2, double y2, double x3, double y3)
        : point1(x1, y1), point2(x2, y2), point3(x3, y3) {}


    double area()
    {
        double side1 = point1.distanceTo(point2);
        double side2 = point2.distanceTo(point3);
        double side3 = point3.distanceTo(point1);

        double s = (side1 + side2 + side3) / 2.0;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    double printSideLengths()
    {
        system("chcp 1251");

        double side1 = point1.distanceTo(point2);
        double side2 = point2.distanceTo(point3);
        double side3 = point3.distanceTo(point1);

        cout << "Сторона 1: " << side1 << endl;
        cout << "Сторона 2: " << side2 << endl;
        cout << "Сторона 3: " << side3 << endl;

        return 0;
    }

    double calculatePerimeter()
    {
        double side1 = point1.distanceTo(point2);
        double side2 = point2.distanceTo(point3);
        double side3 = point3.distanceTo(point1);

        return side1 + side2 + side3;
    }
};
