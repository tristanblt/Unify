/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Bitcrush
*/

#ifndef BITCRUSH_HPP_
#define BITCRUSH_HPP_

#include "core/include/ArcadeCore/PngFile.hpp"
#include "core/include/ArcadeCore/Structs.hpp"
#include "lib/ncurses/include/Graphical/Window.hpp"
#include <ncurses.h>
#include <vector>
#include <iostream>

class Bitcrush {
    public:
        Bitcrush(PngFile *png, Vector2 pos, Box frame, Vector2 wantedSize, IWindow *w);
        ~Bitcrush();

    protected:
    private:
};

#endif /* !BITCRUSH_HPP_ */
