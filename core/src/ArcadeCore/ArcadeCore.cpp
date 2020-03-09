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
    Layout footer(l);
    Builder b(l);

    if (!game)
        return;
    while (b.windowIsOpen()) {
        b.windowClear();
        b.rectDraw({12, 35, 20, 21}, {200, 200, 200, 200});
        b.radiusRectDraw({300, 300, 100, 100}, 10, (Color){200, 200, 200, 255});
        b.circleDraw({100.0f, 100.0f, 20.0f}, {200, 200, 200, 200});
        game->update(&b);
        footer.update(&b);
        b.windowDisplay();
    }
}
