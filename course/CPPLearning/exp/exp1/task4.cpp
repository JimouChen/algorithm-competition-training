#include <iostream>
# include <cstring>
using namespace std;

double area(double a, double b, char *s);//�󳤷��κ�������
double area(double a, char *s);//�������κ�Բ��
const double PI = 3.14;

int main() {
    double width = 1.0, length = 2.0, side = 3.0, triLength = 6.0, height = 2.0, r = 4.0;
    char rectangle[50] = "rectangle", square[50] = "square", triangle[50] = "triangle", round[50] = "round";
    cout << "�����ε������:" << area(width, length, rectangle) << endl;
    cout << "�����ε������:" << area(side, square) << endl;
    cout << "�����ε������:" << area(triLength, height, triangle) << endl;
    cout << "Բ�ε������:" << area(r, round) << endl;
    return 0;
}

double area(double a, double b, char *s) {
    if (!strcmp(s, "triangle"))
        return a * b / 2;
    else if (!strcmp(s, "rectangle"))
        return a * b;
}


double area(double a, char *s) {
    if (!strcmp(s, "round"))
        return a * a * PI;
    else if (!strcmp(s, "square"))
        return a * a;
}
