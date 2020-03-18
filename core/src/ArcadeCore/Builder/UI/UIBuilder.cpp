/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Builder
*/

#include "core/include/ArcadeCore/Builder/Builder.hpp"

/* --------------------------------- buttons -------------------------------- */

bool Builder::buttonDraw(std::string name)
{
    if (_buttons.find(name) == _buttons.end())
        throw std::invalid_argument("Could not find button");
    return (_buttons[name]->draw(this));
}

void Builder::addButton(IButton *button, std::string name)
{
    _buttons[name] = button;
}