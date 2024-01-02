#include <exception>
#include "button_exceptions.hpp"
#include <iostream>

namespace err {

    void WrongSizeErr::what() {
        std::cout << "ERROR: Wrong size of texture\n";
    }

    void TextureLoadErr::what() {
        std::cout << "ERROR: Failed to load texture form file\n";
    }
}
