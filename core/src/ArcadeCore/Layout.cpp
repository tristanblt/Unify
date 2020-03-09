/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** Layout
*/

#include "core/include/ArcadeCore/Layout.hpp"

Layout::Layout(DisplayLibrary *l):
_backgroundBody({0, (l->_window->height() - l->toUnit(70)), l->_window->width(), l->toUnit(70)})
{
}

Layout::~Layout()
{
}

void Layout::update(IBuilder *b)
{
    b->rectDraw(_backgroundBody, b->hexToColor(0x555555FF));
}