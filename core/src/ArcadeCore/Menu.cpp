/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** Menu
*/

#include "core/include/ArcadeCore/Menu.hpp"

Menu::Menu()
{
}

Menu::~Menu()
{
}

void Menu::update(IBuilder *b)
{
    b->rectDraw({0, 0, b->windowWidth(), b->windowHeight()}, b->hexToColor(0x212121FF));
    b->textDraw({"Unify", {b->windowWidth()/32, b->windowHeight()/18}, b->windowHeight()/12, 2}, b->hexToColor(0xFFFFFFFF));
    b->rectDraw({0, b->windowHeight()/5, b->windowWidth(), (b->windowWidth() * 0.3)}, b->hexToColor(0x1A1A1AFF));
    for (int i = 0; i < 5; i++) {
        b->radiusRectDraw({0, 0, 50, 50}, 20, b->hexToColor(0x212100FF));
    }
    
}