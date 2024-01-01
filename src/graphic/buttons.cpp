#include "buttons.hpp"
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics.hpp>


Button::Button(size_t x0, size_t x1, size_t y0, size_t y1, const char* image_loc) {
    this->x0 = x0;
    this->x1 = x1;
    this->y0 = y0;
    this->y1 = y1;

    image.loadFromFile(image_loc);
}

bool Button::is_clicked(size_t x, size_t y) {
    if ((x0 <= x && x <= x1) && (y0 <= y && y <= y1))
        return true;
    return false;
}

void Button::on_click() {
    throw "Abstract class";
}

void Button::draw(sf::RenderWindow& window) {

    sf::Vector2u vec = image.getSize();
    size_t x = vec.x, y = vec.y;

    sf::RectangleShape pixel;
    
    for (size_t i = 0; i < x; i++) {
        for (size_t j = 0; j < y; j++) {
            pixel.setPosition(sf::Vector2f(i, j));
            pixel.setFillColor(image.getPixel(i, j));
            window.draw(pixel);
        }
    }
}

void SendButton::on_click() {
    
}
