/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Entry
*/

#include "lib/include/Entry.hpp"

extern "C" IDisplayLibrary *entryPoint()
{
    return (new SFMLLibrary());
}