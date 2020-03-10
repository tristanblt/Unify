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
    float a = 100;

    b->rectDraw({0, 0, b->windowWidth(), b->windowHeight()}, b->hexToColor(0x212121FF));
    b->textDraw({"Unify", {b->windowWidth()/32, b->windowHeight() / 18.0f}, static_cast<int>(b->windowHeight() / 12.0f), 2}, b->hexToColor(0xFFFFFFFF));
    b->rectDraw({0, b->windowHeight()/5, b->windowWidth(), (b->windowWidth() * 0.3f)}, b->hexToColor(0x1A1A1AFF));
    for (int i = 0; i < 20; i++) {
        float color = (((b->windowHeight() / 3 + 30) * i + offset + (b->windowHeight() / 3 + 30)) / b->windowWidth());
        if (color < 0 || color > 1)
            continue;
        color -= 0.5f;
        if (color < 0)
            color *= -1;
        if (i == 5)
        std::cout << color << std::endl;
        color = 255 - (color * 2 * 255);
        if (color < 26)
            color = 26;
        b->radiusRectDraw({
                (b->windowHeight() / 3 + 30) * i + offset + b->windowHeight() / 6,
                b->windowHeight() / 5 + 70,
                b->windowHeight() / 3,
                b->windowHeight() / 3
            },
            50,
            {static_cast<unsigned char>(color), static_cast<unsigned char>(color), static_cast<unsigned char>(color), 255}
        );
    }
    offset -= 10;
}