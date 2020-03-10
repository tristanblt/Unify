/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SFMLLibrary
*/

#include "../include/SFMLLibrary.hpp"

SFMLLibrary::SFMLLibrary()
{
    _rect = new Rectangle();
    _window = new Window();
    _circle = new Circle();
    _text = new Text(&_assets);
    _sprite = new Sprite(&_assets);
}

SFMLLibrary::~SFMLLibrary()
{
}

float SFMLLibrary::toUnit(float value)
{
    return (value);
}

void SFMLLibrary::loadAsset(const std::string &name, AssetType type)
{
    if (type == AssetType::FONT) {
        sf::Font *f = new sf::Font();
        if (!f->loadFromFile(name))
            throw std::invalid_argument("FONT NOT FOUND"); // TODO
        _assets.push_back((void *)f);
    }
    else if (type == AssetType::SPRITE) {
        sf::Texture *f = new sf::Texture();
        if (!f->loadFromFile(name))
            throw std::invalid_argument("SPRITE NOT FOUND"); // TODO
        _assets.push_back((void *)f);
    } 
}

int SFMLLibrary::getLastAssetIdx() const
{
    return (_assets.size() - 1);
}
