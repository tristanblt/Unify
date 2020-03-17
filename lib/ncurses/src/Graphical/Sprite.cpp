/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Sprite
*/

#include "lib/ncurses/include/Graphical/Sprite.hpp"

Sprite::Sprite(std::map<std::string, void *> *assets)
{
    _assets = assets;
}

Sprite::~Sprite()
{

}

void Sprite::draw(IWindow *w)
{
    _frame.w = (_frame.w == -1 ? _sprite->getWidth() : _frame.w);
    _frame.h = (_frame.h == -1 ? _sprite->getHeight() : _frame.h);

    Bitcrush(_sprite, {_x, _y}, _frame, _wantedSize);
}

void Sprite::setPosition(Vector2 position)
{
    _x = position.x;
    _y = position.y;
}

void Sprite::setSize(Vector2 size)
{
    _frame.x = 0;
    _frame.y = 0;
    _frame.h = -1;
    _frame.w = -1;
    _wantedSize.x = size.x;
    _wantedSize.y = size.y;
}

void Sprite::setSize(Box body, Box frame)
{
    _frame.x = frame.x;
    _frame.y = frame.y;
    _frame.h = frame.h;
    _frame.w = frame.w;
    _wantedSize.x = body.w;
    _wantedSize.y = body.h;
}

void Sprite::setSprite(const std::string &idx)
{
    if (_assets->find(idx) == _assets->end())
        throw std::invalid_argument("Could not find sprite asset");
    _sprite = static_cast<PngFile *>((*_assets)[idx]);
}

void Sprite::setOpacity(unsigned char opacity)
{

}

