/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Sprite
*/

#include "lib/sdl2/include/Graphical/Sprite.hpp"
#include "lib/sdl2/include/SDL2Exceptions.hpp"

Sprite::Sprite(std::map<std::string, void *> *assets)
{
    _assets = assets;
}

Sprite::~Sprite()
{
}

void Sprite::draw(IWindow *w)
{
    SDL_Rect f = {(int)_frame.x, (int)_frame.y, (int)_frame.w, (int)_frame.h};
    SDL_Rect r = {(int)_body.x, (int)_body.y, (int)_body.w, (int)_body.h};
    SDL_RenderCopy(dynamic_cast<Window *>(w)->getRenderer(), _sprite, _frame.x == -1 ? NULL : &f, &r);
}

void Sprite::setPosition(Vector2 position)
{
    _body.x = position.x;
    _body.y = position.y;
}

void Sprite::setSize(Vector2 size)
{
    _body.w = size.x;
    _body.h = size.y;
    _frame = {-1, -1, -1, -1};
}

void Sprite::setSize(Box body, Box frame)
{
    _body = body;
    _frame = frame;
}

void Sprite::setSprite(const std::string &idx)
{
    if (_assets->find(idx) == _assets->end())
        throw SDL2AssetException("Could not find '"+idx+"' asset");
    _sprite = static_cast<SDL_Texture *>((*_assets)[idx]);
}

void Sprite::setOpacity(unsigned char opacity)
{
    (void) opacity;
}