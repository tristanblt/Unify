/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** nCursesColors
*/

#include "lib/ncurses/include/nCursesColors.hpp"
#include <fstream>

int nCursesColors::colorExists(Color color)
{
    for (auto &elem : _knownColors) {
        if (elem.second.r == color.r &&
            elem.second.g == color.g &&
            elem.second.b == color.b) {
            return (elem.first);
        }
    }
    return (-1);
}

int nCursesColors::addColor(Color color)
{
    int ret = 0;
    static int idx = 32;

    ret = idx;
    _knownColors.insert(std::pair<int, Color>(idx++, color));
    return (ret);
}
