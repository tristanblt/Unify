/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** StartNibbler
*/

#ifndef StartNibbler_HPP_
#define StartNibbler_HPP_

#include "games/include/Start.hpp"
#include "games/include/GameClock.hpp"
// #include <chrono>

#define MW(n) (_map.w * n / 100)
#define MH(n) (_map.h * n / 100)
class StartNibbler : public Start {
    public:
        StartNibbler();
        ~StartNibbler();

        void start(IBuilder *builder);
        void update(IBuilder *builder);
        void finish(IBuilder *builder);
        std::string getName() const;

        void updateGame(IBuilder *b);
        void setMap(const Vector2 &, const Vector2 &);
        void setDirection(IBuilder *);
        void setSpeed(const Vector2 &);
        void setPosition(/*const Vector2 &*/);
        void setFoodPosition(void);
        void hasEaten(void);
        void checkDeath(bool isDead = false);
    private:
        Box _map;
        float _scale;
        size_t _foodCount;
        Box _head;
        Box _food;
        Vector2 _speed;
        std::vector<Vector2> _tail;
        GameClock _clock;
};

#endif /* !StartNibbler_HPP_ */
