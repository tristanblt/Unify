/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ArcadeMenu
*/

#include "core/include/ArcadeMenu/ArcadeMenu.hpp"

ArcadeMenu::ArcadeMenu()
{
}

ArcadeMenu::~ArcadeMenu()
{
}

void ArcadeMenu::launchMenu(DisplayLibrary *l)
{
    while (l->_window->isOpen()) {
        l->_rect->setSize(100);
        l->_window->clear();
        l->_rect->draw(l->_window);
        l->_window->display();
    }
}
