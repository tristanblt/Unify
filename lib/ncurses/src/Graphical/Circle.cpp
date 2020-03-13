/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Circle
*/

#include "lib/ncurses/include/Graphical/Circle.hpp"

Circle::Circle():
_x(0),
_y(0),
_radius(0),
_nColor(2),
_colorPair(2)
{
}

Circle::~Circle()
{
}

void Circle::draw(IWindow *w)
{
    int a = 0;

    for(int y = -_radius; y <= _radius; y++) {
        for (int x = -_radius; x <= _radius; x++)
            if ( x * x + y * y < _radius * _radius &&
                (y == 0 || y < -((_radius)/(_radius / 2)) || y > (_radius / (_radius / 2))))
                mvaddch((_y + (y > (_radius / (_radius / 2)) || y == 0 ? y + a : y)) / 2.9, _x + x, ' ' | COLOR_PAIR(_colorPair));
        a -= ((y !=0 && y >= -((_radius) / (_radius/2))) && y <= (_radius / (_radius / 2)) ? 1 : 0);
    }
}

void Circle::setPosition(Vector2 position)
{
    _x = position.x;
    _y = position.y;
}

void Circle::setRadius(float size)
{
    _radius = static_cast<int>(size);
}

void Circle::setColor(Color color)
{
    color.r = color.r > 250 ? 250 : color.r < 0 ? 0 : color.r;
    color.g = color.g > 250 ? 250 : color.g < 0 ? 0 : color.g;
    color.b = color.b > 250 ? 250 : color.b < 0 ? 0 : color.b;
    init_color(_nColor, color.r * 4, color.g * 4, color.b * 4);
    init_pair(_colorPair, COLOR_WHITE, _nColor);
}