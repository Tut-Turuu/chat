#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "input_form.hpp"

// class A {
//     void draw() {
        
//     }
// };

int main() {

        bool is_cap = false;

        sf::ContextSettings settings;
        settings.antialiasingLevel = 100;

        sf::Font font;

        if (!font.loadFromFile("/usr/share/fonts/opentype/cantarell/Cantarell-Bold.otf")) {
            throw "font error";
        }

        sf::Text text;

        text.setFont(font);
        text.setPosition(sf::Vector2f(200,200));

        // WINDOW
        sf::RenderWindow window(sf::VideoMode(800, 780), "Chat", sf::Style::Default, settings);

        window.setFramerateLimit(140);


        // SHAPES
        sf::CircleShape circle(100);
        circle.setFillColor(sf::Color::Green);

        sf::RectangleShape rect(sf::Vector2f(100,50));
        rect.setFillColor(sf::Color::Red);


        InputForm input_form;

        // MAIN LOOP
        while (window.isOpen())
        {

            // window.setPosition(sf::Vector2i(10, 10));
            
            sf::Event event;
            while (window.pollEvent(event))
            {
                switch (event.type) {

                    case sf::Event::Closed:
                        window.close();
                        break;

                    case sf::Event::MouseButtonPressed:
                        if (event.mouseButton.button == sf::Mouse::Left) {

                        }
                        break;

                    case sf::Event::KeyPressed:

                        // std::cout << event.key.code << '\n';

                        if (event.key.code == 38) {
                            is_cap = true;
                        } else if (event.key.code == 58 && input_form.get_length() > 0) {
                            // NOT FULLY IMPLEMENTED
                            input_form.get_content();
                        
                        } else if (event.key.code >= 0 && event.key.code <= 26){
                            input_form.append(event.key.code + (is_cap ? 65: 97));
                        } else {
                            input_form.append(event.key.code);
                        }
                        input_form.debug();
                        break;

                    case sf::Event::KeyReleased:
                        if (event.key.code == 38) {
                            is_cap = false;
                        }
                        break;


                    default:
                        break;
                }
            }
            

            input_form.draw(window, font);
            

            window.display();
            window.clear();

        }

    return 0;
}