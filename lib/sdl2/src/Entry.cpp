/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Entry
*/

#include "lib/sdl2/include/SDL2Library.hpp"
#include "lib/include/Entry.hpp"
#include <iostream>

extern "C" DisplayLibrary *entryPoint()
{
    return (new SDL2Library());
}