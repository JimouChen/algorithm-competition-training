# include <iostream>
using namespace std;

class Cylinder {
private:
    const double height;
    const double PI;
    double rad;
public:
    Cylinder(double h = 0, double r = 0);
    double getVolume();
};

Cylinder::Cylinder(double h, double r) : height(h), rad(r), PI(3.14) {}

double Cylinder::getVolume() {
    return height * PI * rad * rad;
}

int main() {
    Cylinder cylinder1(2.5, 3), cylinder2(4, 5);
    cout << "Բ����1�������: " << cylinder1.getVolume() << endl;
    cout << "Բ����2�������: " << cylinder2.getVolume() << endl;

    return 0;
}