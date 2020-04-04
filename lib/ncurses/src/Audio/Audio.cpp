/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Audio
*/

#include "lib/ncurses/include/Audio/Audio.hpp"

Audio::Audio(std::map<std::string, void *> *assets)
{
    _assets = assets;
}

Audio::~Audio()
{
}

void Audio::playSound(const std::string &name)
{
    (void)name;
    beep();
}

void Audio::playMusic(const std::string &name)
{
<<<<<<< HEAD
    (std::string)name;
=======
    (void)name;
    beep();
>>>>>>> 789a97b56e817749ac673fd040c9521510d3dc29
}

void Audio::stopMusic(const std::string &name)
{
<<<<<<< HEAD
    (std::string)name;
=======
    (void)name;
    beep();
>>>>>>> 789a97b56e817749ac673fd040c9521510d3dc29
}

void Audio::setVolume(int volume)
{
    (void)volume;
}

