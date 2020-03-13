/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** Menu
*/

#include "core/include/ArcadeCore/Menu.hpp"

Menu::Menu()
{
    _currentGame = NULL;
}

Menu::~Menu()
{
}

void Menu::drawBackgrounds(IBuilder *b)
{
    b->rectDraw({0, 0, VW(100), VH(100)}, b->hexToColor(0x212121FF));
    b->rectDraw({0, VH(20), VW(100), VH(55)}, b->hexToColor(0x1A1A1AFF));
}

void Menu::drawHeader(IBuilder *b)
{
    b->textDraw({"Unify", {VW(5), VH(5)}, b->hexToColor(0xFFFFFFFF), (int)VH(8), 2});
    if (b->spriteButtonDraw({{
            b->windowWidth() * (18.2f / 20.0f), b->windowHeight() / 13.7f,
            b->windowWidth() / 38.0f, b->windowWidth() / 38.0f
        },
        {{b->windowWidth() * (18.2f / 20.0f), b->windowHeight() / 13.7f, b->windowWidth() / 38.0f, b->windowWidth() / 38.0f}, 3, 255},
        {{b->windowWidth() * (18.2f / 20.0f), b->windowHeight() / 13.7f, b->windowWidth() / 38.0f, b->windowWidth() / 38.0f}, 3, 255},
        {{b->windowWidth() * (18.2f / 20.0f), b->windowHeight() / 13.7f, b->windowWidth() / 38.0f, b->windowWidth() / 38.0f}, 3, 255},
        {"", {0, 0}, b->hexToColor(0xFFFFFFFF), 0, 0},
        {"", {0, 0}, b->hexToColor(0xFFFFFFFF), 0, 0},
        {"", {0, 0}, b->hexToColor(0xFFFFFFFF), 0, 0},
        false}
        ) && b->getEvents().mouseEvents.mouseStates[MouseButton::LEFT_CLICK] == InputState::RELEASED)
            std::cout << "OPTIONS" << std::endl;
    if (b->spriteButtonDraw(
{        {
            b->windowWidth() * (17.2f / 20.0f), b->windowHeight() / 15.0f * 12.6f,
            b->windowWidth() / 30.0f, b->windowWidth() / 30.0f
        },
        {{b->windowWidth() * (17.2f / 20.0f), b->windowHeight() / 15.0f * 12.6f, b->windowWidth() / 30.0f, b->windowWidth() / 30.0f}, 5, 255},
        {{b->windowWidth() * (17.2f / 20.0f), b->windowHeight() / 15.0f * 12.6f, b->windowWidth() / 30.0f, b->windowWidth() / 30.0f}, 4, 255},
        {{b->windowWidth() * (17.2f / 20.0f), b->windowHeight() / 15.0f * 12.6f, b->windowWidth() / 30.0f, b->windowWidth() / 30.0f}, 6, 255},
        {"", {0, 0}, b->hexToColor(0xFFFFFFFF), 0, 0},
        {"", {0, 0}, b->hexToColor(0xFFFFFFFF), 0, 0},
        {"", {0, 0}, b->hexToColor(0xFFFFFFFF), 0, 0},
        false}
        ) && b->getEvents().mouseEvents.mouseStates[MouseButton::LEFT_CLICK] == InputState::RELEASED)
            std::cout << "REDEMARER" << std::endl;
    if (b->spriteButtonDraw(
{        {
            b->windowWidth() * (18.2f / 20.0f), b->windowHeight() / 15.0f * 12.6f,
            b->windowWidth() / 30.0f, b->windowWidth() / 30.0f
        },
        {{b->windowWidth() * (18.2f / 20.0f), b->windowHeight() / 15.0f * 12.6f, b->windowWidth() / 30.0f, b->windowWidth() / 30.0f}, 9, 255},
        {{b->windowWidth() * (18.2f / 20.0f), b->windowHeight() / 15.0f * 12.6f, b->windowWidth() / 30.0f, b->windowWidth() / 30.0f}, 7, 255},
        {{b->windowWidth() * (18.2f / 20.0f), b->windowHeight() / 15.0f * 12.6f, b->windowWidth() / 30.0f, b->windowWidth() / 30.0f}, 8, 255},
        {"", {0, 0}, b->hexToColor(0xFFFFFFFF), 0, 0},
        {"", {0, 0}, b->hexToColor(0xFFFFFFFF), 0, 0},
        {"", {0, 0}, b->hexToColor(0xFFFFFFFF), 0, 0},
        false}
        ) && b->getEvents().mouseEvents.mouseStates[MouseButton::LEFT_CLICK] == InputState::RELEASED)
            b->windowClose();
}

void Menu::drawCarousel(IBuilder *b)
{
    if (b->isInBox({0, VH(20), VW(100), VH(55)})) {
        _coversOffset -= b->getEvents().mouseEvents.scrollVelocity * 10;
        if (_coversOffset > VW(50) - VW(20))
            _coversOffset = VW(50) - VW(20);
    }
    for (size_t i = 0; i < 10; i++) {
        float color = (((VH(33) + 30) * i + _coversOffset + (VH(33) + 30)) / VW(100));
        if (color < 0 || color > 1)
            continue;
        color -= 0.5f;
        color = color < 0 ? color * -1 : color;
        if (i < _covers.size()) {
            color = (255 - (color * 2 * 255));
            b->spriteDraw({{(VH(33) + 30) * i + _coversOffset + VH(17), VH(20) + 70, VH(33), VH(33)}, _covers[i].spriteIdx, static_cast<unsigned char>(color)});
        }
        else {
            color = (color = (255 - (color * 2 * 255))) >= 26 ? color : 26;
            b->radiusRectDraw({(VH(33) + 30) * i + _coversOffset + VH(17), VH(20) + 70, VH(33), VH(33)}, 50, {static_cast<unsigned char>(color), static_cast<unsigned char>(color), static_cast<unsigned char>(color), 255});
        }
        if (color > 200 && i < _covers.size()) {
            b->textDraw({_covers[i].gameName, {(VW(100) - (0.5f * _covers[i].gameName.length() * (VH(3)))) * 0.49f, VH(20) * 3.12f}, b->hexToColor(0xFFFFFFFF), static_cast<int>(VH(3)), 2});
            if (b->isInBox({(VH(33) + 30) * i + _coversOffset + VH(17), VH(20) + 70, VH(33), VH(33), }) &&
            b->getEvents().mouseEvents.mouseStates[MouseButton::LEFT_CLICK] == InputState::RELEASED)
                _currentGame = _covers[i].gameLib;
        }
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
        DLLoader<Start> *loader = new DLLoader<Start>(file[i + 2].c_str());
        _covers.push_back({file[i], loader, b->getLastAssetIdx()});
    }
    _coversOffset = VW(50) - VW(20);
}

DLLoader<Start> *Menu::update(IBuilder *b)
{
    DLLoader<Start> *tmp = _currentGame;

    _currentGame = NULL;
    drawBackgrounds(b);
    drawHeader(b);
    if (!b->windowIsOpen())
        return (tmp);
    drawCarousel(b);
    return (tmp);
}