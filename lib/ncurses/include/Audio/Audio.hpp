/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Audio
*/

#ifndef Audio_HPP_
#define Audio_HPP_

#include "lib/include/Audio/IAudio.hpp"
#include "core/include/ArcadeCore/Builder/IBuilder.hpp"
#include "core/include/ArcadeCore/Utils/Structs.hpp"
#include <ncurses.h>

class Audio : public IAudio {
    public:
        Audio(std::map<std::string, void *> *assets);
        ~Audio();

        void playSound(const std::string &name);
        void playMusic(const std::string &name);
        void stopMusic(const std::string &name);
        void setVolume(int volume);
    protected:
    private:
        std::map<std::string, void *> *_assets;
};

#endif /* !Audio_HPP_ */
