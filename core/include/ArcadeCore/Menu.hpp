/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** Menu
*/

#ifndef MENU_HPP_
#define MENU_HPP_

#include "core/include/ArcadeCore/IBuilder.hpp"
#include <vector>
#include <fstream>

class Menu {
    public:
        Menu();
        ~Menu();

        struct GameCover {
            std::string gameName;
            std::string libPath;
            int spriteIdx;
        };

        void update(IBuilder *);
        void start(IBuilder *);
        void drawBackgrounds(IBuilder *);
        void drawHeader(IBuilder *);
        void drawCarousel(IBuilder *);
    protected:
    private:
        std::vector<GameCover> _covers;
        float _coversOffset;
};

#endif /* !MENU_HPP_ */
