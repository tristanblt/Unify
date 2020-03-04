/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Rectangle
*/

#include "lib/sfml/include/Graphical/Rectangle.hpp"

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

void Rectangle::setPosition(int size)
{
    _rect->setPosition(size, size);
}

void Rectangle::setSize(int size)
{
    _rect->setSize(sf::Vector2f(size, size));

}