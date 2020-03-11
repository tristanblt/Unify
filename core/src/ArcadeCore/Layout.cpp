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
            static_cast<int>(b->windowHeight() / 25.0f),
            2
        },
        b->hexToColor(0xFFFFFFFF)
    );
    b->textDraw(
        {
            name,
            {
                (b->windowWidth() - (0.5f * /**/8/**/ * (b->windowHeight() / 25.0f))) * 0.5f,
                ((b->windowHeight() - b->toUnit(b->windowHeight() / 16.0f)))
            },
            static_cast<int>(b->windowHeight() / 25.0f),
            2
        },
        b->hexToColor(0xFFFFFF99)
    );
    if (b->buttonDraw(
        {
            b->windowWidth() * (19.0f / 20.0f),
            ((b->windowHeight() - b->toUnit(b->windowHeight() / 16.0f))),
            (b->windowHeight() / 18.0f),
            (b->windowHeight() / 18.0f)
        },
        ((b->windowHeight() / 18.0f) / 2.0f),
        b->hexToColor(0xFFFFFFFF),
        "",
        2
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
        if (b->buttonDraw(
                {
                    b->windowWidth() / 2 - (b->windowWidth() / 16.0f),
                    b->windowHeight() / 2 + b->windowHeight() / 2.5f / 2 - b->windowHeight() / 20 - (b->windowHeight() / 15.0f),
                    (b->windowWidth() / 8.0f),
                    (b->windowHeight() / 20.0f)
                },
                (b->windowWidth() / 120.0f),
                b->hexToColor(0x111111FF),
                "Back to home",
                2
            ) && b->getEvents().mouseEvents.mouseStates[MouseButton::LEFT_CLICK] == InputState::RELEASED)
                coreState = CoreState::CORE_MENU;
    }
}
