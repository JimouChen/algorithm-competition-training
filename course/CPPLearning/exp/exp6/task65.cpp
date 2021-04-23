# include <iostream>
using namespace std;

class Person {
public:
    virtual void display() = 0;
};

class Teacher : virtual public Person {
public:
    void display();
};

void Teacher::display() {
    cout << "this is teacher" << endl;
}

class Student : virtual public Person {
public:
    void display();
};

void Student::display() {
    cout << "this is student" << endl;
}

class Tstu : public Teacher, public Student {
public:
    void display();
};

void Tstu::display() {
    cout << "this is Tstu" << endl;
}

class Employee : public Person {
public:
    void display();
};

void Employee::display() {
    cout << "this is employee" << endl;
}

int main() {
    Person *person;
    Teacher teacher;
    Student student;
    Tstu tstu;
    Employee employee;

    person = &teacher;
    person->display();
    person = &student;
    person->display();
    person = &tstu;
    person->display();
    person = &employee;
    person->display();
    return 0;
}