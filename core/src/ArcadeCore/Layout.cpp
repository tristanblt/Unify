/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** Layout
*/

#include "core/include/ArcadeCore/Layout.hpp"

Layout::Layout(DisplayLibrary *l):
_backgroundBody({0, (l->_window->height() - 70), l->_window->width(), 70})
{
}

Layout::~Layout()
{
}

void Layout::update(IBuilder *b)
{
    b->rectDraw(_backgroundBody, {55, 55, 55, 255});
}