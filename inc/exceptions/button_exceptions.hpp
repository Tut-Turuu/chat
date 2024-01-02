#pragma once

#include <exception>


namespace err {

    class WrongSizeErr : std::exception {
        void what();
    };

    class TextureLoadErr : std::exception {
        void what();
    };
}