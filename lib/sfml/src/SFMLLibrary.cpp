/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SFMLLibrary
*/

#include "../include/SFMLLibrary.hpp"

SFMLLibrary::SFMLLibrary()
{

}

SFMLLibrary::~SFMLLibrary()
{
}

IWindow *SFMLLibrary::newWindow()
{
    return (new Window());
}

IRectangle *SFMLLibrary::newRectangle()
{
    return (new Rectangle());
}