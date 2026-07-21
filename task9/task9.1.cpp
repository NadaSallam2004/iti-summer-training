#include <iostream>
#include <cmath>
using namespace std;

class Shape {
public:
    virtual float getArea() { return 0; }
    virtual float getPerimeter() { return 0; }
    virtual ~Shape() {}
};

class Circle : public Shape {
protected:
    float radius;
public:
    Circle(float r) : radius(r) {}
    float getArea() override { return 3.14159f * radius * radius; }
    float getPerimeter() override { return 2 * 3.14159f * radius; }
};

class Semicircle : public Circle {
public:
    Semicircle(float r) : Circle(r) {}
    float getArea() override { return (3.14159f * radius * radius) / 2; }
    float getPerimeter() override { return 3.14159f * radius + 2 * radius; }
};

class Rectangle : public Shape {
protected:
    float length, width;
public:
    Rectangle(float l, float w) : length(l), width(w) {}
    float getArea() override { return length * width; }
    float getPerimeter() override { return 2 * (length + width); }
};

class Square : public Rectangle {
public:
    Square(float side) : Rectangle(side, side) {}
    float getArea() override { return length * width; }
    float getPerimeter() override { return 4 * length; }
};

class Triangle : public Shape {
protected:
    float base, height;
    float sideA, sideB, sideC;
public:
    Triangle(float b, float h) : base(b), height(h), sideA(0), sideB(0), sideC(0) {}
    float getArea() override { return 0.5f * base * height; }
    float getPerimeter() override { return sideA + sideB + sideC; }
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(float side)
        : Triangle(side, (sqrt(3.0f) / 2)* side) {
        sideA = sideB = sideC = side;
    }
    float getArea() override { return (sqrt(3.0f) / 4) * sideA * sideA; }
    float getPerimeter() override { return 3 * sideA; }
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(float equalSide, float base)
        : Triangle(base, sqrt(equalSide* equalSide - (base * base) / 4)) {
        sideA = sideB = equalSide;
        sideC = base;
    }
    float getArea() override { return 0.5f * base * height; }
    float getPerimeter() override { return sideA + sideB + sideC; }
};

int main() {
    Circle c(5); cout << "Circle Area: " << c.getArea() << endl;
    Semicircle sc(5); cout << "Semicircle Area: " << sc.getArea() << endl;
    Rectangle r(4, 6); cout << "Rectangle Area: " << r.getArea() << endl;
    Square sq(5); cout << "Square Area: " << sq.getArea() << endl;
    Triangle t(6, 4); cout << "Triangle Area: " << t.getArea() << endl;
    EquilateralTriangle et(4); cout << "Equilateral Area: " << et.getArea() << endl;
    IsoscelesTriangle it(5, 6); cout << "Isosceles Area: " << it.getArea() << endl;
    return 0;
}
