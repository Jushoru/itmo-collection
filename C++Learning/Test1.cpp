#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    system("chcp 1251");

    int x1, x2, x3, x4, x5, y1, y2, y3, y4, y5;
    double s;

    cout << "Введите координаты h1" << endl;
    cin >> x1 >> y1;
    cout << "Введите координаты h2" << endl;
    cin >> x2 >> y2;
    cout << "Введите координаты h3" << endl;
    cin >> x3 >> y3;
    cout << "Введите координаты h4" << endl;
    cin >> x4 >> y4;
    cout << "Введите координаты h5" << endl;
    cin >> x5 >> y5;

    //Дополнительные скобочки стоят для отслеживания корректности формулы
    //fabs() - функция нахождения модуля от числа
    s = 0.5*fabs(x1*y2+x2*y3+x3*y4+x4*y5+(x5*y1)-x2*y1-x3*y2-x4*y3-x5*y4-(x1*y5));

    cout << "S = " << s << endl;
}
/*
 Пример пятиугольника и его корректная площадь :
 1 2
 2 3
 4 5
 8 6
 9 1
 
 S=24
*/

