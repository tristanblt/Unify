/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** Menu
*/

#ifndef MENU_HPP_
#define MENU_HPP_

#include "core/include/ArcadeCore/IBuilder.hpp"
#include "games/include/Start.hpp"
#include "core/include/DLLoader.hpp"
#include "core/include/ArcadeCore/BasicButton.hpp"
#include "core/include/ArcadeCore/SpriteButton.hpp"
#include "core/include/ArcadeCore/Enums.hpp"
#include <vector>
#include <fstream>

class Menu {
    public:
        Menu();
        ~Menu();

        struct GameCover {
            std::string gameName;
            DLLoader<Start> *gameLib;
            std::string spriteIdx;
        };

        DLLoader<Start> *update(IBuilder *builder);
        void start(IBuilder *builder);
        void drawBackgrounds(IBuilder *builder);
        void drawHeader(IBuilder *builder);
        void drawCarousel(IBuilder *builder);
        void drawSettings(IBuilder *builder);
    protected:
    private:
        std::vector<GameCover> _covers;
        DLLoader<Start> *_currentGame;
        MenuState _state;
        float _coversOffset;
};

#endif /* !MENU_HPP_ */
