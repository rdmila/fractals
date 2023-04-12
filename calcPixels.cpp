#include <SFML/Graphics.hpp>
#include "Complex/Complex.h"

extern int windowWidth;
extern int windowHeight;
extern double k;
extern int x_zero;
extern int y_zero;
const double R = 1.50197192317588;
const int iterationsNumber = 200;
const Complex C = {-0.74543, 0.11301};

void calcPosition(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int dxz = x_zero - (x1 + x2) / 2;
    int dyz = y_zero - (y1 + y2) / 2;
    double k2 = dx > dy ? windowWidth * k / dx : windowHeight * k / dy;
    x_zero += dxz * k2 / k;
    y_zero += dyz * k2 / k;
    k = k2;
}

Complex getCoordinates (int x, int y) {
    double compX = (double)(x - x_zero) / k;
    double compY = (double)(y - y_zero) / k;
    return Complex(compX, compY);
}

sf::Color getColor (Complex z0) {
    Complex z = z0;
    for (int i = 0; i < iterationsNumber; ++i) {
        z = z.sqr() + C;
        if (z.abs2() > R) {
            return sf::Color(10 * i + 50, i, 2 * i , 255);
        }
    }
    return sf::Color::White;
}

sf::Uint8* calcPixels () {
    auto pixels = new sf::Uint8 [4 * windowWidth * windowHeight];
    int back = 0;
    for (int y = 0; y < windowHeight; ++y) {
        for (int x = 0; x < windowWidth; ++x) {
            Complex c = getCoordinates(x, y);
            sf::Color color = getColor(c);
            pixels[back] = color.r;
            pixels[back + 1] = color.g;
            pixels[back + 2] = color.b;
            pixels[back + 3] = color.a;
            back += 4;
        }
    }
    return pixels;
}

