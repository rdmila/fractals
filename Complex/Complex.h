#pragma once
#include <ostream>

class Complex {
public:
    Complex (double, double);

    Complex sqr();
    double abs2();

    Complex operator+(const Complex&);
    friend std::ostream& operator<<(std::ostream &out, const Complex &number);

private:
    double x;
    double y;
};

