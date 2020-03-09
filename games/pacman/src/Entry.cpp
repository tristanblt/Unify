/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Entry
*/

#include "games/pacman/include/StartPacman.hpp"

extern "C" Start *entryPoint()
{
    return (new StartPacman());
}

