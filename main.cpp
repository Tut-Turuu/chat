#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "input_form.hpp"
#include "buttons.hpp"
#include "to_ascii.hpp"



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
        // sf::CircleShape circle(100);
        // circle.setFillColor(sf::Color::Green);

        // sf::RectangleShape rect(sf::Vector2f(100,50));
        // rect.setFillColor(sf::Color::Red);


        graph::InputForm input_form(100, 500, 100, 200, 10, font);
        graph::SendButton send_button(10, 40, 100, 130, "../assets/button.png");
        

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

                        if (event.key.code == 38) {
                            is_cap = !is_cap;
                        } else if (event.key.code == -1) {
                            is_cap = !is_cap;
                        } else { // here only char keys
                            input_form.append(ut::key_code_to_ascii(event.key.code, is_cap));
                        }

                        std::cout << event.key.code << '\n';
                        break;

                    case sf::Event::KeyReleased:
                        if (event.key.code == 38) {
                            is_cap = !is_cap;
                        }
                        break;


                    default:
                        break;
                }
            }
            
            // button.draw(window);
            input_form.draw(window);
            send_button.draw(window);
            

            window.display();
            window.clear();

        }

    return 0;
}