#include "Color.h"

Color::Color()
{
    //ctor
}

Color::~Color()
{
    //dtor
}

Color::Color(int r, int g, int b)
{
    this->r = r;
    this->g = g;
    this->b = b;
}

void Color::modificar_color(int r, int g, int b)
{
    this->r = r;
    this->g = g;
    this->b = b;
}

bool Color::operator<(const Color & color_a) const
{
    if (this->r != color_a.obtener_RED()) {
        return this->r  < color_a.obtener_RED();
    }
    else if (this->g != color_a.obtener_GREEN()) {
        return this->g < color_a.obtener_GREEN();
    }
    else {
        return this->b < color_a.obtener_BLUE();
    }
}

int Color::obtener_BLUE() const
{
    return this->b;
}

int Color::obtener_GREEN() const
{
    return this->g;
}

int Color::obtener_RED() const
{
    return this->r;
}
