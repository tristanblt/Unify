/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Rectangle
*/

#include "lib/ncurses/include/Graphical/Rectangle.hpp"
#include <ncurses.h>
#include "lib/ncurses/include/nCursesColors.hpp"

Rectangle::Rectangle():
_x(0),
_y(0),
_width(0),
_height(0),
_nColor(1),
_colorPair(1)
{
}

Rectangle::~Rectangle()
{
}

void Rectangle::draw(IWindow *w)
{
    for (int y = _y; y < _y + _height; y++)
        for (int x = _x; x < _x + _width; x++)
            mvaddch(y, x, ' ' | COLOR_PAIR(_colorPair));
}

void Rectangle::setPosition(Vector2 position)
{
    _x = position.x;
    _y = position.y / NCURSES_RATIO;
}

void Rectangle::setSize(Vector2 size)
{
    _width  = size.x;
    _height = size.y;// NCURSES_RATIO;
}

void Rectangle::setColor(Color color)
{
    color.r = color.r > 250 ? 250 : color.r < 0 ? 0 : color.r;
    color.g = color.g > 250 ? 250 : color.g < 0 ? 0 : color.g;
    color.b = color.b > 250 ? 250 : color.b < 0 ? 0 : color.b;
    init_color(_nColor, color.r * 4, color.g * 4, color.b * 4);
    init_pair(_colorPair, COLOR_WHITE, _nColor);
}