#include "buttons.hpp"




Button::Button(size_t x0, size_t x1, size_t y0, size_t y1) {
    this->x0 = x0;
    this->x1 = x1;
    this->y0 = y0;
    this->y1 = y1;
}

bool Button::is_clicked(size_t x, size_t y) {
    if ((x0 <= x && x <= x1) && (y0 <= y && y <= y1))
        return true;
    return false;
}

void Button::event() {
    throw "Abstract class";
}


void SendButton::event() {
    
}
