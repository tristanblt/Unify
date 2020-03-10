/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ArcadeCore
*/

#ifndef ArcadeCore_HPP_
#define ArcadeCore_HPP_

#include "lib/include/DisplayLibrary.hpp"
#include "lib/include/Graphical/IWindow.hpp"
#include "lib/include/Graphical/IRectangle.hpp"
#include "games/include/Start.hpp"
#include "core/include/ArcadeCore/Builder.hpp"
#include "core/include/ArcadeCore/Menu.hpp"
#include "core/include/ArcadeCore/Layout.hpp"

class ArcadeCore {
    public:
        enum CoreState {
            MENU,
            GAME,
            PAUSE
        };

        ArcadeCore();
        ~ArcadeCore();

        void launchCore(DisplayLibrary *);
        void loadCoreAssets(Builder &b);
    protected:
    private:
        CoreState _coreState;
        Menu _menu;
        Layout _layout;
};

#endif /* !ArcadeCore_HPP_ */
