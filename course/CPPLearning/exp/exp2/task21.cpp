# include <iostream>
#include <cstring>
using namespace std;

class Student {
private:
    int age;
    char *name;
public:
    Student();
    Student(int m, char *n = 0);
    ~Student();
    void SetName(int m, char *n = 0);
    int Getage();
    char *Getname();
};

Student::Student(int m, char *n) {
    age = m;
    if (n) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    } else name = 0;
}

Student::Student() {}

Student::~Student() {
    if (name) delete[]name;
}

void Student::SetName(int m, char *n) {
    age = m;
    if (n) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    } else n = 0;
}

int Student::Getage() {
    return age;
}

char *Student::Getname() {
    return name;
}

int main() {
    Student stuArray[3] = {Student(12, "Tom"), Student(13, "Peter")};
    stuArray[2].SetName(14, "Lucy");
    for (int i = 0; i < 3; i++)
        cout << "ĞÕÃû: " << stuArray[i].Getname() << " ÄêÁä: " << stuArray[i].Getage() << "Ëê" << endl;
    return 0;
}