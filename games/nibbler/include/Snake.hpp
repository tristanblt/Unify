/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Snake
*/

#ifndef SNAKE_HPP_
#define SNAKE_HPP_

#include "games/nibbler/include/StartNibbler.hpp"

class Snake {
    public:
        Snake();
        ~Snake();

        void update(void);
        void setSpeed(const Vector2 &);
        void setPosition(const Vector2 &);
        bool hasEaten(void);
        bool isDead(void) const;
    private:
        int _scale;
        int _foodCount;
        Vector2 _pos;
        Vector2 _speed;
        std::vector<Vector2> _tail;
};

#endif /* !SNAKE_HPP_ */
