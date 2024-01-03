#include <string>
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "input_form.hpp"


namespace graph {

    InputForm::InputForm(size_t x0, size_t x1, size_t y0, size_t y1, size_t offset, sf::Font& font) {
        this->x0 = x0;
        this->x1 = x1;
        this->y0 = y0;
        this->y1 = y1;
        this->offset = offset;

        length = 0;

        this->font = &font;
    }

    void InputForm::draw(sf::RenderWindow& window) {

        size_t x2, x3, y2, y3, y;

        x2 = x0 + offset;
        x3 = x1 - offset;
        y2 = y0 + offset;
        y3 = y1 - offset;

        y = y2;

        sf::Text buffer;
        buffer.setFont(*font);

        for (size_t i = 0; i < content.size(); i++) {
            buffer.setString(content[i]);
            buffer.setPosition(sf::Vector2f(x2, y));
            window.draw(buffer);
            y += 35;
        }
    }

    void InputForm::append(char letter) {

        if (content.size() == 0) {
            content.push_back("");
            content[content.size() - 1] += letter;

        } else {

            std::string tmp = content[content.size() - 1];
            tmp += letter;
            
            sf::Text buffer;
            buffer.setFont(*font);
            buffer.setString(tmp);

            if (buffer.getLocalBounds().width <= x1 - x0 - 2*offset) {
                content[content.size() - 1] = tmp;
            } else {
                content.push_back("");
                content[content.size() - 1] += letter;
            }

        }
    }
    void InputForm::pop_back() {
        if (content.size() != 0) {
            if (content[content.size() - 1].length() == 0) {
                content.pop_back();
            }
            if (content.size() != 0) {
                content[content.size() - 1].pop_back();
            }
        } 
    }

    std::string InputForm::get_content() {
        std::string tmp = "";
        for (size_t i = 0; i < content.size(); i++) {
            tmp +=  content[i];
        }
        content.clear();
        length = 0;
        return tmp;
    }
    


    size_t InputForm::get_length() {
        return length;
    }
}

