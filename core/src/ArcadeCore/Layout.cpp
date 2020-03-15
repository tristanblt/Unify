/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** Layout
*/

#include "core/include/ArcadeCore/Layout.hpp"

Layout::Layout()
{

}

Layout::~Layout()
{
}

void Layout::start(IBuilder *b)
{
    b->addButton(new SpriteButton({b->windowWidth() * (19.0f / 20.0f), ((b->windowHeight() - b->toUnit(b->windowHeight() / 16.0f))), (b->windowHeight() / 18.0f), (b->windowHeight() / 18.0f)},
    {0, 0, 128, 128}, {256, 0, 128, 128}, {128, 0, 128, 128}, "UnifyIcons"), "UnifyPause");

    b->addButton(new BasicButton({b->windowWidth() / 2 - (b->windowWidth() / 16.0f), b->windowHeight() / 2 + b->windowHeight() / 2.5f / 2 - b->windowHeight() / 20 - (b->windowHeight() / 15.0f), (b->windowWidth() / 8.0f), (b->windowHeight() / 20.0f)}, b->windowWidth() / 120.0f, "Back to home",
    b->hexToColor(0x111111FF), b->hexToColor(0x111111FF), b->hexToColor(0x111111FF),
    b->hexToColor(0xAAAAAAFF), b->hexToColor(0xFFFFFFFF), b->hexToColor(0x3A7BD7FF),
    b->windowHeight() / 40.0f, "UnifyBoldFont"), "UnifyReturnHome");
}

void Layout::update(IBuilder *b, CoreState &coreState, const std::string &name)
{
    b->rectDraw({0, ((VH(100) - b->toUnit(VH(9)))), b->windowWidth(), VH(9)}, b->hexToColor(0x373737FF));
    b->textDraw({"Unify", {VW(2), ((VH(100) - VH(9)))}, b->hexToColor(0xFFFFFFFF), static_cast<int>(VH(4)), "UnifyBoldFont"});
    b->textDraw({name, {(VW(100) - (0.5f * 8 * (VH(4)))) * 0.5f, ((VH(100) - VH(8)))}, b->hexToColor(0xFFFFFF99), static_cast<int>(VH(4)), "UnifyBoldFont"});
    if (b->buttonDraw("UnifyPause") && b->getEvents().mouseEvents.mouseStates[MouseButton::LEFT_CLICK] == InputState::RELEASED)
        coreState = CoreState::CORE_PAUSE;
    if (coreState == CoreState::CORE_PAUSE) {
        b->radiusRectDraw({VH(50) - VW(16), VH(50) - VH(20) - VH(5), VW(33), VH(40)}, 30, b->hexToColor(0x373737FF));
        if (b->buttonDraw("UnifyReturnHome") && b->getEvents().mouseEvents.mouseStates[MouseButton::LEFT_CLICK] == InputState::RELEASED)
            coreState = CoreState::CORE_MENU;
    }
}
