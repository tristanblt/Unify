/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Sprite
*/

#include "lib/Vulkan/include/Graphical/Sprite.hpp"

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

#include <iostream>
void Sprite::setSize(Vector2 size)
{
    if (_sprite->getTexture()) {
        _sprite->setTextureRect(sf::IntRect(0, 0, _sprite->getTexture()->getSize().x, _sprite->getTexture()->getSize().y));
        _sprite->setScale(sf::Vector2f(size.x / _sprite->getTexture()->getSize().x,
                                       size.y / _sprite->getTexture()->getSize().y));
    }
}

void Sprite::setSprite(int idx)
{
    _sprite->setTexture(*static_cast<sf::Texture *>((*_assets)[idx]));
}

void Sprite::setOpacity(unsigned char opacity)
{
    _sprite->setColor(sf::Color(255, 255, 255, opacity));
}

