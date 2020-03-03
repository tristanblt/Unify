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

void ArcadeMenu::launchMenu(IDisplayLibrary *lib)
{
    IWindow *w = lib->newWindow();
    IRectangle *r = lib->newRectangle();

    while (w->isOpen()) {
        w->clear();
        r->draw(w);
        w->display();
    }
}