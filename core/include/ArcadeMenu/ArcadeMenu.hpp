/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ArcadeMenu
*/

#ifndef ARCADEMENU_HPP_
#define ARCADEMENU_HPP_

#include "lib/include/DisplayLibrary.hpp"
#include "lib/include/Graphical/IWindow.hpp"
#include "lib/include/Graphical/IRectangle.hpp"

class ArcadeMenu {
    public:
        ArcadeMenu();
        ~ArcadeMenu();

        void launchMenu(DisplayLibrary *);
    protected:
    private:
};

#endif /* !ARCADEMENU_HPP_ */
