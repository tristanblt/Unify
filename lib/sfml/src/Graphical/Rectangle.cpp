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
    _rect->setPosition(100, 100);
}

Rectangle::~Rectangle()
{
    delete _rect;
}

void Rectangle::draw(IWindow *w)
{
    dynamic_cast<Window *>(w)->getWindow()->draw(*_rect);
}
