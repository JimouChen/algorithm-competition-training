# include <iostream>
# include <cmath>

using namespace std;

class Point {
private:
    double X, Y;
public:
    Point(double a = 0, double b = 0) : X(a), Y(b) {}

    void SetPoint(double a = 0, double b = 0) {
        X = a;
        Y = b;
    }

    double GetX() {
        return X;
    }

    double GetY() {
        return Y;
    }

    friend double GetLength(Point &A, Point &B);
};

//�����߶γ���
double GetLength(Point &A, Point &B) {
    return sqrt(pow(A.GetX() - B.GetX(), 2) + pow(A.GetY() - B.GetY(), 2));
}

int main() {
    Point Pa(2, 2), Pb(4, 5);
    cout << "�����˵������λ�÷ֱ���:" << endl;
    cout << "Pa(" << Pa.GetX() << ", " << Pa.GetY() << ")" << endl;
    cout << "Pb(" << Pb.GetX() << ", " << Pb.GetY() << ")" << endl;

    cout << "����ĳ�����: " << GetLength(Pa, Pb);
    return 0;
}