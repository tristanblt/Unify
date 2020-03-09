/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** Layout
*/

#include "core/include/ArcadeCore/Layout.hpp"

Layout::Layout():
_backgroundBody({850, 0, 50, 1600})
{
}

Layout::~Layout()
{
}

void Layout::update(IBuilder *b)
{
    b->rectDraw(_backgroundBody, {255, 255, 255, 255});
}