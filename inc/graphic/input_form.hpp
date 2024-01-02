#include <string>
#include <SFML/Graphics.hpp>

#pragma once


namespace graph {

    class InputForm {

        std::string content;
        size_t length;
        size_t x0, x1, y0, y1;


    public:

        InputForm(size_t x0, size_t x1, size_t y0, size_t y1);

        void debug();

        void draw(sf::RenderWindow& window, sf::Font& font);

        void append(char letter);

        std::string get_content();

        size_t get_length();
    };
}

