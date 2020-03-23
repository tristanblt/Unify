/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** Menu
*/

#include "core/include/ArcadeCore/Components/Menu.hpp"
#include "core/include/ArcadeCore/CoreException.hpp"

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
    b->rectSetPosition("UnifyMenuBackground", {0, 0});
    b->rectSetSize("UnifyMenuBackground", {VW(100), VH(100)});
    b->rectDraw("UnifyMenuBackground");
    
    b->rectSetPosition("UnifyMenuCarouselBackground", {0, VH(20)});
    b->rectSetSize("UnifyMenuCarouselBackground", {VW(100), VH(55)});
    b->rectDraw("UnifyMenuCarouselBackground");
}

void Menu::drawHeader(IBuilder *b)
{
    b->spriteSetPosition("UnifyMenuLogo", {VW(4), VH(4)});
    b->spriteSetSize("UnifyMenuLogo", {VH(11.5), VH(11.5)});
    b->spriteDraw("UnifyMenuLogo");

    b->textSetPosition("UnifyMenuLogoName", {VW(12.5), VH(6.5)});
    b->textSetFontSize("UnifyMenuLogoName", (int)VH(5));
    b->textDraw("UnifyMenuLogoName");

    b->spriteButtonSetDisplayBox("UnifySettingsButton", {b->windowWidth() * (18.2f / 20.0f), b->windowHeight() / 13.7f, b->windowWidth() / 38.0f, b->windowWidth() / 38.0f});
    b->spriteButtonSetSpriteBoxes("UnifySettingsButton", {256, 0, 128, 128}, {0, 0, 128, 128}, {128, 0, 128, 128});

    b->spriteButtonSetDisplayBox("UnifyBackButton", {b->windowWidth() * (18.2f / 20.0f), b->windowHeight() / 13.7f, b->windowWidth() / 38.0f, b->windowWidth() / 38.0f});
    b->spriteButtonSetSpriteBoxes("UnifyBackButton", {256, 512, 128, 128}, {0, 512, 128, 128}, {128, 512, 128, 128});

    b->spriteButtonSetDisplayBox("UnifyRestartButton", {b->windowWidth() * (17.2f / 20.0f), b->windowHeight() / 15.0f * 12.6f, b->windowWidth() / 30.0f, b->windowWidth() / 30.0f});
    b->spriteButtonSetSpriteBoxes("UnifyRestartButton", {256, 256, 128, 128}, {0, 256, 128, 128}, {128, 256, 128, 128});

    b->spriteButtonSetDisplayBox("UnifyPowerButton", {b->windowWidth() * (18.2f / 20.0f), b->windowHeight() / 15.0f * 12.6f, b->windowWidth() / 30.0f, b->windowWidth() / 30.0f});
    b->spriteButtonSetSpriteBoxes("UnifyPowerButton", {256, 128, 128, 128}, {0, 128, 128, 128}, {128, 128, 128, 128});

    if (_state == MenuState::MENU_CAROUSSEL) {
        if (b->buttonDraw("UnifySettingsButton") && b->getEvents().mouseEvents.mouseStates[MouseButton::LEFT_CLICK] == InputState::RELEASED)
            _state = MenuState::MENU_SETTINGS;
    } else {
        if (b->buttonDraw("UnifyBackButton") && b->getEvents().mouseEvents.mouseStates[MouseButton::LEFT_CLICK] == InputState::RELEASED)
            _state = MenuState::MENU_CAROUSSEL;
    }
    if (b->buttonDraw("UnifyRestartButton") && b->getEvents().mouseEvents.mouseStates[MouseButton::LEFT_CLICK] == InputState::RELEASED) {
        _interruptType = true;
        b->windowClose();
    }
    if (b->buttonDraw("UnifyPowerButton") && b->getEvents().mouseEvents.mouseStates[MouseButton::LEFT_CLICK] == InputState::RELEASED) {
        _interruptType = false;
        b->windowClose();
    }
}

