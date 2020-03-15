/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** nCursesColors
*/

#ifndef NCURSESCOLORS_HPP_
#define NCURSESCOLORS_HPP_

#include "lib/include/DisplayLibrary.hpp"

namespace nCursesColors
{
    int colorExists(Color);
    int addColor(Color);
    static std::map<int, Color> _knownColors;
};

#endif /* !NCURSESCOLORS_HPP_ */
