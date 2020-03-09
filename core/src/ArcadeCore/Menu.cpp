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
    b->rectDraw({0, 0, 1600, 900}, b->hexToColor(0x212121FF));
    b->textDraw({"Unify", {50, 40}, 75, 2}, b->hexToColor(0xFFFFFFFF));
    b->rectDraw({0, 180, 1600, 600}, b->hexToColor(0x1A1A1AFF));
    for (int i = 0; i < 5; i++) {
        b->radiusRectDraw({0, 0, 50, 50}, 20, b->hexToColor(0x212100FF));
    }
    
}