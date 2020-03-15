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
#include "core/include/ArcadeCore/Enums.hpp"

class ArcadeCore {
    public:

        ArcadeCore();
        ~ArcadeCore();

        bool launchCore(DisplayLibrary *library);
        void loadCoreAssets(Builder &builder);
        Start *changeGame(std::string libName);

        DisplayLibrary *importGraphicalLibs(const std::string &libName);
        void switchGraphicalLibrary(IBuilder *builder);
    protected:
    private:
        CoreState _coreState;
        Menu _menu;
        Layout _layout;
        std::vector<DisplayLibrary *> _libs;
        int _currentLib;
};

#endif /* !ArcadeCore_HPP_ */
