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
    cout << "ѧ����Ϣ:" << endl;
    cout << "ѧ������: " << stu.name << "  ѧ������: " << stu.score << endl;
    cout << "��ʦ��Ϣ:" << endl;
    cout << "��ʦ����: " << tea.name << "  ��ʦְ��: " << tea.position << endl;
}


int main() {
    Stu stu("����", 99.5);
    Tea tea("����", "����");
    showMassage(stu, tea);

    return 0;
}