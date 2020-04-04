/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ArcadeCore
*/

#ifndef ArcadeCore_HPP_
#define ArcadeCore_HPP_

#include "lib/include/ADisplayLibrary.hpp"
#include "lib/include/Graphical/IWindow.hpp"
#include "lib/include/Graphical/IRectangle.hpp"
#include "games/include/Start.hpp"
#include "core/include/ArcadeCore/Builder/Builder.hpp"
#include "core/include/ArcadeCore/Components/Menu.hpp"
#include "core/include/ArcadeCore/Components/Score.hpp"
#include "core/include/ArcadeCore/Components/Layout.hpp"
#include "core/include/ArcadeCore/Utils/Enums.hpp"

class ArcadeCore {
    public:

        ArcadeCore();
        ~ArcadeCore();

        bool launchCore(ADisplayLibrary *library);
        void startLaunchCore(Builder *builder);
        void loadCoreAssets(IBuilder *builder);
        Start *changeGame(std::string libName);

        ADisplayLibrary *importGraphicalLibs(const std::string &libName);
        void switchGraphicalLibrary(Builder *builder, int i, Start *&game);
        void triggerSwitchGraphicalLibrary(Builder *builder, Start *&game);
        void updateJoyConCursors(IBuilder *b);
        void manageMenuAndGame(Builder *b, DLLoader<Start> *&gameLib, Start *&game);
    protected:
    private:
        ScoreManager _sm;
        CoreState _coreState;
        Menu _menu;
        Layout _layout;
        Score _score;
        GameState _gameState;
        std::vector<ADisplayLibrary *> _libs;
        int _currentLib;
};

#endif /* !ArcadeCore_HPP_ */
