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
    b->rectDraw({0, ((b->windowHeight() - b->toUnit(b->windowHeight() / 14.0f))), b->windowWidth(), b->toUnit(b->windowHeight() / 14.0f)}, b->hexToColor(0x373737FF));
    b->textDraw({"Unify", {b->windowWidth()/60, ((b->windowHeight() - b->toUnit(b->windowHeight() / 16.0f)))}, static_cast<int>(b->windowHeight() / 25.0f), 2}, b->hexToColor(0xFFFFFFFF));
    b->textDraw({/**/"Pac-Man"/**/, {(b->windowWidth() - (0.5f * /**/8/**/ * (b->windowHeight() / 25.0f))) * 0.5f, ((b->windowHeight() - b->toUnit(b->windowHeight() / 16.0f)))}, static_cast<int>(b->windowHeight() / 25.0f), 2}, b->hexToColor(0xFFFFFF99));
    b->radiusRectDraw({b->windowWidth() * (19.0f / 20.0f), ((b->windowHeight() - b->toUnit(b->windowHeight() / 16.0f))), (b->windowHeight() / 18.0f), (b->windowHeight() / 18.0f)}, ((b->windowHeight() / 18.0f) / 2.0f), b->hexToColor(0xFFFFFFFF));
}
