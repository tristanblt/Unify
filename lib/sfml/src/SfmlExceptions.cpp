/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SfmlExceptions
*/

#include "lib/sfml/include/SfmlExceptions.hpp"

SfmlException::SfmlException(const std::string &msg):
_message("Sfml error: "+msg)
{

}

SfmlAssetException::SfmlAssetException(const std::string &msg):
SfmlException("asset error: "+msg)
{

}

SfmlBitCrushException::SfmlBitCrushException(const std::string &msg):
SfmlException("bitcrush error: "+msg)
{

}