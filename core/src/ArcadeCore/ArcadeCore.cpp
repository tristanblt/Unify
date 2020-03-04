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

    while (l->_window->isOpen()) {
        l->_window->clear();
        l->_rect->setPosition(0);
        l->_rect->setSize(100);
        l->_rect->draw(l->_window);
        game->update(l);
        l->_window->display();
    }
}
