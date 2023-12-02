#include <iostream>
#include <vector>
#include "Human.h"
#include "Student.h"
#include "Teacher.h"

using namespace std;

int main()
{
	system("chcp 1251");

	// Оценки cтудента
	vector<int> scores;
	// Добавление оценок студента в вектор
	scores.push_back(5);
	scores.push_back(3);
	scores.push_back(4);
	scores.push_back(4);
	scores.push_back(5);
	scores.push_back(3);
	scores.push_back(3);
	scores.push_back(3);
	scores.push_back(3);
	
	student* stud = new student("Петров", "Иван", "Алексеевич", scores);
	cout << stud->get_full_name() << endl;
	cout << "Средний балл : " << stud->get_average_score() << endl;

	unsigned int teacher_work_time = 40;
	teacher* tch = new teacher("Сергеев", "Дмитрий", "Сергеевич", teacher_work_time);
	cout << "\n" << tch->get_full_name() << endl;
	cout << "Количество часов: " << tch->get_work_time() << endl;

	// Указатель типа human, указывающий на объект класса student
	human* humOne = new student("Лядов", "Григорий", "Александрович", { 5, 4, 4, 3, 5, 5, 4, 5, 5 });
	cout << "\n" << humOne->get_full_name() << endl;
	// метод унаследован от класса human и является виртуальным, потому
	// будет вызвана соответствующая реализация метода из класса teacher.
	humOne->role();

	human* humTwo = new teacher("Долорес", "О'риордан", "Айлин", 62);
	cout << "\n" << humTwo->get_full_name() << endl;
	humTwo->role();

}
