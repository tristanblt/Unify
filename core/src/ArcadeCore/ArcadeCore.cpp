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

void ArcadeCore::loadCoreAssets(Builder &builder)
{
    builder.loadAsset("assets/fonts/Montserrat-Light.otf", AssetType::FONT);
    builder.loadAsset("assets/fonts/Montserrat-Regular.otf", AssetType::FONT);
    builder.loadAsset("assets/fonts/Montserrat-Bold.otf", AssetType::FONT);
    builder.loadAsset("assets/imgs/gear.png", AssetType::SPRITE);
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
        builder.updateEvents();
        std::cout << "leftClick: " << builder._events.mouseEvents.mouseStates[MouseButton::LEFT_CLICK] << std::endl;
        std::cout << "x:" << builder._events.mouseEvents.pos.x << " y:" << builder._events.mouseEvents.pos.y << std::endl;
        std::cout << "TAB:" << builder._events.keyboardState[Key::TAB] << std::endl;
        std::cout << "A:" << builder._events.keyboardState[Key::A] << std::endl;
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
