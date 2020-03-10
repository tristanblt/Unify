/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Sprite
*/

#include "lib/sfml/include/Graphical/Sprite.hpp"

Sprite::Sprite(std::vector<void *> *assets)
{
    _assets = assets;
    _sprite = new sf::Sprite();
    _sprite->setPosition(0, 0);
}

Sprite::~Sprite()
{
    delete _sprite;
}

void Sprite::draw(IWindow *w)
{
    dynamic_cast<Window *>(w)->getWindow()->draw(*_sprite);
}

void Sprite::setPosition(Vector2 position)
{
    _sprite->setPosition(position.x, position.y);
}

void Sprite::setSize(Vector2 position)
{
    //_sprite->setScale(sf::Vector2f());
}

void Sprite::setSprite(int idx)
{
    _sprite->setTexture(*static_cast<sf::Texture *>((*_assets)[idx]));
}

