/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** IAudio
*/

#ifndef IAUDIO_HPP_
#define IAUDIO_HPP_

#include "lib/include/Graphical/IWindow.hpp"
#include "core/include/ArcadeCore/Utils/Structs.hpp"

class IAudio {
    public:
        virtual ~IAudio() = default;

        virtual void playSound(const std::string &name) = 0;
        virtual void playMusic(const std::string &name) = 0;
        virtual void stopMusic(const std::string &name) = 0;
        virtual void setVolume(int volume) = 0;

    protected:
    private:
};

#endif /* !IAUDIO_HPP_ */
