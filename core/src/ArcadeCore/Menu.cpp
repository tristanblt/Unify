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
#include <iostream>
void Menu::update(IBuilder *b)
{
    static float offset = 0;
    float a = 30;
    b->rectDraw({0, 0, 1600, 900}, b->hexToColor(0x212121FF));
    b->textDraw({"Unify", {50, 40}, 75, 2}, b->hexToColor(0xFFFFFFFF));
    b->rectDraw({0, 180, 1600, 600}, b->hexToColor(0x1A1A1AFF));
    for (int i = 0; i < 10; i++) {
        float tmp = ((((float)i * 470 + a + offset)) / 1600);
        if (tmp > 1.2 || tmp < -0.2)
            continue;
        tmp -= 0.5;
        if (tmp < 0)
            tmp = -tmp;
        tmp = (((tmp * 50) / 100) + 0.5) * 500;
        b->radiusRectDraw({((float) i) * 470 + a + offset + tmp / 2 - 250, 250 + tmp / 2, 700 - tmp, 700 - tmp}, 40, b->hexToColor(0xFFFFFFFF));
    }
    offset -= 3;
}