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
    (void)name;
    beep();
}

void Audio::stopMusic(const std::string &name)
{
    (void)name;
    beep();
}

void Audio::setVolume(int volume)
{

}

