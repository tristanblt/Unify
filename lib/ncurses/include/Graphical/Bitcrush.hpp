/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Bitcrush
*/

#ifndef BITCRUSH_HPP_
#define BITCRUSH_HPP_

#include "lib/ncurses/include/Graphical/Window.hpp"
#include "lib/ncurses/include/PngFile.hpp"
#include "core/include/ArcadeCore/Utils/Structs.hpp"
#include <ncurses.h>
#include <vector>
#include <map>
#include <iostream>
#include <cmath>

class Bitcrush {
    public:
        Bitcrush();
        ~Bitcrush();

        void drawSprite(PngFile *png, Vector2 pos, Box frame, Vector2 wantedSize, IWindow *w);
        std::vector<std::vector<Color> > bitcrushPng(PngFile *png, Box frame, Vector2 wantedSize);
        Color clusterCrush(PngFile *png, Box frame);
    protected:
    private:
        std::map<PngFile *, std::map<Box, std::map<Vector2, std::vector<std::vector<Color> > > > > _crushed;
};

#endif /* !BITCRUSH_HPP_ */
