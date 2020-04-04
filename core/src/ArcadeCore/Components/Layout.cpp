/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** Layout
*/

#include "core/include/ArcadeCore/Components/Layout.hpp"

Layout::Layout()
{

}

Layout::~Layout()
{
}

void Layout::start(IBuilder *b)
{
    b->spriteButtonInit("UnifyPauseButton");
    b->spriteButtonSetSprite("UnifyPauseButton", "UnifyIcons");

    b->basicButtonInit("UnifyReturnHomeButton");
    b->basicButtonSetBackgroundColors("UnifyReturnHomeButton", b->hexToColor(0x505050FF), b->hexToColor(0x505050FF), b->hexToColor(0x505050FF));
    b->basicButtonSetTextColors("UnifyReturnHomeButton", b->hexToColor(0x1B79E6FF), b->hexToColor(0xDEDEDEFF), b->hexToColor(0xFFFFFFFF));
    b->basicButtonSetFont("UnifyReturnHomeButton", "UnifyBoldFont");
    b->basicButtonSetText("UnifyReturnHomeButton", "Back to home");

    b->basicButtonInit("UnifyReturnGameButton");
    b->basicButtonSetBackgroundColors("UnifyReturnGameButton", b->hexToColor(0x505050FF), b->hexToColor(0x505050FF), b->hexToColor(0x505050FF));
    b->basicButtonSetTextColors("UnifyReturnGameButton", b->hexToColor(0x1B79E6FF), b->hexToColor(0xDEDEDEFF), b->hexToColor(0xFFFFFFFF));
    b->basicButtonSetFont("UnifyReturnGameButton", "UnifyBoldFont");
    b->basicButtonSetText("UnifyReturnGameButton", "Return to game");

    b->rectInit("UnifyLayoutPauseBackground");
    b->rectSetColor("UnifyLayoutPauseBackground", b->hexToColor(0x37373788));

    b->rectInit("UnifyLayoutPauseBanner");
    b->rectSetColor("UnifyLayoutPauseBanner", b->hexToColor(0x373737FF));

    b->textInit("UnifyLayoutPauseText");
    b->textSetFont("UnifyLayoutPauseText", "UnifyBoldFont");
    b->textSetText("UnifyLayoutPauseText", "Pause");
    b->textSetColor("UnifyLayoutPauseText", b->hexToColor(0xFFFFFFFF));

    b->rectInit("UnifyLayoutFooter");
    b->rectSetColor("UnifyLayoutFooter", b->hexToColor(0x373737FF));

    b->textInit("UnifyLayoutFooterName");
    b->textSetFont("UnifyLayoutFooterName", "UnifyBoldFont");
    b->textSetText("UnifyLayoutFooterName", "Unify");
    b->textSetColor("UnifyLayoutFooterName", b->hexToColor(0xFFFFFFFF));

    b->textInit("UnifyLayoutFooterGameName");
    b->textSetFont("UnifyLayoutFooterGameName", "UnifyBoldFont");
    b->textSetColor("UnifyLayoutFooterGameName", b->hexToColor(0xFFFFFF77));

    b->sliderInit("UnifyLayoutAudioSlider");
    b->sliderSetBackgroundColor("UnifyLayoutAudioSlider", b->hexToColor(0x101010FF));
    b->sliderSetSliderColor("UnifyLayoutAudioSlider", b->hexToColor(0x595959FF));

    b->textInit("UnifyLayoutAudioText");
    b->textSetColor("UnifyLayoutAudioText", b->hexToColor(0xFFFFFFFF));
    b->textSetFont("UnifyLayoutAudioText", "UnifyLightFont");
    b->textSetText("UnifyLayoutAudioText", "Audio level");
}

