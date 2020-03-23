/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SDL2Exception
*/

#include "lib/sdl2/include/SDL2Exceptions.hpp"

SDL2Exception::SDL2Exception(const std::string &msg):
_message("SDL2 error: "+msg)
{

}

SDL2AssetException::SDL2AssetException(const std::string &msg):
SDL2Exception("asset error: "+msg)
{

}

SDL2BitCrushException::SDL2BitCrushException(const std::string &msg):
SDL2Exception("bitcrush error: "+msg)
{

}