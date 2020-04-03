/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** CoreException
*/

#include "core/include/ArcadeCore/CoreException.hpp"

CoreException::CoreException(const std::string &msg):
_message("ArcadeCore error: "+msg)
{

}

FileException::FileException(const std::string &msg):
CoreException("File error: "+msg)
{

}

BuilderException::BuilderException(const std::string &msg):
CoreException("Builder error: "+msg)
{

}

PngLibException::PngLibException(const std::string &msg):
CoreException("PNG error: "+msg)
{

}

DLLoaderException::DLLoaderException(const std::string &msg):
CoreException("Dynamic library loader error: "+msg)
{

}