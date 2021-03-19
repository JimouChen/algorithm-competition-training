#include <iostream>
#include <cstring>
using namespace std;

class Tea;

class Stu {
private:
    char *name;
    double score;
public:
    Stu(char *n=0, double s=0);
    ~Stu();
    friend void showMassage(const Stu &, const Tea &);
};

Stu::Stu(char *n, double s) {
    score = s;
    if (n) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    } else *name = 0;
}

Stu::~Stu() {
    if (name) delete[]name;
}

class Tea {
private:
    char *name;
    char *position;
public:
    Tea(char *n=0, char *p=0);
    ~Tea();
    friend void showMassage(const Stu &, const Tea &);
};

Tea::Tea(char *n, char *p) {
    if (name) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    } else *name = 0;
    if (p) {
        position = new char[strlen(p) + 1];
        strcpy(position, p);
    } else *position = 0;
}

Tea::~Tea() {
    if (name) delete[]name;
    if (position) delete[]position;
}

void showMassage(const Stu &stu, const Tea &tea) {
    cout << "学生信息:" << endl;
    cout << "学生姓名: " << stu.name << "  学生分数: " << stu.score << endl;
    cout << "教师信息:" << endl;
    cout << "教师姓名: " << tea.name << "  教师职称: " << tea.position << endl;
}


int main() {
    Stu stu("张三", 99.5);
    Tea tea("李四", "教授");
    showMassage(stu, tea);
    return 0;
}

