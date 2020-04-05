/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Start
*/

#include "games/centipede/include/StartCentipede.hpp"

StartCentipede::StartCentipede()
{

}

StartCentipede::~StartCentipede()
{
}

void StartCentipede::start(IBuilder *b)
{
    (void) b;
}

GameState StartCentipede::update(IBuilder *b)
{
    (void) b;
    return (GameState());
}

void StartCentipede::finish(IBuilder *b)
{
    (void) b;
}

void StartCentipede::restart(IBuilder *b)
{

}

std::string StartCentipede::getName() const
{
    return ("Centipede");
}