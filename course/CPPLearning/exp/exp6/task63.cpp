#include<iostream>
using namespace std;

class Shape {
public:
    virtual void display() = 0;
};

class Rectangle : public Shape {
public:
    virtual void display();
};

void Rectangle::display() {
    cout << "shape is rectangle" << endl;
}

class Circle : public Shape {
public:
    virtual void display();
};

void Circle::display() {
    cout << "shape is circle" << endl;
}

int main() {
    Shape *shape;
    Rectangle rectangle;
    Circle circle;

    shape = &rectangle;
    shape->display();
    shape = &circle;
    shape->display();

    return 0;
}