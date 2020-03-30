/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Snake
*/

#include "games/nibbler/include/Snake.hpp"

Snake::Snake():
_scale(0),
_foodCount(0),
_pos({0, 0}),
_speed({1, 0})
{
}

Snake::~Snake()
{
}

void Snake::update(void)
{

}

void Snake::setSpeed(const Vector2 & speed)
{
    _speed.x = speed.x;
    _speed.y = speed.y;
}

void Snake::setPosition(const Vector2 & pos)
{
    _pos.x = pos.x;
    _pos.y = pos.y;
}

bool Snake::isDead(void) const //TMP
{
    return (true);
}

bool Snake::hasEaten(void) //TMP
{
    _foodCount++;
    // _tail.push_back({xx, yy});
    return (false);
}

