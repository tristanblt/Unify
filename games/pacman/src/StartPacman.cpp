/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Start
*/

#include "games/pacman/include/StartPacman.hpp"

StartPacman::StartPacman()
{
}

StartPacman::~StartPacman()
{
}

void StartPacman::start(IBuilder *b)
{
    b->loadAsset("assets/fonts/Montserrat-Regular.otf", AssetType::FONT);
    b->loadAsset("assets/fonts/Montserrat-Light.otf", AssetType::FONT);
    b->loadAsset("assets/fonts/Montserrat-Bold.otf", AssetType::FONT);
}

void StartPacman::update(IBuilder *b)
{
    b->rectDraw({45, 65, 500, 30}, {1, 1, 1, 1});
    b->textDraw({"souag", {300, 300}, 100, 0}, {255, 255, 255, 255});
}
