/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Snake
*/

#ifndef SNAKE_HPP_
#define SNAKE_HPP_

#include "games/include/Start.hpp"
#include "games/include/GameClock.hpp"
// #include "games/nibbler/include/StartNibbler.hpp"

#define mapw(n) (_map.w * n / 100)
#define maph(n) (_map.h * n / 100)

class Snake {
    public:
        Snake();
        Snake(float, Box);
        ~Snake();

        GameState update(IBuilder *);
        void restart(IBuilder *);
        int getScore(void) const;

    private:

        void setDirection(IBuilder *);
        void setSpeed(const Vector2 &);
        void setPosition();
        void setFoodPosition(void);
        void hasEaten(IBuilder *);
        void checkDeath(IBuilder *);
        void drawSnake(IBuilder *);
        void drawBody (IBuilder *, Vector2, Vector2, Vector2);

        Box _map;
        float _scale;
        size_t _foodCount;
        Box _head;
        Box _food;
        bool _bonus;
        bool _hasBonus;
        float _im;
        Vector2 _speed;
        std::vector<Vector2> _tail;
        GameClock _clock;
        GameClock _bonusClock;
        GameState _gameState;
};

#endif /* !SNAKE_HPP_ */
