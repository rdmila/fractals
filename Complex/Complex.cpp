#include "Complex.h"
#include <iostream>

Complex::Complex(double x, double y): x(x), y(y) {}

Complex Complex::sqr() {
    return Complex(x * x - y * y, 2 * x * y);
}

Complex Complex::operator+(const Complex& rhs) {
    return Complex(x + rhs.x, y + rhs.y);
}

std::ostream& operator<<(std::ostream &out, const Complex &number) {
    out << number.x << " " << number.y << std::endl;
    return out;
}

double Complex::abs2() {
    return x * x + y * y;
}

