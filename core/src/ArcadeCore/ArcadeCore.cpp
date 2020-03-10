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
    Layout layout;
    Builder b(l);
    Menu m;
    bool isMenu = false;

    b.loadAsset("assets/fonts/Montserrat-Light.otf", AssetType::FONT);
    b.loadAsset("assets/fonts/Montserrat-Regular.otf", AssetType::FONT);
    b.loadAsset("assets/fonts/Montserrat-Bold.otf", AssetType::FONT);
    if (!game)
        return;
    game->start(&b);
    while (b.windowIsOpen()) {
        b.updateEvents();
        // std::cout << b._events.mouseEvents.mouseStates[MouseButton::LEFT_CLICK] << std::endl;
        // std::cout << "x:" << b._events.mouseEvents.pos.x << " y:" << b._events.mouseEvents.pos.y << std::endl;
        // std::cout << "TAB:" << b._events.keyboardState[Key::TAB] << std::endl;
        // std::cout << "A:" << b._events.keyboardState[Key::A] << std::endl;
        b.windowClear();
        if (isMenu)
            m.update(&b);
        else {
            game->update(&b);
            layout.update(&b);
        }
        b.windowDisplay();
    }
}
