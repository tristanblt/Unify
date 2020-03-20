/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Start
*/

#include "games/nibbler/include/StartNibbler.hpp"

StartNibbler::StartNibbler()
{
}

StartNibbler::~StartNibbler()
{
}

void StartNibbler::start(IBuilder *b)
{
    (void)b;
}

void StartNibbler::update(IBuilder *b)
{
    //b->textDraw({"saiske", {300, 300}, {0, 0, 0, 255}, 100, "UnifyLightFont"});
}

std::string StartNibbler::getName() const
{
    return ("Nibbler");
}