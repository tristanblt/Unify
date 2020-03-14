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
    float xpos, ypos, radsqr, xsqr;
    int x = _x + _radius;
    int y = _y + _radius;

    for (xpos = x - _radius; xpos <= x + _radius; xpos += 1/*0.1*/) {
        radsqr = pow(_radius, 2);
        xsqr = pow(xpos - x, 2);
        ypos = sqrt(abs(radsqr - xsqr));
        for (int i = rintf(-ypos) + y; i < rintf(ypos) + y; i++)
            mvaddch(rintf(xpos) / NCURSES_RATIO, i, ' ' | COLOR_PAIR(_colorPair));
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