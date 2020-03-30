/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** GameClock
*/

#include "games/include/GameClock.hpp"

GameClock::GameClock():
_start(std::chrono::system_clock::now())
{
}

GameClock::~GameClock()
{
}

void GameClock::restart()
{
    _start = std::chrono::system_clock::now();
}

double GameClock::getElapsedTimeMs() const
{
    std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
    auto elapsed = end - _start;

    return (std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count());
}