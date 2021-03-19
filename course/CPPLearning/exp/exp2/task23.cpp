# include <iostream>
using namespace std;

class Cuboid {
private:
    double a, b, c;
public:
    Cuboid(double a, double b, double c);
    void setA(double a);
    void setB(double b);
    void setC(double c);
    double getA() const;
    double getB() const;
    double getC() const;
    double calculateCuboid();
};

Cuboid::Cuboid(double a, double b, double c) : a(a), b(b), c(c) {}

void Cuboid::setA(double a) {
    this->a = a;
}

void Cuboid::setB(double b) {
    this->b = b;
}

void Cuboid::setC(double c) {
    this->c = c;
}

double Cuboid::getA() const {
    return a;
}

double Cuboid::getB() const {
    return b;
}

double Cuboid::getC() const {
    return c;
}

double Cuboid::calculateCuboid() {
    return a * b * c;
}

int main() {
    Cuboid cuboid(2, 3, 4);
    cout << "������������߳��ȷֱ���:" << endl;
    cout << "a = " << cuboid.getA() << endl;
    cout << "b = " << cuboid.getB() << endl;
    cout << "c = " << cuboid.getC() << endl;
    cout << "���Ϊ: " << cuboid.calculateCuboid() << endl;
    //�޸�Ԫ��ֵ
    cuboid.setA(1.5);
    cuboid.setB(2.5);
    cuboid.setC(4.5);
    cout << "�޸�Ԫ��ֵ֮�󣬳�����������߳��ȷֱ���:" << endl;
    cout << "a = " << cuboid.getA() << endl;
    cout << "b = " << cuboid.getB() << endl;
    cout << "c = " << cuboid.getC() << endl;
    cout << "���Ϊ: " << cuboid.calculateCuboid() << endl;
    return 0;
}