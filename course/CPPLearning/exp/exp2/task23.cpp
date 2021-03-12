# include <iostream>

using namespace std;

class Cuboid {
private:
    double a, b, c;
public:
    Cuboid(double a, double b, double c) : a(a), b(b), c(c) {}

    void setA(double a) {
        this->a = a;
    }

    void setB(double b) {
        this->b = b;
    }

    void setC(double c) {
        this->c = c;
    }

    double getA() const {
        return a;
    }

    double getB() const {
        return b;
    }

    double getC() const {
        return c;
    }

    double calculateCuboid() {
        return a * b * c;
    }
};

int main() {
    Cuboid cuboid(2, 3, 4);
    cout << "长方体的三条边长度分别是:" << endl;
    cout << "a = " << cuboid.getA() << endl;
    cout << "b = " << cuboid.getB() << endl;
    cout << "c = " << cuboid.getC() << endl;
    cout << "体积为: " << cuboid.calculateCuboid() << endl;
    return 0;
}