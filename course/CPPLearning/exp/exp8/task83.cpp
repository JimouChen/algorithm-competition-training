#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;
const int N = 5;

struct Stu {
    char id[20];
    char name[20];
    char sex[10];
    int age;
};

istream &operator>>(istream &in, Stu &stu) {
    in >> stu.id >> stu.name >> stu.sex >> stu.age;
    return in;
}

ostream &operator<<(ostream &out, const Stu &student) {
    out << student.id << setw(10) << student.name << setw(10) << student.sex
        << setw(10) << student.age << endl;
    return out;
}

void readFile(char *filename) {
    ifstream in(filename);
    Stu student[N];

    for (int i = 0; i < N; i++) {
        in >> student[i];
        cout << student[i];
    }
    in.close();
}

int main() {
    readFile("student.txt");
    return 0;
}
