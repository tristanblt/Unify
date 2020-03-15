/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Rectangle
*/

#include "lib/Vulkan/include/Graphical/Rectangle.hpp"

Rectangle::Rectangle()
{
    _rect = new sf::RectangleShape();
    _rect->setPosition(0, 0);
    _rect->setSize(sf::Vector2f(0, 0));
    _rect->setFillColor(sf::Color::White);
}

Rectangle::~Rectangle()
{
    delete _rect;
}

void Rectangle::draw(IWindow *w)
{
    dynamic_cast<Window *>(w)->getWindow()->draw(*_rect);
}

void Rectangle::setPosition(Vector2 position)
{
    _rect->setPosition(position.x, position.y);
}

void Rectangle::setSize(Vector2 size)
{
    _rect->setSize(sf::Vector2f(size.x, size.y));

}

void Rectangle::setColor(Color color)
{
    _rect->setFillColor(sf::Color(color.r, color.b, color.g, color.a));
}