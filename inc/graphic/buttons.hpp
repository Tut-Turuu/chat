#include <iostream>
#pragma once


class Button {

    size_t x0, y0, x1, y1;

public:
    Button(size_t x0, size_t x1, size_t y0, size_t y1);

    bool is_clicked(size_t x, size_t y);

    virtual void event();
    
};

class SendButton : public Button {

public:

    void event(); 
};