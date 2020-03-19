/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** Menu
*/

#include "core/include/ArcadeCore/Components/Menu.hpp"

Menu::Menu()
{
    _currentGame = NULL;
    _state = MenuState::MENU_CAROUSSEL;
    _interruptType = false;
    _coversOffset = 0;
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
    b->spriteDraw({{VW(4), VH(4), VH(11.5), VH(11.5)}, "UnifyLogo", 255});
    b->textDraw({"Unify", {VW(12.5), VH(6.5)}, b->hexToColor(0xFFFFFFFF), (int)VH(5), "UnifyBoldFont"});
    if (_state == MenuState::MENU_CAROUSSEL) {
        if (b->buttonDraw("UnifySettings") && b->getEvents().mouseEvents.mouseStates[MouseButton::LEFT_CLICK] == InputState::RELEASED)
            _state = MenuState::MENU_SETTINGS;
    } else {
        if (b->buttonDraw("UnifyBack") && b->getEvents().mouseEvents.mouseStates[MouseButton::LEFT_CLICK] == InputState::RELEASED)
            _state = MenuState::MENU_CAROUSSEL;
    }
    if (b->buttonDraw("UnifyRestart") && b->getEvents().mouseEvents.mouseStates[MouseButton::LEFT_CLICK] == InputState::RELEASED) {
        _interruptType = true;
        b->windowClose();
    }
    if (b->buttonDraw("UnifyPower") && b->getEvents().mouseEvents.mouseStates[MouseButton::LEFT_CLICK] == InputState::RELEASED) {
        _interruptType = false;
        b->windowClose();
    }
}

void Menu::drawCarousel(IBuilder *b)
{
    if (b->isInBox({0, VH(20), VW(100), VH(55)})) {
        _coversOffset -= b->getEvents().mouseEvents.scrollVelocity * 10;
        _coversOffset += b->getEvents().joyConEvents.buttons[JOY_R1] == InputState::HOLD ? -50 : 0;
        _coversOffset += b->getEvents().joyConEvents.buttons[JOY_L1] == InputState::HOLD ? 50 : 0;
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
            b->spriteDraw({{(VH(35)) * i + _coversOffset + VH(17), VH(24), VH(33), VH(33)}, _covers[i].spriteIdx, static_cast<unsigned char>(color)});
        }
        else {
            color = (color = (255 - (color * 2 * 255))) >= 26 ? color : 26;
            b->radiusRectDraw({(VH(35)) * i + _coversOffset + VH(17), VH(24), VH(33), VH(33)}, VH(5), {static_cast<unsigned char>(color), static_cast<unsigned char>(color), static_cast<unsigned char>(color), 255});
        }
        if (color > 200 && i < _covers.size()) {
            b->textDraw({_covers[i].gameName, {(VW(100) - (0.5f * _covers[i].gameName.length() * (VH(3)))) * 0.49f, VH(20) * 3.12f}, b->hexToColor(0xFFFFFFFF), static_cast<int>(VH(3)), "UnifyBoldFont"});
            if (b->isInBox({(VH(35)) * i + _coversOffset + VH(17), VH(24), VH(33), VH(33), }) &&
            (b->getEvents().mouseEvents.mouseStates[MouseButton::LEFT_CLICK] == InputState::RELEASED ||
            b->getEvents().joyConEvents.buttons[JoyConButtons::JOY_A] == InputState::RELEASED))
                _currentGame = _covers[i].gameLib;
        }
    }
}

void Menu::drawSettings(IBuilder *b)
{
    (void)b;
}

void Menu::start(IBuilder *b)
{
    std::ifstream f("assets/files/games.config");
    std::string buffer;
    std::vector<std::string> file;

    _covers.clear();
    if (!f)
        throw std::invalid_argument("Could not open file games.config");
    while (std::getline(f, buffer))
        if(buffer.size() > 0)
            file.push_back(buffer);
    f.close();
    for (size_t i = 0; i < file.size() / 3 * 3; i += 3) {
        b->loadAsset(file[i + 1], "UnifyCover" + std::to_string(i), AssetType::SPRITE);
        DLLoader<Start> *loader = new DLLoader<Start>(file[i + 2].c_str());
        _covers.push_back({file[i], loader, "UnifyCover" + std::to_string(i)});
    }
    if (_coversOffset == 0)
        _coversOffset = VW(50) - VW(20);
    b->addButton(new SpriteButton({b->windowWidth() * (18.2f / 20.0f), b->windowHeight() / 13.7f, b->windowWidth() / 38.0f, b->windowWidth() / 38.0f},
    {256, 0, 128, 128}, {0, 0, 128, 128}, {128, 0, 128, 128}, "UnifyIcons"), "UnifySettings");
    b->addButton(new SpriteButton({b->windowWidth() * (18.2f / 20.0f), b->windowHeight() / 15.0f * 12.6f, b->windowWidth() / 30.0f, b->windowWidth() / 30.0f},
    {256, 128, 128, 128}, {0, 128, 128, 128}, {128, 128, 128, 128}, "UnifyIcons"), "UnifyPower");
    b->addButton(new SpriteButton({b->windowWidth() * (17.2f / 20.0f), b->windowHeight() / 15.0f * 12.6f, b->windowWidth() / 30.0f, b->windowWidth() / 30.0f},
    {256, 256, 128, 128}, {0, 256, 128, 128}, {128, 256, 128, 128}, "UnifyIcons"), "UnifyRestart");
    b->addButton(new SpriteButton({b->windowWidth() * (18.2f / 20.0f), b->windowHeight() / 13.7f, b->windowWidth() / 38.0f, b->windowWidth() / 38.0f},
    {256, 512, 128, 128}, {0, 512, 128, 128}, {128, 512, 128, 128}, "UnifyIcons"), "UnifyBack");
}

DLLoader<Start> *Menu::update(IBuilder *b)
{
    DLLoader<Start> *tmp = _currentGame;

    _currentGame = NULL;
    drawBackgrounds(b);
    drawHeader(b);
    if (!b->windowIsOpen())
        return (tmp);
    if (_state == MenuState::MENU_CAROUSSEL)
        drawCarousel(b);
    else
        drawSettings(b);
    return (tmp);
}

bool Menu::getInterruptType() const
{
    return (_interruptType);
}