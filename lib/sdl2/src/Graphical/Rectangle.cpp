/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Rectangle
*/

#include "lib/sdl2/include/Graphical/Rectangle.hpp"

Rectangle::Rectangle()
{
    _rect = new SDL_Rect();
    _rect->x = 0;
    _rect->y = 0;
    _rect->w = 0;
    _rect->h = 0;
}

Rectangle::~Rectangle()
{
    delete _rect;
}

void Rectangle::draw(IWindow *w)
{
    SDL_SetRenderDrawColor(dynamic_cast<Window *>(w)->getRenderer(), _color.r, _color.g, _color.b, _color.a);
    SDL_RenderFillRect(dynamic_cast<Window *>(w)->getRenderer(), _rect);
}

void Rectangle::setPosition(Vector2 position)
{
    _rect->x = position.x;
    _rect->y = position.y;
}

void Rectangle::setSize(Vector2 size)
{
    _rect->w = size.x;
    _rect->h = size.y;
}

void Rectangle::setColor(Color color)
{
    _color = color;
}