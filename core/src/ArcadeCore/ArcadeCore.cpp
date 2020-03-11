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

void ArcadeCore::launchCore(DisplayLibrary *library)
{
    DLLoader<Start> loader("games/lib_arcade_pacman.so");
    Start *game = loader.getInstance();
    Layout layout;
    Builder b(library);
    Menu m;
    bool isMenu = false;

    b.loadAsset("assets/fonts/Montserrat-Light.otf", AssetType::FONT);
    b.loadAsset("assets/fonts/Montserrat-Regular.otf", AssetType::FONT);
    b.loadAsset("assets/fonts/Montserrat-Bold.otf", AssetType::FONT);
    b.loadAsset("assets/imgs/gear.png", AssetType::SPRITE);
    if (!game)
        return;
    game->start(&b);
    unsigned char cpt = 0;
    while (b.windowIsOpen()) {
        b.windowClear();
        // b.rectDraw((Box){1, 5, 10, 4}, (Color){255, 255, 0, 255});
        b.circleDraw((CircleModel){30, 15, 20}, (Color){100, 100, 100, 255});
        // if (isMenu)
        //     m.update(&b);
        // else {
        //     game->update(&b);
        //     layout.update(&b);
        // }
        b.windowDisplay();
    }
}
