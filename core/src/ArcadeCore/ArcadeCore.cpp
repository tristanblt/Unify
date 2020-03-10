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
    _coreState = CoreState::MENU;
}

ArcadeCore::~ArcadeCore()
{
}

void ArcadeCore::loadCoreAssets(Builder &b)
{
    b.loadAsset("assets/fonts/Montserrat-Light.otf", AssetType::FONT);
    b.loadAsset("assets/fonts/Montserrat-Regular.otf", AssetType::FONT);
    b.loadAsset("assets/fonts/Montserrat-Bold.otf", AssetType::FONT);
    b.loadAsset("assets/imgs/gear.png", AssetType::SPRITE);
}

void ArcadeCore::launchCore(DisplayLibrary *library)
{
    DLLoader<Start> loader("games/lib_arcade_pacman.so");
    Start *game = loader.getInstance();
    Builder builder(library);

    if (!game)
        return;
    loadCoreAssets(builder);
    game->start(&builder);
    _menu.start(&builder);
    while (builder.windowIsOpen()) {
        builder.windowClear();
        if (_coreState == CoreState::MENU)
            _menu.update(&builder);
        else {
            game->update(&builder);
            _layout.update(&builder);
        }
        builder.windowDisplay();
    }
}
