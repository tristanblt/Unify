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

void StartPacman::start(IBuilder *b)
{
    (void) b;
}

GameState StartPacman::update(IBuilder *b)
{
    (void) b;
    return (GameState());
}

void StartPacman::finish(IBuilder *b)
{
    (void) b;
}

std::string StartPacman::getName() const
{
    return ("Pacman");
}