void Menu::drawCarousel(IBuilder *b)
{
    if (b->isMouseInBox({0, VH(20), VW(100), VH(55)})) {
        _coversOffset -= b->getEvents().mouseEvents.scrollVelocity * 10;
        _coversOffset += b->getEvents().joyConEvents.buttons1[JOY_R1] == InputState::HOLD ? -50 : 0;
        _coversOffset += b->getEvents().joyConEvents.buttons1[JOY_L1] == InputState::HOLD ? 50 : 0;
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
            b->spriteSetPosition("UnifyMenuCarouselCoverPicture", {(VH(35)) * i + _coversOffset + VH(17), VH(24)});
            b->spriteSetSize("UnifyMenuCarouselCoverPicture", {VH(33), VH(33)});
            b->spriteSetSprite("UnifyMenuCarouselCoverPicture", _covers[i].spriteIdx);
            b->spriteSetOpacity("UnifyMenuCarouselCoverPicture", static_cast<unsigned char>(color));
            b->spriteDraw("UnifyMenuCarouselCoverPicture");
        }
        else {
            color = (color = (255 - (color * 2 * 255))) >= 26 ? color : 26;
            b->radiusRectSetPosition("UnifyMenuCarouselCoverEmpty", {(VH(35)) * i + _coversOffset + VH(17), VH(24)});
            b->radiusRectSetSize("UnifyMenuCarouselCoverEmpty", {VH(33), VH(33)});
            b->radiusRectSetRadius("UnifyMenuCarouselCoverEmpty", VH(4));
            b->radiusRectSetColor("UnifyMenuCarouselCoverEmpty",
                {
                    static_cast<unsigned char>(color),
                    static_cast<unsigned char>(color),
                    static_cast<unsigned char>(color),
                    255
                }
            );
            b->radiusRectDraw("UnifyMenuCarouselCoverEmpty");
        }
        if (color > 200 && i < _covers.size()) {
            b->textSetText("UnifyMenuCarouselCoverTitle", _covers[i].gameName);
            b->textSetPosition("UnifyMenuCarouselCoverTitle", {(VW(100) - (0.5f * _covers[i].gameName.length() * (VH(3)))) * 0.49f, VH(20) * 3.12f});
            b->textSetFontSize("UnifyMenuCarouselCoverTitle", static_cast<int>(VH(3)));
            b->textDraw("UnifyMenuCarouselCoverTitle");
            if (b->isMouseInBox({(VH(35)) * i + _coversOffset + VH(17), VH(24), VH(33), VH(33), }) &&
            (b->getEvents().mouseEvents.mouseStates[MouseButton::LEFT_CLICK] == InputState::RELEASED ||
            b->getEvents().joyConEvents.buttons1[JoyConButtons::JOY_A] == InputState::RELEASED))
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
        throw FileException("Could not open file 'games.config'");
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

    b->spriteButtonInit("UnifySettingsButton");
    b->spriteButtonSetSprite("UnifySettingsButton", "UnifyIcons");

    b->spriteButtonInit("UnifyBackButton");
    b->spriteButtonSetSprite("UnifyBackButton", "UnifyIcons");

    b->spriteButtonInit("UnifyRestartButton");
    b->spriteButtonSetSprite("UnifyRestartButton", "UnifyIcons");

    b->spriteButtonInit("UnifyPowerButton");
    b->spriteButtonSetSprite("UnifyPowerButton", "UnifyIcons");

    b->rectInit("UnifyMenuBackground");
    b->rectSetColor("UnifyMenuBackground", b->hexToColor(0x212121FF));

    b->rectInit("UnifyMenuCarouselBackground");
    b->rectSetColor("UnifyMenuCarouselBackground", b->hexToColor(0x1A1A1AFF));

    b->spriteInit("UnifyMenuLogo");
    b->spriteSetSprite("UnifyMenuLogo", "UnifyLogo");
    b->spriteSetOpacity("UnifyMenuLogo", 255);

    b->textInit("UnifyMenuLogoName");
    b->textSetText("UnifyMenuLogoName", "Unify");
    b->textSetColor("UnifyMenuLogoName", b->hexToColor(0xFFFFFFFF));
    b->textSetFont("UnifyMenuLogoName", "UnifyBoldFont");

    b->spriteInit("UnifyMenuCarouselCoverPicture");

    b->radiusRectInit("UnifyMenuCarouselCoverEmpty");

    b->textInit("UnifyMenuCarouselCoverTitle");
    b->textSetColor("UnifyMenuCarouselCoverTitle", b->hexToColor(0xFFFFFFFF));
    b->textSetFont("UnifyMenuCarouselCoverTitle", "UnifyBoldFont");
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