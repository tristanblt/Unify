/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Start
*/

#include "games/qix/include/StartQix.hpp"

StartQix::StartQix()
{

}

StartQix::~StartQix()
{
}

void StartQix::start(IBuilder *b)
{
    (void) b;
}

void StartQix::restart(IBuilder *b)
{
    
}

GameState StartQix::update(IBuilder *b)
{
    (void) b;
    return (GameState());
}

void StartQix::finish(IBuilder *b)
{
    (void) b;
}

std::string StartQix::getName() const
{
    return ("Qix");
}