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
        if ((b->buttonDraw("UnifySettingsButton") && b->getEvents().mouseEvents.mouseStates[MouseButton::LEFT_CLICK] == InputState::RELEASED) ||
        b->getEvents().keyboardState[Key::F5] == InputState::RELEASED) {
            _state = MenuState::MENU_SETTINGS;
            b->playSound("UnifyBorderSound");
        }
    } else {
        if ((b->buttonDraw("UnifyBackButton") && b->getEvents().mouseEvents.mouseStates[MouseButton::LEFT_CLICK] == InputState::RELEASED) ||
        b->getEvents().keyboardState[Key::F5] == InputState::RELEASED) {
            _state = MenuState::MENU_CAROUSSEL;
            b->playSound("UnifyBorderSound");
        }
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
    bool oneText = false;
    static size_t lastIdx = 0;

    _coversOffset += b->getEvents().keyboardState[Key::LEFT] == InputState::HOLD ? VW(1) : 0;
    _coversOffset += b->getEvents().keyboardState[Key::RIGHT] == InputState::HOLD ? -VW(1) : 0;
    if (b->isMouseInBox({0, VH(20), VW(100), VH(55)})) {
        _coversOffset -= b->getEvents().mouseEvents.scrollVelocity * 10;
        _coversOffset += b->getEvents().joyConEvents.buttons1[JOY_R1] == InputState::HOLD ? -VW(1) : 0;
        _coversOffset += b->getEvents().joyConEvents.buttons1[JOY_L1] == InputState::HOLD ? VW(1) : 0;
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
        if (color > 200 && !oneText) {
            if (i != lastIdx) {
                lastIdx = i;
                b->playSound("UnifyClickSound");
            }
        }
        if (color > 200 && i < _covers.size() && !oneText) {
            b->textSetText("UnifyMenuCarouselCoverTitle", _covers[i].gameName);
            b->textSetPosition("UnifyMenuCarouselCoverTitle", {(VW(100) - (0.5f * _covers[i].gameName.length() * (VH(3)))) * 0.49f, VH(20) * 3.12f});
            b->textSetFontSize("UnifyMenuCarouselCoverTitle", static_cast<int>(VH(3)));
            b->textDraw("UnifyMenuCarouselCoverTitle");
            if ((b->isMouseInBox({(VH(35)) * i + _coversOffset + VH(17), VH(24), VH(33), VH(33), }) &&
            (b->getEvents().mouseEvents.mouseStates[MouseButton::LEFT_CLICK] == InputState::RELEASED ||
            b->getEvents().joyConEvents.buttons1[JoyConButtons::JOY_A] == InputState::RELEASED)) ||
            b->getEvents().keyboardState[Key::SPACE] == InputState::RELEASED) {
                _currentGame = _covers[i].gameLib;
                b->playSound("UnifyRunGameSound");
            }
            oneText = true;
        }
    }
}

void Menu::drawSettings(IBuilder *b, LibraryControl &libCtrl)
{
    int result;
    static int tmpVolume = b->getVolume();

    b->selectorSetDisplayBox("UnifySettingsSelector", {0, VH(20), VW(30), VH(55)});
    result = b->selectorDraw("UnifySettingsSelector");
    if (result == 0) {
        if (b->getEvents().keyboardState[Key::RIGHT] == InputState::RELEASED && tmpVolume < 100)
            tmpVolume += 5;
        if (b->getEvents().keyboardState[Key::LEFT] == InputState::RELEASED && tmpVolume > 0)
            tmpVolume -= 5;
        b->sliderSetWidth("UnifySettingsAudioSlider", VW(30));
        b->sliderSetPosition("UnifySettingsAudioSlider", {VW(35), VH(30)});
        b->sliderDraw("UnifySettingsAudioSlider", tmpVolume);
        b->textSetFontSize("UnifySettingsAudioText", VH(2));
        b->textSetPosition("UnifySettingsAudioText", {VW(35), VH(25)});
        b->textDraw("UnifySettingsAudioText");
    } else if (result == 1) {
        b->basicButtonSetDisplayBox("UnifyMenuPreviousLib", {VW(33), VH(25), VW(15), VH(5)});
        b->basicButtonSetFontSize("UnifyMenuPreviousLib", VH(2));
        b->basicButtonSetRadius("UnifyMenuPreviousLib", VH(2.5));
        b->buttonDraw("UnifyMenuPreviousLib");
        if (b->buttonDraw("UnifyMenuPreviousLib") && b->getEvents().mouseEvents.mouseStates[MouseButton::LEFT_CLICK] == InputState::RELEASED)
            libCtrl = LibraryControl::LIB_CTRL_PREV;
        b->basicButtonSetDisplayBox("UnifyMenuNextLib", {VW(33), VH(33), VW(15), VH(5)});
        b->basicButtonSetFontSize("UnifyMenuNextLib", VH(2));
        b->basicButtonSetRadius("UnifyMenuNextLib", VH(2.5));
        b->buttonDraw("UnifyMenuNextLib");
        if (b->buttonDraw("UnifyMenuNextLib") && b->getEvents().mouseEvents.mouseStates[MouseButton::LEFT_CLICK] == InputState::RELEASED)
            libCtrl = LibraryControl::LIB_CTRL_NEXT;
    } else if (result == 2) {
        b->textSetPosition("UnifySettingsCredits", {VW(35), VH(25)});
        b->textSetFontSize("UnifySettingsCredits", VH(2));
        b->textDraw("UnifySettingsCredits");
    }
    b->setVolume(tmpVolume);
}

