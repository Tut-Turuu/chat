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


        graph::InputForm input_form(100, 500, 100, 500, 10, font);
        graph::Button send_button(550, 580, 100, 130, "../assets/button.png");
        graph::Button shift_up(500, 530, 100, 130, "../assets/button.png");
        graph::Button shift_down(500, 530, 470, 500, "../assets/button.png");

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
                            size_t x = event.mouseButton.x;
                            size_t y = event.mouseButton.y;

                            if (send_button.is_clicked(x, y)) {
                                input_form.get_content();
                            } else if (shift_up.is_clicked(x, y)) {
                                input_form.shift_up();
                            } else if (shift_down.is_clicked(x, y)) {
                                input_form.shift_down();
                            }
                        }
                        break;

                    case sf::Event::KeyPressed:

                        if (event.key.code == 38) {
                            is_cap = !is_cap;
                        } else if (event.key.code == -1) {
                            is_cap = !is_cap;
                        } else if (event.key.code == 59) {
                            input_form.pop_back();
                        } else if (event.key.code == 58) {
                            input_form.get_content(); // implement with sockets networking later
                        } else { 
                            // here only char keys
                            input_form.append(ut::key_code_to_ascii(event.key.code, is_cap));
                        }

                        // std::cout << event.key.code << '\n';
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
            shift_up.draw(window);
            shift_down.draw(window);
            

            window.display();
            window.clear();

        }

    return 0;
}