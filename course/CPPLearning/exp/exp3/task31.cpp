# include<iostream>
# include <cstring>
using namespace std;

class Student {
private:
    int age;
    char *name;
public:
    static int count;
    Student();
    Student(int m, char *n);
    ~Student();
    void Print() const;
};

int Student::count = 0;

Student::Student() {
    name = new char[strlen("NoName") + 1];
    strcpy(name, "NoName");
    age = 0;
    count++;
}

Student::~Student() {
    if (name) delete[] name;
    count--;
}

Student::Student(int m, char *n) {
    count++;
    age = m;
    if (n) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    } else *name = 0;
}

void Student::Print() const {
    cout << count << endl;
    cout << "Name=" << name << " , " << "age=" << age << endl;
}

int main() {
    cout << "count =" << Student::count << endl;
    Student s1, *p = new Student(23, "zhanghong");
    s1.Print();
    p->Print();
    delete p;
    s1.Print();
    Student Stu[4];
    cout << "count =" << Student::count << endl;
    return 0;
}