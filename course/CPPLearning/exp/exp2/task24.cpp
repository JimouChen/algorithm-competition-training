#include <iostream>

using namespace std;

class Tea;

class Stu {
private:
    char *name;
    double score;
public:
    Stu(char *name, double score) : name(name), score(score) {}

    friend void showMassage(const Stu &, const Tea &);
};

class Tea {
private:
    char *name;
    char *position;
public:
    Tea(char *name, char *position) : name(name), position(position) {}

    friend void showMassage(const Stu &, const Tea &);

};

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