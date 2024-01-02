#include <iostream>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics.hpp>
#pragma once


namespace graph {

    class Button {

        size_t x0, y0, x1, y1;
        sf::Texture texture;
        sf::Sprite sprite;

    public:
        Button(size_t x0, size_t x1, size_t y0, size_t y1, const char* image_loc);

        bool is_clicked(size_t x, size_t y);

        void on_click();

        void draw(sf::RenderWindow& window);
        
    };

    class SendButton: public Button {

    public:
        SendButton(size_t x0, size_t x1, size_t y0, size_t y1, const char* image_loc);

        void on_click();
    };
}
