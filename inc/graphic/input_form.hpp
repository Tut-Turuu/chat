#include <string>
#include <SFML/Graphics.hpp>

#pragma once

class InputForm {

    std::string content;
    size_t length;


public:

    InputForm();

    void debug();

    void draw(sf::RenderWindow& window, sf::Font& font);

    void append(char letter);

    std::string get_content();

    size_t get_length();
};

