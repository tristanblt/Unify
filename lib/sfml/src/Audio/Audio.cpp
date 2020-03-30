/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Audio
*/

#include "lib/sfml/include/Audio/Audio.hpp"

Audio::Audio(std::map<std::string, void *> *assets)
{
    _assets = assets;
}

Audio::~Audio()
{
}

void Audio::playSound(const std::string &name)
{
    static_cast<sf::Sound *>((*_assets)[name])->play();
}

void Audio::playMusic(const std::string &name)
{
    static_cast<sf::Sound *>((*_assets)[name])->play();
    static_cast<sf::Sound *>((*_assets)[name])->setLoop(true);
}

void Audio::stopMusic(const std::string &name)
{
    static_cast<sf::Sound *>((*_assets)[name])->stop();
}

void Audio::setVolume(int volume)
{
    sf::Listener::setGlobalVolume(volume);
}
