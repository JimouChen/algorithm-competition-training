# include <iostream>
using namespace std;

class Rectangle {
protected:
    float length, width;
public:
    Rectangle(float l, float w);
    float area();
    void disp();
};

Rectangle::Rectangle(float l, float w) : length(l), width(w) {}

float Rectangle::area() {
    return length * width;
}

void Rectangle::disp() {
    cout << "The area of rectangle is: " << area() << endl;
}

class Cuboid : public Rectangle {
private:
    float height;
public:
    Cuboid(float l, float w, float h);
    float cal();
    void disp();
};

Cuboid::Cuboid(float l, float w, float h) : Rectangle(l, w), height(h) {}

float Cuboid::cal() {
    return length * width * height;
}

void Cuboid::disp() {
    Rectangle::disp();
    cout << "The volume of cuboid is: " << cal() << endl;
}

int main() {
    Cuboid cuboid(2, 3, 4);
    cuboid.disp();
    return 0;
}