void Layout::update(IBuilder *b, CoreState &coreState, const std::string &name)
{
    static int tmpVolume = b->getVolume();

    if (coreState == CoreState::CORE_PAUSE) {
        b->rectSetPosition("UnifyLayoutPauseBackground", {VW(0), VH(0)});
        b->rectSetSize("UnifyLayoutPauseBackground", {VW(100), VH(100)});
        b->rectDraw("UnifyLayoutPauseBackground");

        b->rectSetPosition("UnifyLayoutPauseBanner", {VW(0), VH(29)});
        b->rectSetSize("UnifyLayoutPauseBanner", {VW(100), VH(33)});
        b->rectDraw("UnifyLayoutPauseBanner");

        b->textSetPosition("UnifyLayoutPauseText", {VW(50) - (5 * VH(2)), VH(31)});
        b->textSetFontSize("UnifyLayoutPauseText", static_cast<int>(VH(6)));
        b->textDraw("UnifyLayoutPauseText");

        b->basicButtonSetDisplayBox("UnifyReturnHomeButton", {VW(37), VH(55), VW(12), VH(5)});
        b->basicButtonSetFontSize("UnifyReturnHomeButton", VH(2));
        b->basicButtonSetRadius("UnifyReturnHomeButton", VH(2.5));
        if (b->buttonDraw("UnifyReturnHomeButton") && b->getEvents().mouseEvents.mouseStates[MouseButton::LEFT_CLICK] == InputState::RELEASED)
            coreState = CoreState::CORE_MENU;
        
        b->basicButtonSetDisplayBox("UnifyReturnGameButton", {VW(51), VH(55), VW(12), VH(5)});
        b->basicButtonSetFontSize("UnifyReturnGameButton", VH(2));
        b->basicButtonSetRadius("UnifyReturnGameButton", VH(2.5));
        if (b->buttonDraw("UnifyReturnGameButton") && b->getEvents().mouseEvents.mouseStates[MouseButton::LEFT_CLICK] == InputState::RELEASED)
            coreState = CoreState::CORE_GAME;

        if (b->getEvents().keyboardState[Key::RIGHT] == InputState::RELEASED && tmpVolume < 100)
            tmpVolume += 5;
        if (b->getEvents().keyboardState[Key::LEFT] == InputState::RELEASED && tmpVolume > 0)
            tmpVolume -= 5;
        b->sliderSetWidth("UnifyLayoutAudioSlider", VW(30));
        b->sliderSetPosition("UnifyLayoutAudioSlider", {VW(35), VH(43)});
        b->sliderDraw("UnifyLayoutAudioSlider", tmpVolume);

        b->textSetFontSize("UnifyLayoutAudioText", VH(2));
        b->textSetPosition("UnifyLayoutAudioText", {VW(35), VH(40)});
        b->textDraw("UnifyLayoutAudioText");
    }
    b->rectSetPosition("UnifyLayoutFooter", {0, VH(100) - VH(7)});
    b->rectSetSize("UnifyLayoutFooter", {VW(100), VH(7)});
    b->rectDraw("UnifyLayoutFooter");

    b->textSetPosition("UnifyLayoutFooterName", {VW(2), VH(94)});
    b->textSetFontSize("UnifyLayoutFooterName", static_cast<int>(VH(4)));
    b->textDraw("UnifyLayoutFooterName");

    b->textSetPosition("UnifyLayoutFooterGameName", {VW(50) - (name.size() * VW(0.5f)), VH(94.6)});
    b->textSetFontSize("UnifyLayoutFooterGameName", static_cast<int>(VH(3)));
    b->textSetText("UnifyLayoutFooterGameName", name);
    b->textDraw("UnifyLayoutFooterGameName");

    b->spriteButtonSetDisplayBox("UnifyPauseButton", {b->windowWidth() * (19.0f / 20.0f),
    ((b->windowHeight() - b->windowHeight() / 16.0f)), (b->windowHeight() / 18.0f), (b->windowHeight() / 18.0f)});
    b->spriteButtonSetSpriteBoxes("UnifyPauseButton", {256, 384, 128, 128}, {0, 384, 128, 128}, {128, 384, 128, 128});

    if (coreState == CoreState::CORE_PAUSE && b->getEvents().joyConEvents.buttons1[JOY_OP] == InputState::RELEASED)
        coreState = CoreState::CORE_GAME;    
    else if ((b->buttonDraw("UnifyPauseButton") &&
    b->getEvents().mouseEvents.mouseStates[MouseButton::LEFT_CLICK] == InputState::RELEASED) ||
    b->getEvents().joyConEvents.buttons1[JOY_OP] == InputState::RELEASED ||
    b->getEvents().keyboardState[Key::P] == InputState::RELEASED)
        coreState = CoreState::CORE_PAUSE;
    if (b->getEvents().joyConEvents.buttons1[JOY_MENU] == InputState::RELEASED ||
    b->getEvents().keyboardState[Key::M] == InputState::RELEASED)
        coreState = CoreState::CORE_MENU;
    b->setVolume(tmpVolume);
}
