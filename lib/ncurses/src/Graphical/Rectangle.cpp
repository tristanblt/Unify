/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Rectangle
*/

#include "lib/ncurses/include/Graphical/Rectangle.hpp"
#include <fstream>

Rectangle::Rectangle():
_x(0),
_y(0),
_width(0),
_height(0),
_color({0, 0, 0, 255})
{
}

Rectangle::~Rectangle()
{
}

void Rectangle::draw(IWindow *w)
{
    Color tmp = _color;

    _height -= 1;
    for (int y = _y; y < _y + _height; y++) {
        for (int x = _x; x < _x + _width; x++) {
            dynamic_cast<Window *>(w)->drawBufferPixel(x, y, _color);
        }
    }
}

void Rectangle::setPosition(Vector2 position)
{
    _x = static_cast<int>(position.x);
    _y = static_cast<int>(position.y);
}

void Rectangle::setSize(Vector2 size)
{
    _width  = static_cast<int>(size.x);
    _height = static_cast<int>(size.y);// NCURSES_RATIO;
}

void Rectangle::setColor(Color color)
{
    _color = color;
}