/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ArcadeCore
*/

#include "core/include/ArcadeCore/ArcadeCore.hpp"
#include "core/include/DLLoader.hpp"

ArcadeCore::ArcadeCore()
{
}

ArcadeCore::~ArcadeCore()
{
}

void ArcadeCore::launchCore(DisplayLibrary *l)
{
    DLLoader<Start> loader("games/lib_arcade_pacman.so");
    Start *game = loader.getInstance();
    Builder b(l);

    if (!game)
        return;
    while (b.windowIsOpen()) {
        b.windowClear();
        b.rectDraw({12, 35, 20, 21}, { 20, 20, 20, 20});
        game->update(&b);
        b.windowDisplay();
    }
}