void Menu::start(IBuilder *b)
{
    FileManager fm("assets/files/games.config");

    _covers.clear();
    for (size_t i = 0; i < fm._file.size() / 3 * 3; i += 3) {
        b->loadAsset(fm._file[i + 1], "UnifyCover" + std::to_string(i), AssetType::SPRITE);
        DLLoader<Start> *loader = new DLLoader<Start>(fm._file[i + 2].c_str());
        _covers.push_back({fm._file[i], loader, "UnifyCover" + std::to_string(i)});
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

    b->textInit("UnifyMenuLogoName");
    b->textSetText("UnifyMenuLogoName", "Unify");
    b->textSetColor("UnifyMenuLogoName", b->hexToColor(0xFFFFFFFF));
    b->textSetFont("UnifyMenuLogoName", "UnifyBoldFont");

    b->spriteInit("UnifyMenuCarouselCoverPicture");

    b->radiusRectInit("UnifyMenuCarouselCoverEmpty");

    b->textInit("UnifyMenuCarouselCoverTitle");
    b->textSetColor("UnifyMenuCarouselCoverTitle", b->hexToColor(0xFFFFFFFF));
    b->textSetFont("UnifyMenuCarouselCoverTitle", "UnifyBoldFont");

    b->selectorInit("UnifySettingsSelector");
    b->selectorSetItems("UnifySettingsSelector", {"Audio", "Graphics", "Credits"});
    b->selectorSetFont("UnifySettingsSelector", "UnifyBoldFont");
    b->selectorSetBackgroundColors("UnifySettingsSelector", b->hexToColor(0x111111FF), b->hexToColor(0x090909FF), b->hexToColor(0x000000FF));

    b->textInit("UnifySettingsCredits");
    b->textSetColor("UnifySettingsCredits", b->hexToColor(0xFFFFFFFF));
    b->textSetFont("UnifySettingsCredits", "UnifyBoldFont");
    b->textSetText("UnifySettingsCredits", "Credits:\n\nEpitech Project 2020, Arcade\n\nKenan Barbot\nNathan Quentel\nTristan Bouillot");

    b->sliderInit("UnifySettingsAudioSlider");
    b->sliderSetBackgroundColor("UnifySettingsAudioSlider", b->hexToColor(0x101010FF));
    b->sliderSetSliderColor("UnifySettingsAudioSlider", b->hexToColor(0x595959FF));

    b->textInit("UnifySettingsAudioText");
    b->textSetColor("UnifySettingsAudioText", b->hexToColor(0xFFFFFFFF));
    b->textSetFont("UnifySettingsAudioText", "UnifyLightFont");
    b->textSetText("UnifySettingsAudioText", "Audio level");

    b->basicButtonInit("UnifyMenuNextLib");
    b->basicButtonSetBackgroundColors("UnifyMenuNextLib", b->hexToColor(0x505050FF), b->hexToColor(0x505050FF), b->hexToColor(0x505050FF));
    b->basicButtonSetTextColors("UnifyMenuNextLib", b->hexToColor(0x1B79E6FF), b->hexToColor(0xDEDEDEFF), b->hexToColor(0xFFFFFFFF));
    b->basicButtonSetFont("UnifyMenuNextLib", "UnifyBoldFont");
    b->basicButtonSetText("UnifyMenuNextLib", "Next library");

    b->basicButtonInit("UnifyMenuPreviousLib");
    b->basicButtonSetBackgroundColors("UnifyMenuPreviousLib", b->hexToColor(0x505050FF), b->hexToColor(0x505050FF), b->hexToColor(0x505050FF));
    b->basicButtonSetTextColors("UnifyMenuPreviousLib", b->hexToColor(0x1B79E6FF), b->hexToColor(0xDEDEDEFF), b->hexToColor(0xFFFFFFFF));
    b->basicButtonSetFont("UnifyMenuPreviousLib", "UnifyBoldFont");
    b->basicButtonSetText("UnifyMenuPreviousLib", "Previous library");
}

DLLoader<Start> *Menu::update(IBuilder *b, LibraryControl &libCtrl)
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
        drawSettings(b, libCtrl);
    return (tmp);
}

bool Menu::getInterruptType() const
{
    return (_interruptType);
}