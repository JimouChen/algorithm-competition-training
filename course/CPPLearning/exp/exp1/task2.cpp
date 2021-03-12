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
    cout << "������ѧ������:";
    cin >> name;
    cout << "������ѧ������:";
    cin >> age;
    cout << "������ѧ������:";
    cin >> score;
    try {
        checkAge = CheckAgeScore(age, score);
    }
    catch (int) {
        cout << "�������뷶Χ����" << endl;
    }
    catch (float) {
        cout << "�������뷶Χ����" << endl;
    }
    if (checkAge >= 0) {
        cout << "��ͬѧ��������:" << name << endl;
        cout << "��ͬѧ��������:" << age << endl;
        cout << "��ͬѧ�ķ�����:" << checkAge * 20 << endl;
    }
    return 0;
}