/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** Layout
*/

#include "core/include/ArcadeCore/Layout.hpp"

Layout::Layout()
{
}

Layout::~Layout()
{
}

void Layout::update(IBuilder *b)
{
    b->rectDraw({0, ((float)(b->windowHeight() - b->toUnit(70))), (float)(b->windowWidth()), (float)(b->toUnit(70))}, b->hexToColor(0x555555FF));
}