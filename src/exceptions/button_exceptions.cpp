#include <exception>
#include "button_exceptions.hpp"
#include <iostream>

namespace err {

    void WrongSizeErr::what() {
        std::cout << "ERROR: Wrong size of texture\n";
    }

    void FontLoadErr::what() {
        std::cout << "ERROR: Failed to load font form file\n";
    }
}
