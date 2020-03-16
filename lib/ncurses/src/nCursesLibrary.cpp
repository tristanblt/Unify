/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SFMLLibrary
*/

#include "../include/nCursesLibrary.hpp"

nCursesLibrary::nCursesLibrary()
{
    _rect = new Rectangle();
    _window = new Window();
    _circle = new Circle();
    _text = new Text(&_assets);
    _sprite = new Sprite(&_assets);
}

nCursesLibrary::~nCursesLibrary()
{
}

float nCursesLibrary::toUnit(float nb)
{
    return (nb);
}

void nCursesLibrary::loadAsset(const std::string &path, const std::string &name, AssetType type)
{
    if (type == AssetType::SPRITE) {
        PngFile *f = new PngFile(path);
        _assets[name] = (void *)f;
    }
}

Events nCursesLibrary::updateEvents(Events *events)
{
    return (Events());
}

int nCursesLibrary::getLastAssetIdx() const
{
    return (_assets.size() - 1);
    return (0);
}
void nCursesLibrary::updateMouseEvents(Events *events, Window *window)
{

}

void nCursesLibrary::updateKeyboardEvents(Events *events)
{
}