/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Start
*/

#include "games/solarfox/include/StartSolarfox.hpp"

StartSolarfox::StartSolarfox()
{
}

StartSolarfox::~StartSolarfox()
{
}

void StartSolarfox::start(IBuilder *b)
{
    (void)b;
}

void StartSolarfox::update(IBuilder *b)
{
    //b->textDraw({"souag", {300, 300}, {0, 0, 0, 255}, 100, "UnifyLightFont"});
}

std::string StartSolarfox::getName() const
{
    return ("Solar Fox");
}