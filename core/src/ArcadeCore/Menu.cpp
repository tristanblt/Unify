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

void Menu::drawBackgrounds(IBuilder *b)
{
    b->rectDraw(
        {
            0,
            0,
            b->windowWidth(),
            b->windowHeight()
        },
        b->hexToColor(0x212121FF)
    );
    b->rectDraw(
        {
            0,
            b->windowHeight()/5,
            b->windowWidth(),
            (b->windowWidth() * 0.3f)
        },
        b->hexToColor(0x1A1A1AFF)
    );
}

void Menu::drawHeader(IBuilder *b)
{
    b->textDraw(
        {
            "Unify",
            {
                b->windowWidth()/32,
                b->windowHeight() / 25.0f
            },
            static_cast<int>(b->windowHeight() / 12.0f),
            2
        },
        b->hexToColor(0xFFFFFFFF)
    );
    b->spriteDraw(
        {
            {
                b->windowWidth() * (18.5f / 20.0f),
                b->windowHeight() / 15.0f,
                 b->windowWidth() / 38.0f,
                 b->windowWidth() / 38.0f
            },
            3
        }
    );
}

void Menu::drawCarousel(IBuilder *b, int offset)
{
    for (size_t i = 0; i < 10; i++) {
        float color = (((b->windowHeight() / 3 + 30) * i + offset + (b->windowHeight() / 3 + 30)) / b->windowWidth());
        if (color < 0 || color > 1)
            continue;
        color -= 0.5f;
        color = color < 0 ? color * -1 : color;
        color = (color = (255 - (color * 2 * 255))) >= 26 ? color : 26;
        b->radiusRectDraw(
            {
                (b->windowHeight() / 3 + 30) * i + offset + b->windowHeight() / 6,
                b->windowHeight() / 5 + 70,
                b->windowHeight() / 3,
                b->windowHeight() / 3
            },
            50,
            {
                static_cast<unsigned char>(color),
                static_cast<unsigned char>(color),
                static_cast<unsigned char>(color),
                255
            }
        );
        if (i < _covers.size())
            b->spriteDraw(
                {
                    {
                        (b->windowHeight() / 3 + 30) * i + offset + b->windowHeight() / 6,
                        b->windowHeight() / 5 + 70,
                        b->windowHeight() / 3,
                        b->windowHeight() / 3,
                    },
                    _covers[i].spriteIdx
                }
            );
        if (color > 200 && i < _covers.size())
            b->textDraw(
                {
                    _covers[i].gameName,
                    {
                        b->windowWidth() / 2 - 10,
                        b->windowWidth() * 0.3f + b->windowHeight()/5 - 180
                    },
                    static_cast<int>(b->windowHeight() / 24.0f),
                    2
                },
                b->hexToColor(0xFFFFFFFF)
            );
    }
}

void Menu::start(IBuilder *b)
{
    std::ifstream f("assets/files/games.config");
    std::string buffer;
    std::vector<std::string> file;

    if (!f)
        throw std::invalid_argument("Could not open file games.config");
    while (std::getline(f, buffer))
        if(buffer.size() > 0)
            file.push_back(buffer);
    f.close();
    for (size_t i = 0; i < file.size() / 3 * 3; i += 3) {
        b->loadAsset(file[i + 1], AssetType::SPRITE);
        _covers.push_back({file[i], file[i + 2], b->getLastAssetIdx()});
    }
}

void Menu::update(IBuilder *b)
{
    static float offset = 1000; // temp

    drawBackgrounds(b);
    drawHeader(b);
    drawCarousel(b, offset);
    offset -= 4; // temp
}