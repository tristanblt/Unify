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
    static float offset = 0;
    float a = 100;

    b->rectDraw({0, 0, b->windowWidth(), b->windowHeight()}, b->hexToColor(0x212121FF));
    b->textDraw({"Unify", {b->windowWidth()/32, b->windowHeight() / 18.0f}, static_cast<int>(b->windowHeight() / 12.0f), 2}, b->hexToColor(0xFFFFFFFF));
    b->rectDraw({0, b->windowHeight()/5, b->windowWidth(), (b->windowWidth() * 0.3f)}, b->hexToColor(0x1A1A1AFF));
    for (int i = 0; i < 20; i++) {
        float tmp = (((float)i * (500 + a) + offset + 250) / b->windowWidth());
        if (tmp > 1.2 || tmp < -0.2)
            continue;
        tmp -= 0.5;
        tmp = tmp < 0 ? -tmp : tmp;
        tmp = (((tmp * 40) / 100) + 0.6) * (b->windowHeight() / 2);
        b->radiusRectDraw({((float) i) * (500 + a) + offset + tmp / 2 - 250, (b->windowHeight()/5) + tmp / 2 - 250, (b->windowHeight() / 2 + 200) - tmp, (b->windowHeight() / 2 + 200) - tmp}, 40, b->hexToColor(0x111111FF));
    }
    offset -= 10;
}