#include <iostream>
# include <cstring>
using namespace std;

class Date {
private:
    int year, month, day;
public:
    Date(int y, int m, int d);
    void print();
};

Date::Date(int y, int m, int d) : year(y), month(m), day(d) {}

void Date::print() {
    cout << "time:" << year << "-" << month << "-" << day << endl;
}

class Student {
private:
    char name[20];
    int score;
    Date bir;
public:
    Student(char *n, int s, int y, int m, int d);
    void print();//输出学生全部信息
};

Student::Student(char *n, int s, int y, int m, int d) : bir(y, m, d) {
    score = s;
    if (name) strcpy(name, n);
    else *name = 0;
}

void Student::print() {
    cout << "name:" << name << endl;
    cout << "score:" << score << endl;
    cout << "birthday:";
    bir.print();
}

int main() {
    Student student("Jack", 100, 2021, 2, 4);
    student.print();
    return 0;
}