/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Rectangle
*/

#include "lib/ncurses/include/Graphical/Rectangle.hpp"

Rectangle::Rectangle():
_x(0),
_y(0),
_width(0),
_height(0),
_nColor(1),
_colorPair(0)
{
}

Rectangle::~Rectangle()
{
}

void Rectangle::draw(IWindow *w)
{
    (void)w;
    for (int y = _y; y < _y + _height; y++)
        for (int x = _x; x < _x + _width; x++)
            mvaddch(y, x, ' ' | COLOR_PAIR(_colorPair));
}

void Rectangle::setPosition(Vector2 position)
{
    _x = static_cast<int>(position.x);
    _y = static_cast<int>(position.y);
}

void Rectangle::setSize(Vector2 size)
{
    _width  = static_cast<int>(size.x);
    _height = static_cast<int>(size.y);
}

void Rectangle::setColor(Color color)
{
    int tmp;

    color.r = color.r > 250 ? 250 : color.r < 0 ? 0 : color.r;
    color.g = color.g > 250 ? 250 : color.g < 0 ? 0 : color.g;
    color.b = color.b > 250 ? 250 : color.b < 0 ? 0 : color.b;
    tmp = nCursesColors::colorExists(color);
    if (tmp != -1) {
        _colorPair = tmp;
        _nColor = tmp;
    } else {
        _colorPair = nCursesColors::addColor(color);
        _nColor = _colorPair;
        init_color(_nColor, color.r * 4, color.g * 4, color.b * 4);
        init_pair(_colorPair, COLOR_WHITE, _nColor);
    }
}