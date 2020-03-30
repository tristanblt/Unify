/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Audio
*/

#include "lib/sdl2/include/Audio/Audio.hpp"

Audio::Audio(std::map<std::string, void *> *assets)
{
    _assets = assets;
}

Audio::~Audio()
{
}

void Audio::playSound(const std::string &name)
{
    Mix_PlayChannel(-1, static_cast<Mix_Chunk *>((*_assets)[name]), 0);
}

void Audio::playMusic(const std::string &name)
{
    Mix_PlayChannel(-1, static_cast<Mix_Chunk *>((*_assets)[name]), 1);
}

void Audio::stopMusic(const std::string &name)
{
    Mix_Pause(-1);
}

void Audio::setVolume(int volume)
{
    Mix_Volume(-1, volume);
}
