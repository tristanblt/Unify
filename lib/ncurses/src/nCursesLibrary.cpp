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