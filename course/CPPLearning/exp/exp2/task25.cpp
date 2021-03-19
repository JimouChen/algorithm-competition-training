#include <iostream>
#include <cstring>
using namespace std;

class Student {
private:
    char name[21];
    double dailyScore1, dailyScore2, midScore, finalScore, resScore;
    char level;
public:
    Student();
    Student(char *n, double dailyScore1, double dailyScore2, double midScore, double finalScore,
            char level = 'B');//等级默认是B
    ~Student();
    void Evaluate();//计算学生成绩和等级
    void Input();//输入学生信息
    void Output();//输出学生信息
    void setDailyScore1(double dailyScore1);
    void setDailyScore2(double dailyScore2);
    void setMidScore(double midScore);
    void setFinalScore(double finalScore);
    void setResScore(double resScore);
};

Student::Student() {}

Student::~Student() {}

Student::Student(char *n, double dailyScore1, double dailyScore2, double midScore, double finalScore,
                 char level) {
    if (name)strcpy(name, n);
    else *name = 0;
    dailyScore1 = dailyScore1;
    dailyScore2 = dailyScore2;
    midScore = midScore;
    finalScore = finalScore;
}


void Student::Evaluate() {
    resScore = 0.25 * 5 * (dailyScore1 + dailyScore2) + 0.25 * midScore + 0.5 * finalScore;
    if (resScore >= 90)level = 'A';
    else if (resScore >= 80)level = 'B';
    else if (resScore >= 70)level = 'C';
    else if (resScore >= 60)level = 'D';
    else level = 'E';
}

void Student::Input() {
    cout << "student name = ";
    cin >> name;
    cout << "dailyScore1 = ";
    cin >> dailyScore1;
    cout << "dailyScore2 = ";
    cin >> dailyScore2;
    cout << "midScore = ";
    cin >> midScore;
    cout << "finalScore = ";
    cin >> finalScore;
    cout << endl;
}

void Student::Output() {
    cout << endl << "student name = " << name;
    cout << ", dailyScore1 = " << dailyScore1;
    cout << ", dailyScore2 = " << dailyScore2;
    cout << ", midScore = " << midScore;
    cout << ", finalScore =" << finalScore;
    cout << ", resScore = " << resScore;
    cout << ", level = " << level << endl;
}

void Student::setDailyScore1(double dailyScore1) {
    Student::dailyScore1 = dailyScore1;
}

void Student::setDailyScore2(double dailyScore2) {
    Student::dailyScore2 = dailyScore2;
}

void Student::setMidScore(double midScore) {
    Student::midScore = midScore;
}

void Student::setFinalScore(double finalScore) {
    Student::finalScore = finalScore;
}

void Student::setResScore(double resScore) {
    Student::resScore = resScore;
}


int main() {
    Student Array[5];
    int i;
    for (i = 0; i < 5; i++) {
        Array[i].Input();
        Array[i].Evaluate();
    }
    for (i = 0; i < 5; i++) Array[i].Output();
    return 0;
}