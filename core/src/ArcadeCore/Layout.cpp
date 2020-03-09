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
    b->rectDraw({0, ((b->windowHeight() - b->toUnit(b->windowHeight() / 12.8f))), b->windowWidth(), b->toUnit(b->windowHeight() / 12.8f)}, b->hexToColor(0x373737FF));
    b->textDraw({"Unify", {b->windowWidth()/60, ((b->windowHeight() - b->toUnit(b->windowHeight() / 12.8f)))}, static_cast<int>(b->windowHeight() / 18.0f), 2}, b->hexToColor(0xFFFFFFFF));
}
