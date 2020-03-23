/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** CoreException
*/

#include "core/include/ArcadeCore/CoreException.hpp"

CoreException::CoreException(const std::string &msg):
_message("Arcade Core error: "+msg)
{

}

FileException::FileException(const std::string &msg):
CoreException("file error: "+msg)
{

}

BuilderException::BuilderException(const std::string &msg):
CoreException("builder error: "+msg)
{

}

PngLibException::PngLibException(const std::string &msg):
CoreException("png error: "+msg)
{

}
