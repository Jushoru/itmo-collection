#include <iostream>
#include <stdexcept>
#include <cmath> 

using namespace std;

class TriangleError : public exception
{
public:
    // Конструктор класса принимает строку message, которая содержит сообщение об ошибке
    TriangleError(const string& message) : message(message) {}

    // Данный метод возвращает указатель на константную C - строку, представляющую сообщение об ошибке
    // override - явно указывает на то, что этот метод переопределен из базового класса exception.
    const char* what() const override
    {
        return message.c_str();
    }

private:
    string message;
};


class  Triangle
{
public:
    Triangle(double a, double b, double c)
    {
        if (a + b <= c || a + c <= b || b + c <= a || a <= 0 || b <= 0 || c <= 0)
        {
            throw TriangleError("Треугольника с такими сторонами не существует.");
        }

        side_a = a;
        side_b = b;
        side_c = c;
    }

    double side_a;
    double side_b;
    double side_c;

    static double AreaOfTriangle(Triangle& tr) {
        double p = (tr.side_a + tr.side_b + tr.side_c) / 2.0;
        double area = sqrt(p * (p - tr.side_a) * (p - tr.side_b) * (p - tr.side_c));
        return area;
    }
};

int main()
{
    system("chcp 1251");

    try
    {
        Triangle tria1(3.0, 4.0, 5.0);
        cout << "Площадь треугольника: " << Triangle::AreaOfTriangle(tria1) << endl;
    }
    catch (const TriangleError& error)
    {
        cerr << "Ошибка: " << error.what() << endl;
    }
}
