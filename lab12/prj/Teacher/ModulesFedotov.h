#ifndef MODULESFEDOTOV_H_INCLUDED
#define MODULESFEDOTOV_H_INCLUDED
#include <cmath>
class ClassLab12_Fedotov {
public:
    ClassLab12_Fedotov();
    ClassLab12_Fedotov(float a, float b);
    void setA(float a);
    void setB(float b);
    float getA();
    float getB();
    float getArea();
    float getPerimeter();
private:
    float a = 0.0;
    float b = 0.0;
};

ClassLab12_Fedotov::ClassLab12_Fedotov() {}

ClassLab12_Fedotov::ClassLab12_Fedotov(float a, float b) {
    this->a = a;
    this->b = b;
}

void ClassLab12_Fedotov::setA(float a) {
    this->a = a;
}

void ClassLab12_Fedotov::setB(float b) {
    this->b = b;
}

float ClassLab12_Fedotov::getA() {
    return a;
}

float ClassLab12_Fedotov::getB() {
    return b;
}

float ClassLab12_Fedotov::getArea() {
    return a * b;
}

float ClassLab12_Fedotov::getPerimeter() {
    return 2 * (a + b);
}

#endif // MODULESFEDOTOV_H_INCLUDED