# include<iostream>
# include<cmath>
using namespace std;
const double PI = 3.14;

class Point {
private:
    double x, y;
public:
    Point(double a = 0, double b = 0);
    ~Point();
    double GetX() const;
    double GetY() const;
    void Change(double a, double b);
};

Point::Point(double a, double b) : x(a), y(b) {}

Point::~Point() {};

double Point::GetX() const {
    return x;
}

double Point::GetY() const {
    return y;
}

void Point::Change(double a, double b) {
    x = a;
    y = b;
}

double area(const Point &a, const Point &b) {
    //获取两点之间的长度
    double length = sqrt((a.GetX() - b.GetX()) * (a.GetX() - b.GetX()) + (a.GetY() - b.GetY()) * (a.GetY() - b.GetY()));
    return PI * length * length;
}

int main() {
    const Point p1;
    Point p2(-5, 3);
    cout << "s1=" << area(p1, p2) << endl;
    p2.Change(56, 34);
    cout << "s2=" << area(p1, p2) << endl;

    return 0;
}