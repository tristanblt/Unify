/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** GameClock
*/

#ifndef GAMECLOCK_HPP_
#define GAMECLOCK_HPP_

#include <chrono>

class GameClock {
    public:
        GameClock();
        ~GameClock();

        void restart();
        double getElapsedTimeMs() const;
    private:
        std::chrono::time_point<std::chrono::system_clock> _start;
};

#endif /* !GAMECLOCK_HPP_ */
