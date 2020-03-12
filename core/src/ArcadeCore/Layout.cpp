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

void Layout::update(IBuilder *b, CoreState &coreState, const std::string &name)
{
    b->rectDraw(
        {
            0,
            ((b->windowHeight() - b->toUnit(b->windowHeight() / 14.0f))),
            b->windowWidth(),
            b->toUnit(b->windowHeight() / 14.0f)
        },
        b->hexToColor(0x373737FF)
    );
    b->textDraw(
        {
            "Unify",
            {
                b->windowWidth()/60,
                ((b->windowHeight() - b->toUnit(b->windowHeight() / 16.0f)))
            },
            b->hexToColor(0xFFFFFFFF),
            static_cast<int>(b->windowHeight() / 25.0f),
            2
        }
    );
    b->textDraw(
        {
            name,
            {
                (b->windowWidth() - (0.5f * /**/8/**/ * (b->windowHeight() / 25.0f))) * 0.5f,
                ((b->windowHeight() - b->toUnit(b->windowHeight() / 16.0f)))
            },
            b->hexToColor(0xFFFFFF99),
            static_cast<int>(b->windowHeight() / 25.0f),
            2
        }
    );
    if (b->spriteButtonDraw(
{        {
            b->windowWidth() * (19.0f / 20.0f), ((b->windowHeight() - b->toUnit(b->windowHeight() / 16.0f))),
            (b->windowHeight() / 18.0f), (b->windowHeight() / 18.0f)
        },
        {{b->windowWidth() * (19.0f / 20.0f), ((b->windowHeight() - b->toUnit(b->windowHeight() / 16.0f))), (b->windowHeight() / 18.0f), (b->windowHeight() / 18.0f)}, 12, 255},
        {{b->windowWidth() * (19.0f / 20.0f), ((b->windowHeight() - b->toUnit(b->windowHeight() / 16.0f))), (b->windowHeight() / 18.0f), (b->windowHeight() / 18.0f)}, 10, 255},
        {{b->windowWidth() * (19.0f / 20.0f), ((b->windowHeight() - b->toUnit(b->windowHeight() / 16.0f))), (b->windowHeight() / 18.0f), (b->windowHeight() / 18.0f)}, 11, 255},
        {"", {0, 0}, b->hexToColor(0xFFFFFFFF), 0, 0},
        {"", {0, 0}, b->hexToColor(0xFFFFFFFF), 0, 0},
        {"", {0, 0}, b->hexToColor(0xFFFFFFFF), 0, 0},
        false}
        ) && b->getEvents().mouseEvents.mouseStates[MouseButton::LEFT_CLICK] == InputState::RELEASED)
        coreState = CoreState::CORE_PAUSE;
    if (coreState == CoreState::CORE_PAUSE) {
        b->radiusRectDraw(
            {
                b->windowWidth() / 2 - b->windowWidth() / 3 / 2,
                b->windowHeight() / 2 - b->windowHeight() / 2.5f / 2 - b->windowHeight() / 20,
                b->windowWidth() / 3,
                b->windowHeight() / 2.5f
            },
            30,
            b->hexToColor(0x373737FF)
        );
        if (b->basicButtonDraw({
                {
                    b->windowWidth() / 2 - (b->windowWidth() / 16.0f), b->windowHeight() / 2 + b->windowHeight() / 2.5f / 2 - b->windowHeight() / 20 - (b->windowHeight() / 15.0f),
                    (b->windowWidth() / 8.0f), (b->windowHeight() / 20.0f)
                },
                static_cast<int>(b->windowWidth() / 120.0f),
                b->hexToColor(0x111111FF),
                b->hexToColor(0x111111FF),
                b->hexToColor(0x111111FF),
                {"Back to home", {b->windowWidth() / 2 - (b->windowWidth() / 18.5f), b->windowHeight() / 2 + b->windowHeight() / 2.5f / 2 - b->windowHeight() / 20 - (b->windowHeight() / 17.0f)}, b->hexToColor(0xAAAAAAFF), static_cast<int>(b->windowHeight() / 40.0f), 2},
                {"Back to home", {b->windowWidth() / 2 - (b->windowWidth() / 18.5f), b->windowHeight() / 2 + b->windowHeight() / 2.5f / 2 - b->windowHeight() / 20 - (b->windowHeight() / 17.0f)}, b->hexToColor(0xFFFFFFFF), static_cast<int>(b->windowHeight() / 40.0f), 2},
                {"Back to home", {b->windowWidth() / 2 - (b->windowWidth() / 18.5f), b->windowHeight() / 2 + b->windowHeight() / 2.5f / 2 - b->windowHeight() / 20 - (b->windowHeight() / 17.0f)}, b->hexToColor(0x3A7BD7FF), static_cast<int>(b->windowHeight() / 40.0f), 2},
                false}
            ) && b->getEvents().mouseEvents.mouseStates[MouseButton::LEFT_CLICK] == InputState::RELEASED)
                coreState = CoreState::CORE_MENU;
    }
}
