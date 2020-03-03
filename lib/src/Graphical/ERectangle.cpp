/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ERectangle
*/

#include "lib/include/Graphical/ERectangle.hpp"

ERectangle::ERectangle(IRectangle *rect)
{
    _rect = rect;
    position = 0;
    size = 0;
}

ERectangle::~ERectangle()
{
    delete _rect;
}

IRectangle *ERectangle::getRectangle() const
{
    return (_rect);
}

// void ERectangle::setPosition(int size)
// {
//     //position
// }

// void ERectangle::setSize(int size)
// {

// }