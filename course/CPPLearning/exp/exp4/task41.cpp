#include <iostream>
#include <cmath>
using namespace std;

class Point {
private:
    double x, y;
public:
    Point(double a, double b);
    Point(Point &p);
    double GetX();
    double GetY();
};

Point::Point(double a, double b) : x(a), y(b) {}

Point::Point(Point &p) {
    x = p.x;
    y = p.y;
}

double Point::GetX() {
    return x;
}

double Point::GetY() {
    return y;
}

class Line {
private:
    Point A, B;
    double length;
public:
    Line(Point &a, Point &b);
    double GetLength();
};

double Line::GetLength() {
    return sqrt(pow((A.GetX() - B.GetX()), 2) + pow(A.GetY() - B.GetY(), 2));
}

Line::Line(Point &a, Point &b) : A(a), B(b) {}

int main() {
    Point a(1, 3);
    Point b(2, 2);
    Line line(a, b);
    cout << "The length between a and b is :" << line.GetLength() << endl;
    return 0;
}