#include "buttons.hpp"
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics.hpp>
#include "button_exceptions.hpp"

namespace graph {

    Button::Button(size_t x0, size_t x1, size_t y0, size_t y1, const char* image_loc) {
        this->x0 = x0;
        this->x1 = x1;
        this->y0 = y0;
        this->y1 = y1;

        if (!texture.loadFromFile(image_loc)) {
            throw err::TextureLoadErr();
        }
        sf::Vector2u size = texture.getSize();

        if (size.x != x1 - x0 && size.y != y1 - y0) {
            throw err::WrongSizeErr();
        }

        sprite.setTexture(texture);
        sprite.setPosition(sf::Vector2f(x0, y0));
        // sprite.setScale(sf::Vector2f(x1 - x0, y1 - y0));
    }

    bool Button::is_clicked(size_t x, size_t y) {
        if ((x0 <= x && x <= x1) && (y0 <= y && y <= y1))
            return true;
        return false;
    }

    void Button::draw(sf::RenderWindow& window) {
        window.draw(sprite);
    }
}
