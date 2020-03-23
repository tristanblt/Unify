/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** NCursesException
*/

#include "lib/ncurses/include/NCursesException.hpp"

NCursesException::NCursesException(const std::string &msg):
_message("nCurses error: "+msg)
{

}

NCursesAssetException::NCursesAssetException(const std::string &msg):
NCursesException("asset error: "+msg)
{

}

NCursesBitCrushException::NCursesBitCrushException(const std::string &msg):
NCursesException("bitcrush error: "+msg)
{

}