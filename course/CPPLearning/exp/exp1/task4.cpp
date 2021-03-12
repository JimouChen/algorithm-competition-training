#include <iostream>
# include <cstring>
using namespace std;

double area(double a, double b, char *s);//求长方形和三角形
double area(double a, char *s);//求正方形和圆形
const double PI = 3.14;

int main() {
    double width = 1.0, length = 2.0, side = 3.0, triLength = 6.0, height = 2.0, r = 4.0;
    char rectangle[50] = "rectangle", square[50] = "square", triangle[50] = "triangle", round[50] = "round";
    cout << "长方形的面积是:" << area(width, length, rectangle) << endl;
    cout << "正方形的面积是:" << area(side, square) << endl;
    cout << "三角形的面积是:" << area(triLength, height, triangle) << endl;
    cout << "圆形的面积是:" << area(r, round) << endl;
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
