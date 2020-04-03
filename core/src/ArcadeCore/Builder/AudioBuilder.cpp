/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** AudioBuilder
*/

#include "core/include/ArcadeCore/Builder/Builder.hpp"

/* ---------------------------------- audio --------------------------------- */

void Builder::playSound(const std::string &name)
{
    _library->_audio->playSound(name);
}

void Builder::playMusic(const std::string &name)
{
    if (std::find(_musicsPlaying.begin(), _musicsPlaying.end(), name) == _musicsPlaying.end()) {
        _musicsPlaying.push_back(name);
        _library->_audio->playMusic(name);
    }
}

void Builder::stopMusic(const std::string &name)
{
    _musicsPlaying.erase(std::remove(_musicsPlaying.begin(), _musicsPlaying.end(), name), _musicsPlaying.end());
    _library->_audio->stopMusic(name);
}

void Builder::setVolume(int volume)
{
    _library->_audio->setVolume(volume);
    _volume = volume;
}

int Builder::getVolume() const
{
    return (_volume);
}