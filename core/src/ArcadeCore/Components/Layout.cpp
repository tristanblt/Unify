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
    /*b->addSpriteButton({b->windowWidth() * (19.0f / 20.0f),
    ((b->windowHeight() - b->windowHeight() / 16.0f)),
    (b->windowHeight() / 18.0f),
    (b->windowHeight() / 18.0f)},
    {256, 384, 128, 128}, {0, 384, 128, 128}, {128, 384, 128, 128}, "UnifyIcons", "UnifyPause");

    b->addBasicButton({VW(44), VH(55), VW(12), VH(5)}, VH(2.5),
    b->hexToColor(0x505050FF), b->hexToColor(0x505050FF), b->hexToColor(0x505050FF),
    b->hexToColor(0xDEDEDEFF), b->hexToColor(0xFFFFFFFF), b->hexToColor(0x1B79E6FF),
    "Back to home", VH(2), "UnifyBoldFont", "UnifyReturnHome");*/
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
}

void Layout::update(IBuilder *b, CoreState &coreState, const std::string &name)
{
    if (coreState == CoreState::CORE_PAUSE) {
        b->rectSetPotition("UnifyLayoutPauseBackground", {VW(0), VH(0)});
        b->rectSetSize("UnifyLayoutPauseBackground", {VW(100), VH(100)});
        b->rectDraw("UnifyLayoutPauseBackground");

        b->rectSetPotition("UnifyLayoutPauseBanner", {VW(0), VH(29)});
        b->rectSetSize("UnifyLayoutPauseBanner", {VW(100), VH(33)});
        b->rectDraw("UnifyLayoutPauseBanner");

        b->textSetPotition("UnifyLayoutPauseText", {VH(79.5) - (5 * VH(2)), VH(31)});
        b->textSetFontSize("UnifyLayoutPauseText", static_cast<int>(VH(6)));
        b->textDraw("UnifyLayoutPauseText");

        //if (b->buttonDraw("UnifyReturnHome") && b->getEvents().mouseEvents.mouseStates[MouseButton::LEFT_CLICK] == InputState::RELEASED)
        //    coreState = CoreState::CORE_MENU;
    }
    b->rectSetPotition("UnifyLayoutFooter", {0, VH(100) - VH(7)});
    b->rectSetSize("UnifyLayoutFooter", {VW(100), VH(7)});
    b->rectDraw("UnifyLayoutFooter");

    b->textSetPotition("UnifyLayoutFooterName", {VW(2), VH(94)});
    b->textSetFontSize("UnifyLayoutFooterName", static_cast<int>(VH(4)));
    b->textDraw("UnifyLayoutFooterName");

    b->textSetPotition("UnifyLayoutFooterGameName", {VW(50) - (name.size() * VH(1.3)), VH(94.6)});
    b->textSetFontSize("UnifyLayoutFooterGameName", static_cast<int>(VH(3)));
    b->textSetText("UnifyLayoutFooterGameName", name);
    b->textDraw("UnifyLayoutFooterGameName");
    /*if (coreState == CoreState::CORE_PAUSE && b->getEvents().joyConEvents.buttons1[JOY_OP] == InputState::RELEASED)
        coreState = CoreState::CORE_GAME;    
    else if ((b->buttonDraw("UnifyPause") && b->getEvents().mouseEvents.mouseStates[MouseButton::LEFT_CLICK] == InputState::RELEASED) ||
    b->getEvents().joyConEvents.buttons1[JOY_OP] == InputState::RELEASED)
        coreState = CoreState::CORE_PAUSE;
    if (b->getEvents().joyConEvents.buttons1[JOY_MENU] == InputState::RELEASED)
        coreState = CoreState::CORE_MENU;*/
}
