/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Start
*/

#include "games/unify_showcase/include/StartUnifyShowcase.hpp"

StartUnifyShowcase::StartUnifyShowcase()
{
}

StartUnifyShowcase::~StartUnifyShowcase()
{
}

void StartUnifyShowcase::start(IBuilder *b)
{
    b->addButton(new BasicButton({VW(44), VH(55), VW(12), VH(5)}, VH(2.5), "Next scene",
    b->hexToColor(0x505050FF), b->hexToColor(0x505050FF), b->hexToColor(0x505050FF),
    b->hexToColor(0xDEDEDEFF), b->hexToColor(0xFFFFFFFF), b->hexToColor(0x1B79E6FF),
    VH(2), "UnifyBoldFont"), "UnifyNextScene");
}

void StartUnifyShowcase::update(IBuilder *b)
{
    b->rectDraw({0, 0, VW(100), VH(100)}, b->hexToColor(0x111111FF));
    b->buttonDraw("UnifyNextScene");
}

std::string StartUnifyShowcase::getName() const
{
    return ("Unify Showcase");
}