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
    b->addButton(new SpriteButton({b->windowWidth() * (19.0f / 20.0f),
    ((b->windowHeight() - b->toUnit(b->windowHeight() / 16.0f))),
    (b->windowHeight() / 18.0f),
    (b->windowHeight() / 18.0f)},
    {256, 384, 128, 128}, {0, 384, 128, 128}, {128, 384, 128, 128}, "UnifyIcons"), "UnifyPause");

    b->addButton(new BasicButton({VW(44), VH(55), VW(12), VH(5)}, VH(2.5), "Back to home",
    b->hexToColor(0x505050FF), b->hexToColor(0x505050FF), b->hexToColor(0x505050FF),
    b->hexToColor(0xDEDEDEFF), b->hexToColor(0xFFFFFFFF), b->hexToColor(0x1B79E6FF),
    VH(2), "UnifyBoldFont"), "UnifyReturnHome");
}

void Layout::update(IBuilder *b, CoreState &coreState, const std::string &name)
{
    if (coreState == CoreState::CORE_PAUSE) {
        b->rectDraw({VW(0), VH(0), VW(100), VH(100)}, b->hexToColor(0x37373788));
        b->rectDraw({VW(0), VH(29), VW(100), VH(33)}, b->hexToColor(0x373737FF));
        b->textDraw({"Pause", {VH(79.5) - (5 * VH(2)), VH(31)}, b->hexToColor(0xFFFFFFFF), static_cast<int>(VH(6)), "UnifyBoldFont"});
        if (b->buttonDraw("UnifyReturnHome") && b->getEvents().mouseEvents.mouseStates[MouseButton::LEFT_CLICK] == InputState::RELEASED)
            coreState = CoreState::CORE_MENU;
    }
    b->rectDraw({0, VH(100) - VH(7), VW(100), VH(7)}, b->hexToColor(0x373737FF));
    b->textDraw({"Unify", {VW(2), VH(94)}, b->hexToColor(0xFFFFFFFF), static_cast<int>(VH(4)), "UnifyBoldFont"});
    b->textDraw({name, {VW(50) - (name.size() * VH(1.3)), VH(94)}, b->hexToColor(0xFFFFFF77), static_cast<int>(VH(4)), "UnifyBoldFont"});
    if (b->buttonDraw("UnifyPause") && b->getEvents().mouseEvents.mouseStates[MouseButton::LEFT_CLICK] == InputState::RELEASED)
        coreState = CoreState::CORE_PAUSE;
}
