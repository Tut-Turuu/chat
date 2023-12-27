#include <string>
#include <SFML/Graphics.hpp>
#include "input_form.hpp"

sf::RenderWindow window;


class InputForm {

    std::string content;
    size_t length;

public:

    InputForm() {
        content = "";
        length = 0;
    }

    void draw() {
        sf::Text buffer;

        size_t x = 100, y = 100;

        for (size_t i = 0; i <= length / 20; i++) {
            buffer.setString(content.substr(i*20, 20));
            buffer.setPosition(x, y);
            y += 12;
            window.draw(buffer);
        }
    }

    void append(char letter) {
        content += letter;
    }
};