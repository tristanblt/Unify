/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Start
*/

#include "games/pacman/include/StartPacman.hpp"

StartPacman::StartPacman()
{
}

StartPacman::~StartPacman()
{
}

void StartPacman::update(DisplayLibrary *l)
{
    l->_rect->setPosition(500);
    l->_rect->draw(l->_window);
}
