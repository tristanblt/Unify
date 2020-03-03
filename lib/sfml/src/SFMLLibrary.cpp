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

Window *SFMLLibrary::newWindow()
{
    return (new Window());
}