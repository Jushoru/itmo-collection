#include <iostream>
#include <map>
#include <string>

using namespace std;

class GradeMap
{
private:
    map<string, int> gradeMap;
public:
    void addGrade(const string& name, int grade) {
        gradeMap[name] = grade;
    }
    void displayGrades() const {
        for (const auto& entry : gradeMap) {
            cout << "Студент: " << entry.first << "; оценка: " << entry.second << endl;
        }
    }
};

int main() {
    system("chcp 1251");

    GradeMap gradeMap;

    gradeMap.addGrade("Рик", 5);
    gradeMap.addGrade("Юнатан", 4);
    gradeMap.addGrade("Дмитрий", 2);

    gradeMap.displayGrades();

    return 0;
}
