# include <iostream>
# include <cmath>
using namespace std;

class Point {
private:
    double X, Y;
public:
    Point(double a = 0, double b = 0);
    void SetPoint(double a = 0, double b = 0);
    double GetX();
    double GetY();
    friend double GetLength(Point &A, Point &B);
};

Point::Point(double a, double b) : X(a), Y(b) {}

void Point::SetPoint(double a, double b) {
    X = a;
    Y = b;
}

double Point::GetX() {
    return X;
}

double Point::GetY() {
    return Y;
}

//�����߶γ���
double GetLength(Point &A, Point &B) {
    return sqrt(pow(A.GetX() - B.GetX(), 2) + pow(A.GetY() - B.GetY(), 2));
}

int main() {
    Point Pa(2, 2), Pb;
    Pb.SetPoint(4, 5);
    cout << "�����˵������λ�÷ֱ���:" << endl;
    cout << "Pa(" << Pa.GetX() << ", " << Pa.GetY() << ")" << endl;
    cout << "Pb(" << Pb.GetX() << ", " << Pb.GetY() << ")" << endl;
    cout << "�߶εĳ�����: " << GetLength(Pa, Pb);
    return 0;
}