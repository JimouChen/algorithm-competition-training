# include<iostream>
# include <cstring>
using namespace std;

class Data {
private:
    char name[20];
    int age;
public:
    Data(char *n, int a);
    char *getName();
    int getAge();
    void print();
};

Data::Data(char *n, int a) {
    age = a;
    if (n) strcpy(name, n);
    else *name = 0;
}

char *Data::getName() {
    return name;
}

int Data::getAge() {
    return age;
}

void Data::print() {
    cout << "name: " << getName() << ", age: " << getAge() << endl;
}

class Teacher : public Data {
private:
    double sal;
public:
    Teacher(char *n, double s, int a);
    double getSalary();
    void print();
};

Teacher::Teacher(char *n, double s, int a) : Data(n, a), sal(s) {}

double Teacher::getSalary() {
    return sal;
}

void Teacher::print() {
    cout << "name: " << getName() << ", age: " << getAge() << endl;
    cout << "salary: " << getSalary() << endl << endl;
}

class Student : public Data {
private:
    char id[20];
public:
    Student(char *n, char *i, int a);
    char *getId();
    void print();
};

Student::Student(char *n, char *i, int a) : Data(n, a) {
    if (i) strcpy(id, i);
    else *id = 0;
}

char *Student::getId() {
    return id;
}

void Student::print() {
    cout << "name: " << getName() << ", age: " << getAge() << endl;
    cout << "id: " << getId() << endl << endl;
}

class Postgrad : public Student {
private:
    char dn[20];
public:
    Postgrad(char *n, char *i, char *d, int a);
    char *getDn();
    void print();
};

Postgrad::Postgrad(char *n, char *i, char *d, int a) : Student(n, i, a) {
    if (d) strcpy(dn, d);
    else *dn = 0;
}

char *Postgrad::getDn() {
    return dn;
}

void Postgrad::print() {
    cout << "name: " << getName() << ", age: " << getAge() << endl;
    cout << "id: " << getId() << endl;
    cout << "Dn: " << getDn() << endl<< endl;
}

class Tpost : public Teacher, public Postgrad {
public:
    Tpost(char *n, double s, char *i, char *d, int a);
    void print();
};

Tpost::Tpost(char *n, double s, char *i, char *d, int a) : Teacher(n, s, a), Postgrad(n, i, d, a) {}

void Tpost::print() {
    cout << "name: " << Teacher::getName() << ", age: " << Teacher::getAge() << endl;
    cout << "salary: " << getSalary() << endl;
    cout << "id: " << getId() << endl;
    cout << "Dn: " << getDn() << endl<< endl;
}

int main() {
    Teacher teacher("Tony", 6000, 21);
    Student student("Peter", "2021001123", 18);
    Postgrad postgrad("Bob", "2018004123", "Computer", 33);
    Tpost tpost("Jack", 100000, "2020005647", "Software", 24);

    teacher.print();
    student.print();
    postgrad.print();
    tpost.print();
    return 0;
}