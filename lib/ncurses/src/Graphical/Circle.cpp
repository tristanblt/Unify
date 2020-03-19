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
_color({0, 0, 0, 255})
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
            dynamic_cast<Window *>(w)->drawBufferPixel(i, rintf(xpos), _color);
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
    _color = color;
}