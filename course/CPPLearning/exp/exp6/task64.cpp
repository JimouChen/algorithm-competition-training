#include <iostream>
using namespace std;
const double pi = 3.14159;

class Container {
protected:
    double radius;
public:
    Container(double r);
    virtual double surface_area() = 0;
    virtual double volume() = 0;
    virtual void display() = 0;
};

Container::Container(double r) : radius(r) {}

class Cube : public Container {
public:
    Cube(double r);
    double surface_area();
    double volume();
    void display();
};

Cube::Cube(double r) : Container(r) {}

double Cube::surface_area() {
    return 6 * radius * radius;
}

double Cube::volume() {
    return radius * radius * radius;
}

void Cube::display() {
    cout << "Cube:" << endl;
    cout << "radius: " << radius << endl;
    cout << "area: " << surface_area() << endl;
    cout << "volume: " << volume() << endl;
}


class Sphere : public Container {
public:
    Sphere(double r);
    double surface_area();
    double volume();
    void display();
};

Sphere::Sphere(double r) : Container(r) {}

double Sphere::surface_area() {
    return 4 * pi * radius * radius;
}

double Sphere::volume() {
    return pi * radius * radius * radius * 4 / 3;
}

void Sphere::display() {
    cout << "Sphere" << endl;
    cout << "radius: " << radius << endl;
    cout << "area: " << surface_area() << endl;
    cout << "volume: " << volume() << endl;
}

class Cylinder : public Container {
private:
    double height;
public:
    Cylinder(double r, double h);
    double surface_area();
    double volume();
    void display();
};

Cylinder::Cylinder(double r, double h) : Container(r), height(h) {}

double Cylinder::surface_area() {
    return 2* pi * radius * radius + 2 * pi * radius * height;
}

double Cylinder::volume() {
    return pi * radius * radius * height;
}

void Cylinder::display() {
    cout << "Cylinder:" << endl;
    cout << "radius: " << radius << endl;
    cout << "height: " << height << endl;
    cout << "area: " << surface_area() << endl;
    cout << "volume: " << volume() << endl;
}

int main() {
    Container *container;
    Cube cube(5);
    Sphere sphere(5);
    Cylinder cylinder(5, 6);

    container = &cube;
    container->display();
    container = &sphere;
    container->display();
    container = &cylinder;
    container->display();

    return 0;
}