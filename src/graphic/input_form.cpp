#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "input_form.hpp"


namespace graph {


    InputForm::InputForm(size_t x0, size_t x1, size_t y0, size_t y1) {
        this->x0 = x0;
        this->x1 = x1;
        this->y0 = y0;
        this->y1 = y1;

        content = "";
        length = 0;
    }

    void InputForm::debug() {
        std::cout << "String: " << content << '\n';
    }

    void InputForm::draw(sf::RenderWindow& window, sf::Font& font) {
        sf::Text buffer;
        buffer.setFont(font);
        size_t x2, x3, y2;

        size_t offset = 10;
        x2 = x0 + offset;
        x3 = x1 - offset;
        y2 = y0 + offset;
        // y3 = y1 - offset;

        size_t current_symbol = 0;

        size_t y = y2;

        for (size_t i = 1; i <= length; i++) {
            buffer.setString(content.substr(current_symbol, i - current_symbol));
            if (buffer.getLocalBounds().width < (x3 - x2)) {
                buffer.setPosition(sf::Vector2f(x2, y));
                continue;
            } else {
                current_symbol = i - 1;
                y += 30;
            }

            window.draw(buffer);

            // buffer.setString(content.substr(i*20, 20));
            // buffer.setPosition(sf::Vector2f(x, y));
            // y += 40;
            // window.draw(buffer);

            // std::cout << buffer.getLocalBounds().height << ' ' << buffer.getLocalBounds().width << '\n';
            // // std::cout << "Times: " << i << '\n';
        }
    }

    void InputForm::append(char letter) {
        content += letter;
        length++;
    }

    std::string InputForm::get_content() {
        std::string tmp = content;
        content = "";
        length = 0;
        return tmp;
    }

    size_t InputForm::get_length() {
        return length;
    }
}

