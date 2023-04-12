#include <iostream>
#include <unistd.h>
#include <vector>
#include <SFML/Graphics.hpp>

int windowWidth = 1920;
int windowHeight = 1080;
double k = 600;
int x_zero = windowWidth / 2;
int y_zero = windowHeight / 2;

sf::Uint8* calcPixels ();
void calcPosition (int, int, int, int);

int main() {
    int rectX;
    int rectY;
    int rectX2;
    int rectY2;
    bool leftButtonPressed = false;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Algebraic fractal");
    sf::Image plainImage;
    sf::Texture plainTexture;
    sf::Sprite sprite;

    sf::Uint8* pixels = calcPixels();
    plainImage.create(windowWidth, windowHeight, pixels);
    plainTexture.loadFromImage(plainImage);
    sprite.setTexture(plainTexture);
    window.draw(sprite);
    sf::RectangleShape rectangle;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                leftButtonPressed = true;
                if (event.key.code == sf::Mouse::Left) {
                    auto pos = sf::Mouse::getPosition();
                    rectX = pos.x;
                    rectY = pos.y;
                }
            }
            if (event.type == sf::Event::KeyPressed) {
                windowWidth = 1920;
                windowHeight = 1080;
                k = 600;
                x_zero = windowWidth / 2;
                y_zero = windowHeight / 2;
                pixels = calcPixels();
                plainImage.create(windowWidth, windowHeight, pixels);
                plainTexture.loadFromImage(plainImage);
                sprite.setTexture(plainTexture);
                window.draw(sprite);
            }
            if (event.type == sf::Event::MouseButtonReleased) {
                leftButtonPressed = false;
                rectangle.setFillColor(sf::Color::Transparent);
                calcPosition(std::min(rectX, rectX2), std::min(rectY, rectY2),
                             std::max(rectX, rectX2), std::max(rectY, rectY2));
                pixels = calcPixels();
                plainImage.create(windowWidth, windowHeight, pixels);
                plainTexture.loadFromImage(plainImage);
                sprite.setTexture(plainTexture);
            }
        }
        auto pos = sf::Mouse::getPosition();
        rectX2 = pos.x;
        rectY2 = pos.y - 24;
        if (leftButtonPressed) {
            rectangle.setSize(sf::Vector2f(abs(rectX2 - rectX), abs(rectY2 - rectY)));
            rectangle.setFillColor(sf::Color(255, 100, 100, 100));
            rectangle.setPosition(std::min(rectX, rectX2), std::min(rectY, rectY2));
        }

        window.clear();
        window.draw(sprite);
        window.draw(rectangle);
        window.display();
    }

    return 0;
}

