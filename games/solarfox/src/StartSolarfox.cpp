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

}

void StartSolarfox::update(IBuilder *b)
{
    b->textDraw({"souag", {300, 300}, {0, 0, 0, 255}, 100, 0});
}

std::string StartSolarfox::getName() const
{
    return ("Solar Fox");
}