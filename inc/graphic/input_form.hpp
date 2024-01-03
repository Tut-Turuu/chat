#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

#pragma once


namespace graph {

    class InputForm {

        std::vector<std::string> content;
        sf::Font font;
        size_t length;
        size_t x0, x1, y0, y1, offset;


    public:

        InputForm(size_t x0, size_t x1, size_t y0, size_t y1, size_t offset, sf::Font& font);

        void draw(sf::RenderWindow& window);

        void append(char letter);

        std::string get_content();

        size_t get_length();
    };
}

