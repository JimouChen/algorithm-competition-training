# include <iostream>
using namespace std;

float CheckAgeScore(int age, float score) {
    if (age < 16 || age > 25)
        throw age;
    if (score < 0 || score > 5)
        throw score;
    return score;
}

int main() {
    char name[20];
    int age;
    float score, checkAge = -1;
    cout << "请输入学生名字:";
    cin >> name;
    cout << "请输入学生年龄:";
    cin >> age;
    cout << "请输入学生分数:";
    cin >> score;
    try {
        checkAge = CheckAgeScore(age, score);
    }
    catch (int) {
        cout << "年龄输入范围错误" << endl;
    }
    catch (float) {
        cout << "分数输入范围错误" << endl;
    }
    if (checkAge >= 0) {
        cout << "该同学的名字是:" << name << endl;
        cout << "该同学的年龄是:" << age << endl;
        cout << "该同学的分数是:" << checkAge * 20 << endl;
    }
    return 0;
}