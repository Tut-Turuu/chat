#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "input_form.hpp"




InputForm::InputForm() {

    content = "";
    length = 0;
}

void InputForm::debug() {
    std::cout << "String: " << content << '\n';
}

void InputForm::draw(sf::RenderWindow& window, sf::Font& font) {
    sf::Text buffer;
    buffer.setFont(font);

    size_t x = 100;
    size_t y = 100;

    for (size_t i = 0; i <= length / 20; i++) {
        buffer.setString(content.substr(i*20, 20));
        buffer.setPosition(sf::Vector2f(x, y));
        y += 40;
        window.draw(buffer);
        // std::cout << "Times: " << i << '\n';
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
