#pragma once

#include <exception>


namespace err {

    class WrongSizeErr : std::exception {
        void what();
    };

    class FontLoadErr : std::exception {
        void what();
    };
}