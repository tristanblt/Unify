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
}

nCursesLibrary::~nCursesLibrary()
{
}

float nCursesLibrary::toUnit(float nb)
{
    return (nb);
}

void nCursesLibrary::loadAsset(const std::string &path, AssetType type)
{
    (void)path;
    (void)type;
}

Events nCursesLibrary::updateEvents(Events *events)
{
    return (Events());
}

int nCursesLibrary::getLastAssetIdx() const
{
    //return (_assets.size() - 1);
    return (0);
}
void nCursesLibrary::updateMouseEvents(Events *events, Window *window)
{

}

void nCursesLibrary::updateKeyboardEvents(Events *events)
{
}