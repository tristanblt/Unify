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
    {256, 386, 128, 128}, {0, 386, 128, 128}, {128, 386, 128, 128}, "UnifyIcons"), "UnifyPause");

    b->addButton(new BasicButton({VW(44), VH(50), VW(12), VH(5)}, VH(2.5), "Back to home",
    b->hexToColor(0x505050FF), b->hexToColor(0x505050FF), b->hexToColor(0x505050FF),
    b->hexToColor(0xDEDEDEFF), b->hexToColor(0xFFFFFFFF), b->hexToColor(0x1B79E6FF),
    VH(2), "UnifyBoldFont"), "UnifyReturnHome");
}

void Layout::update(IBuilder *b, CoreState &coreState, const std::string &name)
{
    b->rectDraw({0, VH(91), VW(100), VH(9)}, b->hexToColor(0x373737FF));
    b->textDraw({"Unify", {VW(2), VH(93)}, b->hexToColor(0xFFFFFFFF), static_cast<int>(VH(4)), "UnifyBoldFont"});
    b->textDraw({name, {VW(50) / 2.0f - name.size() / 2.0f, VH(92.75)}, b->hexToColor(0xFFFFFF99), static_cast<int>(VH(6)), "UnifyBoldFont"});
    if (b->buttonDraw("UnifyPause") && b->getEvents().mouseEvents.mouseStates[MouseButton::LEFT_CLICK] == InputState::RELEASED)
        coreState = CoreState::CORE_PAUSE;
    if (coreState == CoreState::CORE_PAUSE) {
        b->rectDraw({VW(0), VH(0), VW(100), VH(91)}, b->hexToColor(0x37373788));
        b->rectDraw({VW(0), VH(29), VW(100), VH(33)}, b->hexToColor(0x373737FF));
        b->textDraw({"Pause", {VH(79.5), VH(31)}, b->hexToColor(0xFFFFFFFF), static_cast<int>(VH(6)), "UnifyBoldFont"});
        if (b->buttonDraw("UnifyReturnHome") && b->getEvents().mouseEvents.mouseStates[MouseButton::LEFT_CLICK] == InputState::RELEASED)
            coreState = CoreState::CORE_MENU;
    }
}
