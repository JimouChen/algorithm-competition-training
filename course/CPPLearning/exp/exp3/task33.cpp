# include <iostream>
using namespace std;

class Student {
private:
    double score;
    static double total;
    static int count;
public:
    void scoreTotal(double s);
    static int person();
    static double average();
};

double Student::total = 0;
int Student::count = 0;

void Student::scoreTotal(double s) {
    score = s;
    total += score;
    count++;
}

int Student::person() {
    return count;
}

double Student::average() {
    return total / count;
}

int main() {
    Student student[3];//�������ɸ�ѧ��
    student[0].scoreTotal(92);
    student[1].scoreTotal(94);
    student[2].scoreTotal(96);
    cout << "ѧ��������:" << Student::person() << endl;
    cout << "ѧ����ƽ������:" << Student::average() << endl;

    return 0;
}