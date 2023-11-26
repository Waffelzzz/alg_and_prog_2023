#include <cmath>

class Shape {
public:
    virtual double getPerimeter() const = 0;
};

class Rectangle : public Shape {
private:
    int length;
    int width;
public:
    Rectangle(int a, int b) : length(a), width(b) {}

    double getPerimeter() const override {
        return 2 * (length + width);
    }
};

class Circle : public Shape {
private:
    int radius;
    double PI = M_PI;
public:
    Circle(int r) : radius(r) {}

    double getPerimeter() const override {
        return 2 * PI * radius;
    }
};

class Triangle : public Shape {
private:
    int sideA;
    int sideB;
    int sideC;
public:
    Triangle(int a, int b, int c) : sideA(a), sideB(b), sideC(c) {}

    double getPerimeter() const override {
        if (sideA + sideB > sideC && sideA + sideC > sideB && sideB + sideC > sideA) {
            return sideA + sideB + sideC;
        }
        else {
            return 0;
        }
    }
};
