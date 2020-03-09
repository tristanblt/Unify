/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** Layout
*/

#include "core/include/ArcadeCore/Layout.hpp"

Layout::Layout(DisplayLibrary *l):
_backgroundBody({0, ((float)(l->_window->height() - l->toUnit(70))), (float)(l->_window->width()), (float)(l->toUnit(70))})
{
}

Layout::~Layout()
{
}

void Layout::update(IBuilder *b)
{
    b->rectDraw(_backgroundBody, b->hexToColor(0x555555FF));
}