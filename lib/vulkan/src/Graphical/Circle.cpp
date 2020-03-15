/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Circle
*/

#include "lib/Vulkan/include/Graphical/Circle.hpp"

Circle::Circle()
{
    _circle = new sf::CircleShape();
    _circle->setPosition(0, 0);
    _circle->setRadius(0);
    _circle->setFillColor(sf::Color::White);
}

Circle::~Circle()
{
    delete _circle;
}

void Circle::draw(IWindow *w)
{
    dynamic_cast<Window *>(w)->getWindow()->draw(*_circle);
}

void Circle::setPosition(Vector2 position)
{
    _circle->setPosition(position.x, position.y);
}

void Circle::setRadius(float size)
{
    _circle->setRadius(size);
}

void Circle::setColor(Color color)
{
    _circle->setFillColor(sf::Color(color.r, color.b, color.g, color.a));
}