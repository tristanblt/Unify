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
#include "core/include/ArcadeCore/Builder/Builder.hpp"
#include "core/include/ArcadeCore/Components/Menu.hpp"
#include "core/include/ArcadeCore/Components/Layout.hpp"
#include "core/include/ArcadeCore/Utils/Enums.hpp"

class ArcadeCore {
    public:

        ArcadeCore();
        ~ArcadeCore();

        bool launchCore(DisplayLibrary *library);
        void loadCoreAssets(IBuilder *builder);
        Start *changeGame(std::string libName);

        DisplayLibrary *importGraphicalLibs(const std::string &libName);
        void switchGraphicalLibrary(Builder *builder);
        void joyConCursors(IBuilder *b);
    protected:
    private:
        CoreState _coreState;
        Menu _menu;
        Layout _layout;
        std::vector<DisplayLibrary *> _libs;
        int _currentLib;
};

#endif /* !ArcadeCore_HPP_ */
